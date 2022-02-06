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



#include "PipesResource.h"
#include "SPLog.h"
#include "model/PipeInfoResponse.h"

#define PIPE_OP_START "start"
#define PIPE_OP_STOP "stop"
#define PIPE_OP_PAUSE "pause"
#define PIPE_OP_TERMINATE "terminate"

namespace sp {
PipesResource::PipesResource(std::string some, Injectable& inj)  : m_inject(inj){
    m_some = some;
    registerMethods();
}
void PipesResource::registerMethods(){
    headers_fn=bind(&PipesResource::precessHeaders,this, placeholders::_1);

    reg_map["/"]={
        .GET_m = {
            .inited =  true,
            .fn =  bind(&PipesResource::doGET_,this,placeholders::_1,placeholders::_2),
            .accepts =  "",
            .produces =  "application/json"
        },
        .PUT_m = {
            .inited =  true,
            .fn =  bind(&PipesResource::doPUT_,this,placeholders::_1,placeholders::_2),
            .accepts =  "application/json",
            .produces =  "application/json"
        },
        .POST_m = {
            .inited =  false
        },
        .DELETE_m = {
            .inited =  false
        },
        .OPTIONS_m = {
            .inited =  false
        }
    };

    reg_map["/{id}"]={
        .GET_m = {
            .inited =  true,
            .fn =  bind(&PipesResource::doGET_byId,this,placeholders::_1,placeholders::_2),
            .accepts =  "",
            .produces =  "application/json"
        },
        .PUT_m = {
            .inited =  false
        },
        .POST_m = {
            .inited =  true,
            .fn =  bind(&PipesResource::doPOST_byId,this,placeholders::_1,placeholders::_2),
            .accepts =  "application/json",
            .produces =  "application/json"
        },
        .DELETE_m = {
            .inited =  false
        },
        .OPTIONS_m = {
            .inited =  false
        }    
    };
    reg_map["/{pipeId}/{pipeOp}"]={
        .GET_m = {
            .inited =  false
        },
        .PUT_m = {
            .inited =  false
        },
        .POST_m = {
            .inited =  true,
            .fn =  bind(&PipesResource::doPOST_PpipeId_PpipeOp,this,placeholders::_1,placeholders::_2),
            .accepts =  "application/json",
            .produces =  "application/json"
        },
        .DELETE_m = {
            .inited =  false
        },
        .OPTIONS_m = {
            .inited =  false
        }    
    };    
}

PipesResource::~PipesResource() {
}

void PipesResource::precessHeaders(web::http::http_headers& hdrs){
    
}
void PipesResource::doGET_(web::http::http_request& rq, sp::rest::ParamsPtr params){
    cout <<"doGet_"<<endl;
}
void PipesResource::doPUT_(web::http::http_request& rq, sp::rest::ParamsPtr params){
    cout <<"doPUT_"<<endl;    
}
void PipesResource::doGET_byId(web::http::http_request& rq, sp::rest::ParamsPtr params){
    cout <<"doGet_byId"<<endl;
    string rep = U("PipesResource::doGET_byId OPERATION called\n");
    for (auto kv: params->path_params){
        rep=rep+"PATH_PARAM "+kv.first+"="+kv.second+"\n";
    }
    for (auto kv: params->request_params){
        rep=rep+"REQUEST_PARAM "+kv.first+"="+kv.second+"\n";        
    }
    cout<<rep<<endl;
    rest::model::PipeInfoResponse resp;
    shared_ptr<rest::model::PipeInfo> pi(new rest::model::PipeInfo());
    pi->id="pipe1";
    pi->name="pipe1";
    resp.pipes.push_back(pi);

    cout<<"====== "<<resp.toJson().serialize()<<"==========";
    rq.reply(web::http::status_codes::OK, resp.toJson());    
}
void PipesResource::doPOST_byId(web::http::http_request& rq, sp::rest::ParamsPtr params){
    cout <<"doPost_byId"<<endl;    
}

void PipesResource::doPOST_PpipeId_PpipeOp(web::http::http_request& rq, sp::rest::ParamsPtr params){
    std::string id = params->path_params["pipeId"];
    std::string op = params->path_params["pipeOp"];
    LOG_DEBUG<<"pipeId="<<id<<" pipeOp="<<op;
    rest::model::SpApiResponse resp;
    resp.code = SP_REST_CODE_OK;    
    web::http::status_code ret_code = web::http::status_codes::OK;
    
   // auto pipeline = m_pipelineManager.GetPipeline(id);
    if (true) {
        bool op_res = false;
        if(op==PIPE_OP_START){
            op_res = true;
        }else if (op==PIPE_OP_STOP){
            op_res = true;
        }else if (op==PIPE_OP_PAUSE){
            op_res = true;
        }else if (op==PIPE_OP_TERMINATE){
            op_res = true;
        }else{
          op_res = true;  
          ret_code = web::http::status_codes::NotImplemented;
          resp.message = "Not implemented: "+op;   
        }
        if(!op_res){
            resp.code=SP_REST_CODE_ERROR;
            resp.message=" Operation: "+op+" on pipe: "+id+" failed.";
        }
    }else{
        resp.code = SP_REST_CODE_ERROR;
        ret_code = web::http::status_codes::NotFound;
    }
    rq.reply(ret_code, resp.toJson());    
}


}
