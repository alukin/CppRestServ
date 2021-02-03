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

#include <iostream>

#include "rest/HTTPAPIServer.h"
#include "PipesResource.h"
#include "UserResource.h"
#include "Injectable.h"

using namespace std;
using namespace web;
using namespace http;
using namespace utility;
using namespace http::experimental::listener;



using namespace sp;
using namespace rest;

std::unique_ptr<HTTPAPIServer> g_httpHandler;

void on_initialize(const string_t& address)
{


    uri_builder uri(address);
  

    auto addr = uri.to_uri().to_string();
    
    g_httpHandler = std::unique_ptr<HTTPAPIServer>(new HTTPAPIServer(addr,"/web","/home/al/web","/api"));

    Injectable inj(123);

    g_httpHandler->registerRESTEndpoint("pipes",[&]{
          ResourcePtr res(new PipesResource("some string",inj));
          return res;
        }
    );
    g_httpHandler->registerRESTEndpoint("user",[]{
         ResourcePtr res(new UserResource());
         return res;
    });
    g_httpHandler->start();

    ucout << utility::string_t(U("Listening for requests at: ")) << addr << std::endl;

    return;
}

void on_shutdown()

{
    g_httpHandler->unRegisterRESTEndpoint("pipes");
    g_httpHandler->unRegisterRESTEndpoint("user");
    g_httpHandler->stop();
    g_httpHandler->join();
    return;
}


int main(int argc, char *argv[])

{
    utility::string_t port = U("8080");
    if(argc == 2)
    {
        port = argv[1];
    }

    utility::string_t address = U("http://127.0.0.1:");
    address.append(port);
    address.append("/sp");  
    on_initialize(address);
    std::cout << "Press ENTER to exit." << std::endl;

    std::string line;
    std::getline(std::cin, line);

    on_shutdown();
    return 0;
}

