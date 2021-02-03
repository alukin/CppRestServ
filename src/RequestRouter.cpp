/*
 * This program is free software; you can redistribute it and/or
 * modify it under the terms of the GNU General Public License
 * as published by the Free Software Foundation, version 2
 * of the License.
 *
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 * Copyright (c) Oleksiy Lukin <alukin@gmail.com>
 */


#define USE_BOOST_REGEX
//GCC 4.8.x has completely broken regex implementation
#ifdef USE_BOOST_REGEX
#include <boost/regex.hpp>
#else
#include <regex>
#endif

#include <sstream>
#include "rest/RequestRouter.h"
#include "rest/ResourceFactory.h"
#include "rest/SecurityProviderBase.h"

namespace sp {
    namespace rest {

        using namespace std;
#ifdef USE_BOOST_REGEX
        using namespace boost;
#endif        

        RequestRouter::RequestRouter() {
        }

        void RequestRouter::setRestPath(std::string path) {
            if (rest_path.substr(0, 1) != "/") {
                rest_path = "/" + path;
            } else {
                rest_path = path;
            }
        }

        void RequestRouter::setStaticPath(std::string path) {
            if (path.substr(0, 1) != "/") {
                static_path = "/" + path;
            } else {
                static_path = path;
            }
        }

        void RequestRouter::setStaticRootDir(std::string path) {
            static_serv.setWebRoot(path);
        }

        RequestRouter::~RequestRouter() {
            resource_map.clear();
        }

        void RequestRouter::registerService(std::string name, CreateResourceFn pfnCreate) {
            m_factory.registerResource(name, pfnCreate);
            ResourcePtr r = m_factory.createResource(name);
            resource_map[name] = r;
        }

        void RequestRouter::unRegisterService(std::string name) {
            m_factory.unRegisterResource(name);
            resource_map.erase(name);
        }

        void RequestRouter::route(web::http::http_request& message, const web::http::method& method) {
            string relative_uri = message.relative_uri().path();
            //check access
            if (!m_security_provider.authenticate_request(message)) {
                message.reply(web::http::status_codes::Unauthorized, "Access denied\n");
                return;
            }
            //match resource
            ResourcePtr match_rp(nullptr);
            string prefix = "";
            for (const auto& rme : resource_map) {
                prefix = rest_path + "/" + rme.first;
                if (relative_uri.substr(0, prefix.length()) == prefix) {
                    match_rp = rme.second;
                    break;
                }
            };
            int rest_res = false;
            if (match_rp.get() != nullptr) {
                rest_res = processCall(match_rp, relative_uri.substr(prefix.length(), relative_uri.length()), message, method);
                if (!rest_res) {
                    defaultReply(message);
                }
                return;
            }
            string sp = relative_uri.substr(0, static_path.length());
            if (method == web::http::methods::GET && sp == static_path) {
                // we have no path mateches for REST, try static                
                string dpr = relative_uri.substr(sp.length(), relative_uri.length());
                if (dpr.substr(0, 1) != "/") {
                    dpr = "/" + dpr;
                }
                static_serv.serve(message, dpr);
            } else {
                defaultReply(message);
            }
        }

        void RequestRouter::defaultReply(web::http::http_request message) {
            std::string rep = U("REST route is not configured for the path\n");
            message.reply(web::http::status_codes::NotFound, rep);
        }

        RbrePtr RequestRouter::getBRE(const std::string& bs) {
            RbrePtr res(new Rbre());
            regex re("(/)(\\{)(\\w+)(\\})");
            regex rr("(/\\w+)?(/\\{\\w+\\})?(/\\w+)?(/\\{\\w+\\})?(/\\w+)?(/\\w+)?(/\\{\\w+\\})?");
            string out = bs;
            smatch m;
            if (regex_match(bs, m, rr)) {
                for (size_t i = 0; i < m.size(); ++i) {
                    string vs = m[i].str();
                    if (i > 0 && vs.length() > 2 && vs.substr(0, 2) == "/{") {
                        res->pnames.push_back(vs.substr(2, vs.length() - 3));
                    }
                }
            }
#ifdef USE_BOOST_REGEX
            out = regex_replace(out, re, "(/)(\\\\w+)");
#else
            out = regex_replace(out, re, "(/)(\\w+)");
#endif            
            res->pmre = out;
            return res;
        }

        RestMethodEntry* RequestRouter::getRestMethodEntry(ResourcePtr rp, std::string mpath, const web::http::method& method) {
            RestMethodEntry* res = nullptr;
            if (method == web::http::methods::GET) {
                res = &rp->reg_map[mpath].GET_m;
            } else if (method == web::http::methods::PUT) {
                res = &rp->reg_map[mpath].PUT_m;
            } else if (method == web::http::methods::POST) {
                res = &rp->reg_map[mpath].POST_m;
            } else if (method == web::http::methods::DEL) {
                res = &rp->reg_map[mpath].DELETE_m;
            } else if (method == web::http::methods::OPTIONS) {
                res = &rp->reg_map[mpath].OPTIONS_m;
            }
            return res;
        }

        bool RequestRouter::processCall(ResourcePtr rp, std::string rpath, web::http::http_request& message, const web::http::method& method) {
            bool res = true;
            string mpath = "";
            ParamsPtr params(new Params);
            //loop trough resource configured paths to find match
            for (const auto& rme : rp->reg_map) {
                //build RE and path parameters vector
                RbrePtr bre = getBRE(rme.first);
                smatch m;
                regex re(bre->pmre);
                if (regex_match(rpath, m, re)) {
                    int idx = 0;
                    for (size_t i = 2; i < m.size(); i++) {
                        params->path_params[bre->pnames[idx]] = m[i].str();
                        i++;
                        idx++;
                    }
                    mpath = rme.first;
                    break;
                }
            }
            if (!mpath.empty()) {
                //path found, check HTTP method and execute
                RestMethodEntry* rme = getRestMethodEntry(rp, mpath, method);
                if (rme != nullptr && rme->inited) {
                    //we have inited method for this call
                    if (rp->headers_fn != nullptr) {
                        (rp->headers_fn)(message.headers());
                    }
                    //extract request parameters if so
                    web::uri rq_uri = message.request_uri();
                    string query = rq_uri.query();
                    std::istringstream qss(query);
                    if (!query.empty()) {
                        std::string keyval, key, val;
                        while (std::getline(qss, keyval, '&')) // split each term
                        {
                            std::istringstream iss(keyval);
                            if (std::getline(std::getline(iss, key, '='), val))
                                params->request_params[key] = val;
                        }
                    }
                    (rme->fn)(message, params);
                }else{
                    res=false;
                }
            } else {
                res = false;
            }

            return res;
        }

        //-- end        
    }
}
