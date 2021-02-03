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



#include "rest/ResourceFactory.h"
#include <functional>

namespace sp {
    namespace rest {


        ResourceFactory::ResourceFactory() {
        }

        ResourceFactory::~ResourceFactory() {
            m_FactoryMap.clear();
        }

        void ResourceFactory::registerResource(const std::string &name, CreateResourceFn pfnCreate) {
            m_FactoryMap[name]=pfnCreate;
        }
        
        void ResourceFactory::unRegisterResource(const std::string &name) {
            m_FactoryMap.erase(name);
        }
        
        ResourcePtr ResourceFactory::createResource(std::string name) {
            ResourcePtr res;
            FactoryMap::iterator it = m_FactoryMap.find(name);
            if (it != m_FactoryMap.end()) {
                res =  it->second();
            }
            return res;

        }



    }
}
