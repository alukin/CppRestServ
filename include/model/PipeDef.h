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

namespace sp {
    namespace rest {
        namespace model {

            /// <summary>
            /// Pipe definition as for SP pipe config (TODO: implement)
            /// </summary>

            class PipeDef : public ModelBase {
            public:
                PipeDef(){};
                virtual ~PipeDef(){};
                web::json::value toJson() const override {
                    web::json::value res;
                    return res;
                };
                void fromJson(web::json::value& json) override {
                    (void)json;
                };
                std::string name="";
            };

        }
    }
}

