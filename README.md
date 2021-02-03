# C++ RestAPI/HTTP Server

This is "testbed" project for Casablanca (MS cpprest)
based REST/HTTP  server (https://github.com/Microsoft/cpprestsdk)

Main idea is to enable easy REST endpoint creation and simple static conten
serving in C++ project that use cpprest.

It is about 2 years old and provided here as example of my C++ code. But anyway, feel fre to use it.
May be better solution today is to use "Beast" library from Boost library, but anyway, I hope this code will be usefull
as example

### Requirements

Boost developemnt package (boost-devel) and CPPRest development package (cppres-devel)

You also need CMake and, obviously, gcc-c++.
On Fedore, run:

dnf install boost-devel cpprest-devel cmake gcc-c++

