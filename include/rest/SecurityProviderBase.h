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

namespace sp {
    namespace rest {

        class SecurityProviderBase {
        public:

            SecurityProviderBase() {
            };

            virtual ~SecurityProviderBase() {
            };

            virtual bool basic_authenticate(std::string user, std::string password) {
                (void) user;
                (void) password;
                return true;
            }

            virtual bool authenticate_request(web::http::http_request& message) {
                (void) message;
                return true;
            }
        private:

        };
    }
}


