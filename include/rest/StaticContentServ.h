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

#include <cpprest/http_msg.h>
#include <cpprest/uri.h>
#include <string>

namespace sp{
namespace rest{    
    
    struct ContentInfo{
        std::string mime_type;
        size_t size;
        bool accessible;
        bool isDirectory;
    };
    
class StaticContentServ {
public:
    StaticContentServ();
    virtual ~StaticContentServ();
    /// serve static content from the disk path
    int serve(web::http::http_request& message, std::string rel_path);
    void setWebRoot(std::string disk_path){
        web_root = disk_path;
    };
    std::string getWebRoot(std::string disk_path){
        return disk_path;
    };
private:
    std::string web_root="/var/www/httml";
    /// Convert a file extension into a MIME type.
    std::string extensionToType(const std::string& extension);
    ContentInfo getContentInfo(std::string dpath);
};
}
}

