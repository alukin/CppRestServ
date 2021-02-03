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

#include <string>
#include <cpprest/json.h>

namespace sp {
    namespace rest {
        namespace model {

            class ModelBase {
            public:
                ModelBase(){};
                virtual ~ModelBase(){};
                virtual web::json::value toJson() const = 0;
                virtual void fromJson(web::json::value& json) = 0;             
            private:
            };

        }
    }
}


