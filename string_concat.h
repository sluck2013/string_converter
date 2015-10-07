//for C++03 and previous versions only
//In C++11 to_string() should be used
#ifndef STRING_CONCAT_H
#define STRING_CONCAT_H

#include <ios>
#include <iomanip>
#include "SStreamPool.h"

#define INT_TO_STR_BODY_(n) ({\
    SStream *str_cc_ss = sstreamPool.getSStream() \
    str_cc_ss->stream.seekp(std::ios::beg); \
    str_cc_ss->stream << n << '\0'; \
    std::string result = str_cc_ss->stream.str().c_str();\
    sstreamPool.putSStream(str_cc_ss); \
    return result; \
})

#define FLOAT_TO_STR_BODY_(val, precision) ({\
    SStream *str_cc_ss = sstreamPool.getSStream(); \
    str_cc_ss->stream.seekp(std::ios::beg);\
    str_cc_ss->stream << std::setprecision(precision) << val << '\0';\
    std::string result = str_cc_ss->stream.str().c_str();\
    sstreamPool.putSStream(str_cc_ss); \
    return result; \
})

static SStreamPool& sstreamPool = SStreamPool::getInstanceWithPoolSize(10);

std::string toString(const std::string& s) {
    return s;
}

std::string toString(const char* cstr) {
    return cstr;
}

std::string toString(const short n) {
    INT_TO_STR_BODY_(n);
}

std::string toString(const unsigned short n) {
    INT_TO_STR_BODY_(n);
}

std::string toString(const int n) {
    INT_TO_STR_BODY_(n);
}

std::string toString(const unsigned int n) {
    INT_TO_STR_BODY_(n);
}

std::string toString(const long n) {
    INT_TO_STR_BODY_(n);
}

std::string toString(const unsigned long n) {
    INT_TO_STR_BODY_(n);
}

std::string toString(const long long n) {
    INT_TO_STR_BODY_(n);
}

std::string toString(const unsigned long long n) {
    INT_TO_STR_BODY_(n);
}

std::string toString(const float val, const int precision = 6) {
    FLOAT_TO_STR_BODY_(val, precision);
}

std::string toString(const double val, const int precision = 6) {
    FLOAT_TO_STR_BODY_(val, precision);
}

std::string toString(const long double val, const int precision = 6) {
    FLOAT_TO_STR_BODY_(val, precision);
}

std::string toString(const char c) {
    return std::string(1, c);
}

std::string toString(const bool b) {
    if (b) {
        return "true";
    } else {
        return "false";
    }
}

template<typename T1, typename T2>
std::string operator+(const T1& v1, const T2& v2) {
    return toString(v1) + toString(v2);
}

#endif
