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

#include <thread>
#include <chrono>
#include <cpprest/http_listener.h>
#include <rest/RequestRouter.h>

using namespace web::http;
using namespace web;

namespace sp {
    namespace rest{
class HTTPAPIServer
{
public:
    HTTPAPIServer(std::string base_url):HTTPAPIServer(base_url,"/","/var/www/html","/api"){};
    HTTPAPIServer(std::string base_url, std::string static_path, std::string static_root_dir, std::string rest_path);
    ~HTTPAPIServer();

    bool start();
    bool stop();
    void join();
    // Register rest api endpoint.
    void registerRESTEndpoint(std::string path, rest::CreateResourceFn pfnCreate){
        _rqrouter.registerService(path, pfnCreate);
    };
    void unRegisterRESTEndpoint(std::string path){
        _rqrouter.unRegisterService(path);
    };

private:
    rest::RequestRouter _rqrouter;
    // Callbacks.
    void handle_get(http_request request);
    void handle_put(http_request request);
    void handle_post(http_request request);
    void handle_delete(http_request request);
    void handle_options(http_request request);

    // Async wait for shutdown.
    std::mutex _guardMutex;
    std::condition_variable _wakeup;
    std::atomic_bool _bloop { false };
    std::chrono::system_clock::duration _timeout = std::chrono::milliseconds(500);

    // HTTP Server listener.
    web::http::experimental::listener::http_listener _listener;

};

}
}