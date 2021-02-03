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
#include "PipeInfo.h"
#include <vector>

namespace sp {
    namespace rest {
        namespace model {

            /// <summary>
            /// 
            /// </summary>

            class PipeInfoResponse : public SpApiResponse {
            public:
                PipeInfoResponse(){};
                virtual ~PipeInfoResponse(){};

                web::json::value toJson() const override {
                    web::json::value res;
                    res["pipes"]=web::json::value::array();
                    for(size_t i=0; i<pipes.size(); i++){
                        res["pipes"][i] =pipes[i]->toJson();
                    }
                    return res;
                };

                void fromJson(web::json::value& json) override {
                    (void)json;
                };

                std::vector<std::shared_ptr<PipeInfo>> pipes;
            };

        }
    }
}

