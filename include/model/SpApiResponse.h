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

#include "ModelBase.h"

#define SP_REST_CODE_OK 0
#define SP_REST_CODE_ERROR 1
#define SP_REST_CODE_NOT_IMPLEMENED 2

namespace sp {
    namespace rest {
        namespace model {
            class SpApiResponse : public ModelBase {
            public:
                SpApiResponse(){};
                virtual ~SpApiResponse(){};
                web::json::value toJson() const override{
                    web::json::value res;
                    res["code"]=web::json::value(code);
                    res["message"]==web::json::value(message);
                    return res;
                }
                void fromJson(web::json::value& json) override{
                    code = json.at("code").as_integer();
                    message = json.at("message").as_string();
                }
                //json fields
                int code=0;
                std::string message="";
            };
        }
    }
}


