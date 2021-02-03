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

#include "rest/ResourceBase.h"
#include "Injectable.h"
#include <iostream>

namespace sp {

    using namespace rest;
    using namespace std;

    class PipesResource : public sp::rest::ResourceBase {
    public:
        PipesResource(std::string some, Injectable& inj);
        virtual ~PipesResource();
        void precessHeaders(web::http::http_headers& hdrs);
        void doGET_(web::http::http_request& rq, sp::rest::ParamsPtr params);
        void doPUT_(web::http::http_request& rq, sp::rest::ParamsPtr params);
        void doGET_byId(web::http::http_request& rq, sp::rest::ParamsPtr params);
        void doPOST_byId(web::http::http_request& rq, sp::rest::ParamsPtr params);
        void doPOST_PpipeId_PpipeOp(web::http::http_request& rq, sp::rest::ParamsPtr params);
        
    private:
        std::string m_some;
        Injectable& m_inject;
        void registerMethods();
    };
}


