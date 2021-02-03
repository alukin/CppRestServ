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

#include "rest/HTTPAPIServer.h"
#include <boost/algorithm/string/replace.hpp>
#include "SPLog.h"

using namespace web::http::experimental::listener;

namespace sp {
    namespace rest{
        
HTTPAPIServer::HTTPAPIServer(std::string base_url, std::string static_path, std::string static_root_dir, std::string rest_path){
//Setup RequestRouter
    _rqrouter.setStaticPath(static_path);
    _rqrouter.setStaticRootDir(static_root_dir);
    _rqrouter.setRestPath(rest_path);
    _listener = http_listener(base_url);
//    
    _listener.support(methods::GET, std::bind(&HTTPAPIServer::handle_get, this, std::placeholders::_1));
    _listener.support(methods::PUT, std::bind(&HTTPAPIServer::handle_put, this, std::placeholders::_1));
    _listener.support(methods::POST, std::bind(&HTTPAPIServer::handle_post, this, std::placeholders::_1));
    _listener.support(methods::DEL, std::bind(&HTTPAPIServer::handle_delete, this, std::placeholders::_1));    
    _listener.support(methods::OPTIONS, std::bind(&HTTPAPIServer::handle_options, this, std::placeholders::_1));
    LOG_DEBUG<<"Starting RESTHTTPServer. base_url="<<base_url<<" statis_path="<<static_path
            <<" static_rootdir="<<static_root_dir<<" rest_path="<<rest_path;    
} 

HTTPAPIServer::~HTTPAPIServer ()
{
    _bloop = false;
    _wakeup.notify_all();
    stop();
}
bool HTTPAPIServer::start(){
    // Start listener
    bool res = true;
    try{
       _listener.open().wait();
       _bloop = true;
    }catch(...){
        _bloop=false;
        res=false;
    }   

    return res;
}

bool HTTPAPIServer::stop()
{
    if(_bloop)
    {
        auto task = _listener.close();
        if(task._GetImpl())
        {
            task.wait();
        }
        _bloop = false;
        _wakeup.notify_all();
    }

    return true;
}

void HTTPAPIServer::join()
{
    while (_bloop.load())
    {
        std::unique_lock<std::mutex> lock(_guardMutex);
        _wakeup.wait_for(lock, _timeout, [this]() { return !this->_bloop.load(); });
    }
}

void HTTPAPIServer::handle_get(http_request request)
{
    _rqrouter.route(request, methods::GET);
}

void HTTPAPIServer::handle_put(http_request request)
{
    _rqrouter.route(request, methods::PUT);
}

void HTTPAPIServer::handle_post(http_request request)
{
    _rqrouter.route(request, methods::POST);
}
void HTTPAPIServer::handle_delete(http_request request)
{
    _rqrouter.route(request, methods::DEL);
}

void HTTPAPIServer::handle_options(http_request request)
{
    _rqrouter.route(request, methods::OPTIONS);
}

}
}
