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

#include <memory>
#include <map>
#include <functional>
#include <cpprest/http_msg.h>
#include <cpprest/uri.h>

namespace sp{
namespace rest{    

typedef std::map<std::string,std::string> tPathParams;
typedef std::map<std::string,std::string> tReqParams;

struct Params{
   std::map<std::string,std::string>  path_params;
   std::map<std::string,std::string>  request_params;
};    

typedef std::shared_ptr<Params> ParamsPtr; 

typedef std::function<void (web::http::http_request&, ParamsPtr )> RestMethodFn;    
typedef std::function<void (web::http::http_headers&)> HeadersFn;

struct RestMethodEntry{
  bool inited;  
  RestMethodFn fn;  
  std::string accepts;
  std::string produces;
};

/**
 * Resord for rest methods registration. Please
 * be carefull with fields order.
 */
struct RestMethodsRec{
   RestMethodEntry GET_m;   
   RestMethodEntry PUT_m;   
   RestMethodEntry POST_m;   
   RestMethodEntry DELETE_m;   
   RestMethodEntry OPTIONS_m;
};

/**
 * key is path, path may contain path-encoded variables e.g. {id}
 */
typedef std::map<std::string, RestMethodsRec> tMethodReMgap;

class ResourceBase {
    friend class RequestRouter;  
public:
    ResourceBase(){};
    virtual ~ResourceBase(){};
protected:
    tMethodReMgap reg_map;    
    HeadersFn headers_fn=nullptr;   
private:

};
typedef std::shared_ptr<ResourceBase> ResourcePtr; 

/**
 * prototype for "create" static funtion that creates
 * instance of derived classes. Used in ResourceFactory
 * to create resource instance by name(path)
 */
typedef std::function<ResourcePtr(void)> CreateResourceFn;

}
}


