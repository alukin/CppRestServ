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

#include "SpApiResponse.h"
#include <cpprest/details/basic_types.h>

namespace sp {
    namespace rest {
        namespace model {

            /// <summary>
            /// 
            /// </summary>

            class SpStatus : public SpApiResponse {
            public:
                SpStatus();
                virtual ~SpStatus();

                web::json::value toJson() const override {
                    web::json::value res;
                    return res;
                }

                void fromJson(web::json::value& json) override {
                    (void)json;
                }
// This is in YAML spec but not yet implemented                
//                std::string serverId="SP";
//                int cpuLoad=0;
//                utility::datetime upSince=utility::datetime::from_string("1997-07-16T19:20:30.45+01:00");
//                std::string state="running";
            };

        }
    }
}

