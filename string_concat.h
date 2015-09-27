//for C++03 and previous versions only
//In C++11 to_string() should be used
#ifndef STRING_CONCAT_H
#define STRING_CONCAT_H

#include <sstream>
#include <ios>
#include <iomanip>

#define INT_TO_STR_BODY_(n) ({\
    str_cc_ss.seekp(std::ios::beg); \
    str_cc_ss << n << '\0'; \
    return str_cc_ss.str().c_str();\
})

#define FLOAT_TO_STR_BODY_(val, precision) ({\
    str_cc_ss.seekp(std::ios::beg);\
    str_cc_ss << std::setprecision(precision) << val << '\0';\
    return str_cc_ss.str().c_str();\
})


static std::stringstream str_cc_ss;


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
