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
// #include "../IPipeline.h"

namespace sp {
    namespace rest {
        namespace model {

            /// <summary>
            /// 
            /// </summary>

            class PipeStatusEnum
            : public ModelBase {
            public:
                PipeStatusEnum(){};
/*
                PipeStatusEnum(IPipeline::PipelineState pstate){
                    switch(pstate){
                        case IPipeline::PipelineState::STATE_VOID_PENDING:
                            status="pening";
                            break;
                        case IPipeline::PipelineState::STATE_NULL:
                            status="state_null";
                            break;
                        case IPipeline::PipelineState::STATE_PAUSED:
                            status="paused";
                            break;
                        case IPipeline::PipelineState::STATE_PLAYING:
                            status="playing";
                            break;
                        case IPipeline::PipelineState::STATE_READY:
                            status="ready";
                            break;
                    };
                };
*/
                virtual ~PipeStatusEnum(){};

                web::json::value toJson() const override {
                    web::json::value res;
                    res["status"]=web::json::value(status);
                    return res;
                };

                void fromJson(web::json::value& json) override {
                    status=json.at("status").as_string(); ;
                };
            protected:
                std::string status="";
            };

        }
    }
}

