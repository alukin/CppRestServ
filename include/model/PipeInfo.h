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

#include "PipeStatusEnum.h"
#include "PipeDef.h"
#include <memory>

namespace sp {
    namespace rest {
        namespace model {

            /// <summary>
            /// Extended Pipeline object with pipe definition inside of it optionally
            /// </summary>

            class PipeInfo : public ModelBase {
            public:
                PipeInfo(){};
                virtual ~PipeInfo(){};

                web::json::value toJson() const override {
                    web::json::value res;
                    res["id"] = web::json::value(id);
                    res["name"] = web::json::value(name);
                    res["status"] = status->toJson();
                    res["pipedef"] = pipedef->toJson();
                    return res;
                };

                void fromJson(web::json::value& json) override {
                    (void) json;
                    id = json.at("id").as_string();
                    name = json.at("name").as_string();
                    status = std::make_shared<PipeStatusEnum>();
                    status->fromJson(json.at("status"));
                    pipedef = std::make_shared<PipeDef>();
                    pipedef->fromJson(json.at("pipedf"));
                };
                std::string id = "";
                std::string name = "";
                std::shared_ptr<PipeStatusEnum> status = std::make_shared<PipeStatusEnum>();
                std::shared_ptr<PipeDef> pipedef = std::make_shared<PipeDef>();;
            };

        }
    }
}

