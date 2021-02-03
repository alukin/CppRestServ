#pragma once

#include <boost/log/trivial.hpp>

inline std::string className(const std::string& prettyFunction)
{
    size_t colons = prettyFunction.find("(");
    if (colons == std::string::npos)
        return "::";
    size_t begin = prettyFunction.substr(0,colons).rfind(" ") + 1;
    size_t end = colons - begin;

    return prettyFunction.substr(begin,end);
}

#define __CLASS_NAME__ className(__PRETTY_FUNCTION__)

#define LOG_TRACE   BOOST_LOG_TRIVIAL(trace)    << __CLASS_NAME__ << "(): "
#define LOG_DEBUG   BOOST_LOG_TRIVIAL(debug)    << __CLASS_NAME__ << "(): "
#define LOG_INFO    BOOST_LOG_TRIVIAL(info)
#define LOG_WARNING BOOST_LOG_TRIVIAL(warning)
#define LOG_ERROR   BOOST_LOG_TRIVIAL(error)
#define LOG_FATAL   BOOST_LOG_TRIVIAL(fatal)
