#include "../string_concat.h"

#define CATCH_CONFIG_MAIN
#include "catch.hpp"

using namespace std;

TEST_CASE("convert [string] to string", "[toString]") {
    string s1 = "test string";
    string s2 = "";
    REQUIRE(toString(s1) == "test string");
    REQUIRE(toString(s2) == "");
}

TEST_CASE("convert [c-style string] to string", "[toString]") {
    const char *c1 = "test c-style string";
    const char *c2 = "";
    char c3[] = "char array";
    REQUIRE(toString(c1) == "test c-style string");
    REQUIRE(toString(c2) == "");
    REQUIRE(toString("abc") == "abc");
    REQUIRE(toString(c3) == "char array");
}

TEST_CASE("convert [short] to string", "[toString]") {
    short n1 = -32768, n2 = 0, n3 = 32767;
    REQUIRE(toString(n1) == "-32768");
    REQUIRE(toString(n2) == "0");
    REQUIRE(toString(n3) == "32767");
}

TEST_CASE("convert [unsigned short] to string", "[toString]") {
    unsigned short n1 = 0, n2 = 32756, n3 = 65535;
    REQUIRE(toString(n1) == "0");
    REQUIRE(toString(n2) == "32756");
    REQUIRE(toString(n3) == "65535");
}

TEST_CASE("convert [int] to string", "[toString]") {
    int n1 = -56568, n2 = 0, n3 = 2147483647;
    REQUIRE(toString(n1) == "-56568");
    REQUIRE(toString(n2) == "0");
    REQUIRE(toString(n3) == "2147483647");
}


TEST_CASE("convert [unsigned int] to string", "[toString]") {
    unsigned int n1 = 56568, n2 = 0, n3 = 2149483742;
    REQUIRE(toString(n1) == "56568");
    REQUIRE(toString(n2) == "0");
    REQUIRE(toString(n3) == "2149483742");
}

TEST_CASE("convert [long] to string", "[toString]") {
    long n1 = -56568, n2 = 0, n3 = 2147483647;
    REQUIRE(toString(n1) == "-56568");
    REQUIRE(toString(n2) == "0");
    REQUIRE(toString(n3) == "2147483647");
}

TEST_CASE("convert [unsigned long] to string", "[toString]") {
    unsigned long n1 = 56568, n2 = 0, n3 = 2149483742;
    REQUIRE(toString(n1) == "56568");
    REQUIRE(toString(n2) == "0");
    REQUIRE(toString(n3) == "2149483742");
}

TEST_CASE("convert [float] to string", "[toString]") {
    float n1 = 0.256f, n2 = -56565.565f, n3 = 0.0f, n4 = 1234564578.12345678f;
    REQUIRE(toString(n1) == "0.256");
    REQUIRE(toString(n2) == "-56565.6");
    REQUIRE(toString(n4) == "1.23456e+09");
    REQUIRE(toString(n4, 9) == "1.23456461e+09");
    REQUIRE(toString(n3) == "0");
    REQUIRE(toString(n2, 7) == "-56565.57");
}

TEST_CASE("convert [double] to string", "[toString]") {
    double n1 = 0.256, n2 = -56565.565, n3 = 0.00, n4 = 123456.789, n5 = 123456789012345678.5;
    REQUIRE(toString(n2) == "-56565.6");
    REQUIRE(toString(n3) == "0");
    REQUIRE(toString(n4) == "123457");
    REQUIRE(toString(n5) == "1.23457e+17");
    REQUIRE(toString(n4, 9) == "123456.789");
    REQUIRE(toString(n1) == "0.256");
}

TEST_CASE("convert [long double] to string", "[toString]") {
    long double n1 = 0.256, n2 = -56565.565, n3 = 0.00, n4 = 123456.789, 
         n5 = 123456789012345678.5, n6 = 1234567890123456.5;
    REQUIRE(toString(n1) == "0.256");
    REQUIRE(toString(n2) == "-56565.6");
    REQUIRE(toString(n3) == "0");
    REQUIRE(toString(n6, 17) == "1234567890123456.5");
    REQUIRE(toString(n4) == "123457");
    REQUIRE(toString(n5) == "1.23457e+17");
}

TEST_CASE("convert [char] to string", "[toString]") {
    REQUIRE(toString('a') == "a");
    REQUIRE(toString('0') == "0");
    REQUIRE(toString(' ') == " ");
}

TEST_CASE("convert [bool] to string", "[toString]") {
    REQUIRE(toString(true) == "true");
    REQUIRE(toString(false) == "false");
}

TEST_CASE("concatenate string", "[operator+'") {
    string s = "s";
    char c = 'c';
    const char* pc = "abc";

    short shortVal = 17;
    unsigned short usVal = 65530;
    int intVal = 2147403656;
    unsigned int uiVal = 3455483656;
    long lVal = -21474836478;
    unsigned long ulVal = 0;
    long long llVal = 214748632145654;
    unsigned long long ullVal = 314748632145654;
    float fVal = -123.56;
    double dVal = -1234.565;
    double dVal2 = 123456.789;
    bool bVal = true;

    REQUIRE(c + s == "cs");
    REQUIRE(s + c == "sc");
    REQUIRE(pc + toString('s') == "abcs");
    REQUIRE(std::string(pc) + shortVal == "abc17");
    REQUIRE(fVal + std::string(pc) == "-123.56abc");
    REQUIRE(s + shortVal == "s17");
    REQUIRE(intVal + s == "2147403656s");
    REQUIRE(s + uiVal == "s3455483656");
    REQUIRE(lVal + s == "-21474836478s");
    REQUIRE(intVal + shortVal == 2147403673);
    REQUIRE(ulVal + s == "0s");
    REQUIRE(llVal + s == "214748632145654s");
    REQUIRE(ullVal + s == "314748632145654s");
    REQUIRE(fVal + s + dVal == "-123.56s-1234.57");
    REQUIRE(toString(dVal2, 9) + s == "123456.789s");
    REQUIRE(bVal + 1 == 2);
    REQUIRE(bVal + s == "trues");
}
