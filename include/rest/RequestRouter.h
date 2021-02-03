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

#pragma once

#include "rest/ResourceFactory.h"
#include "rest/ResourceBase.h"
#include "rest/StaticContentServ.h"
#include "rest/SecurityProviderBase.h"

#include <cpprest/http_msg.h>
#include <cpprest/uri.h>
#include <string>
#include <vector>
#include <memory>

namespace sp{
namespace rest{

struct Rbre{
    std::string pmre;
    std::vector<std::string> pnames;
};
typedef std::unique_ptr<Rbre> RbrePtr;

class RequestRouter {
  public:
    RequestRouter();
    virtual ~RequestRouter();
    void route(web::http::http_request& message, const web::http::method& method);
    void registerService(std::string name, CreateResourceFn pfnCreate);
    void unRegisterService(std::string name);
    void setRestPath(std::string path);
    void setStaticPath(std::string path);
    void setStaticRootDir(std::string path);
  private:
    bool processCall(ResourcePtr rp, std::string rpath, web::http::http_request& message, const web::http::method& method);
    void defaultReply(web::http::http_request message);
    RbrePtr getBRE(const std::string& bs);
    RestMethodEntry *getRestMethodEntry(ResourcePtr rp, std::string mpath, const web::http::method& method);
    std::string url;
    std::string rest_path = "/api";
    std::string static_root_dir = "/var/http";
    std::string static_path = "/";
    std::map<std::string,ResourcePtr> resource_map;
    StaticContentServ static_serv;
    ResourceFactory m_factory;
    SecurityProviderBase m_security_provider;
};

}
}

