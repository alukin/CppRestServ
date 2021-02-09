# C++ RestAPI/HTTP Server

This is "testbed" project for Casablanca (MS cpprest)
based REST/HTTP  server (https://github.com/Microsoft/cpprestsdk)

Main idea is to enable easy REST endpoint creation and simple static conten
serving in C++ project that use cpprest.

It is about 2 years old and provided here as example of my C++ code. But anyway, feel fre to use it.
I hope this code will be usefull as example of Java-style easy to use REST service library.

If I where writing such kind of library today, I'd use [Boot Beast](https://www.boost.org/doc/libs/1_74_0/libs/beast/doc/html/index.html)
and [JSON library by Niels Lohmann](https://github.com/nlohmann/json).

### Requirements

Boost developemnt package (boost-devel) and CPPRest development package (cppres-devel)

You also need CMake and, obviously, gcc-c++.
On Fedora Linux, run:

sudo dnf install boost-devel cpprest-devel cmake gcc-c++

