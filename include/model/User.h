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
#include <cpprest/details/basic_types.h>

namespace sp {
    namespace rest {
        namespace model {

            /// <summary>
            /// 
            /// </summary>

            class User : public ModelBase {
            public:
                User();
                virtual ~User();

                web::json::value toJson() const override {
                    web::json::value res;
                    return res;
                };

                void fromJson(web::json::value& json) override {
                    (void) json;
                };
// This is in YAML spec but not yet implemented
//                long id=0;
//                std::string username="";
//                std::string firstName="";
//                std::string lastName="";
//                std::string email="";
//                std::string password="";
//                std::string phone="";
//                int userStatus=0;
            };

        }
    }
}

