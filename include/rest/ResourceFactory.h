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

#include <rest/ResourceBase.h>
#include <memory>
#include <map>

namespace sp{
namespace rest{    

class ResourceFactory {
public:
    ResourceFactory();
    virtual ~ResourceFactory();
    ResourcePtr createResource(std::string name);
    void registerResource(const std::string &name, CreateResourceFn pfnCreate);
    void unRegisterResource(const std::string &name);
    static ResourceFactory *getInstance();
private:
    static ResourceFactory *instance;
    typedef std::map<std::string, CreateResourceFn> FactoryMap; 
    FactoryMap m_FactoryMap; 
};

}
}


