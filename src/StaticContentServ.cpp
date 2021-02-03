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



#include "rest/StaticContentServ.h"
#include "cpprest/asyncrt_utils.h"
#include "cpprest/filestream.h"
#include "cpprest/containerstream.h"
#include "cpprest/producerconsumerstream.h"

#include <iostream>
#include <sys/stat.h>

namespace sp {
    namespace rest {
        using namespace std;

        struct ext_mapping {
            const char* extension;
            const char* mime_type;
        } mappings[] = {
            { "gif", "image/gif"},
            { "jpg", "image/jpeg"},
            { "jpeg", "image/jpeg"},
            { "png", "image/png"},
            { "htm", "text/html"},
            { "html", "text/html"},
            { "js", "text/javascript"},
            { "css", "text/css"},
            { "txt", "text/plain"},
            { "json", "application/json"},
            { "xml", "application/xml"}

        };

        StaticContentServ::StaticContentServ() {
        }

        StaticContentServ::~StaticContentServ() {
        }

        std::string StaticContentServ::extensionToType(const std::string& extension) {
            for (ext_mapping m : mappings) {
                if (m.extension == extension) {
                    return m.mime_type;
                }
            }
            return "text/plain";
        }

        ContentInfo StaticContentServ::getContentInfo(std::string dpath) {
            ContentInfo ci;
            struct stat st;
            ci.accessible = (stat(dpath.c_str(), &st) == 0);
            if (ci.accessible) {
                ci.isDirectory = S_ISDIR(st.st_mode);
                if (!ci.isDirectory) {
                    ci.size = st.st_size;
                    // Determine the file extension.
                    std::size_t last_slash_pos = dpath.find_last_of("/");
                    std::size_t last_dot_pos = dpath.find_last_of(".");
                    std::string extension;
                    if (last_dot_pos != std::string::npos && last_dot_pos > last_slash_pos) {
                        extension = dpath.substr(last_dot_pos + 1);
                    }
                    ci.mime_type = extensionToType(extension);
                }
            }
            return ci;
        }

        int StaticContentServ::serve(web::http::http_request& message, std::string path) {


            std::string disk_path = web_root + path;
            ContentInfo ci = getContentInfo(disk_path);
            if (!ci.accessible) {
                message.reply(web::http::status_codes::NotFound, U("File not found: ") + path);
                return -1;
            }
            // If path  is a directory then add "index.html".

            if (ci.isDirectory) {
                if (disk_path[disk_path.length() - 1] != '/') {
                    disk_path += "/";
                }
                disk_path += "index.html";
                ci = getContentInfo(disk_path);
                if (!ci.accessible) {
                    message.reply(web::http::status_codes::NotFound, U("File not found: ") + path);
                    return -1;
            }
        }

        concurrency::streams::fstream::open_istream(disk_path, std::ios::in)
        .then([ = ](concurrency::streams::istream is){
            message.reply(web::http::status_codes::OK, is, ci.size, ci.mime_type)
            .then([ & ](pplx::task<void> t) {
                try {
                    t.get();
                } catch (...) {
                    message.reply(web::http::status_codes::NotFound, U("File not found"));
                    // res = -1;
                }
            });
        }).then([ & ](pplx::task<void>t) {
            try {
                t.get();
            } catch (...) {
                message.reply(web::http::status_codes::InternalError, U("INTERNAL ERROR "));
                // res = -2;
            }
        });
        return 0;
    }

}
}
