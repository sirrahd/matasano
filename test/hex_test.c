#include "test.h"
#include "../src/hex.h"

#define TESTCOUNT 16
#define RESULTLENGTH 8
void TestHexCharToInt(int* success, int* failure) {
    const char FUNCNAME[] = "HexCharToInt";
    const char* tests[TESTCOUNT][2] = {
        {"a", "10"},
        {"A", "10"},
        {"b", "11"},
        {"B", "11"},
        {"c", "12"},
        {"C", "12"},
        {"d", "13"},
        {"D", "13"},
        {"e", "14"},
        {"E", "14"},
        {"f", "15"},
        {"F", "15"},
        {"0", "0"},
        {"1", "1"},
        {"5", "5"},
        {"9", "9"},
    };

    for (int i = 0; i < TESTCOUNT; i++) {
        char result[RESULTLENGTH];
        snprintf(result, RESULTLENGTH, "%i", HexCharToInt(tests[i][0][0]));
        printResult(FUNCNAME, i, result, tests[i][1], success, failure);
    }
}
#undef TESTCOUNT
#undef RESULTLENGTH

#define TESTCOUNT 6
#define RESULTLENGTH 16
void TestHexStringToInt(int* success, int* failure) {
    const char FUNCNAME[] = "HexStringToInt";
    const char* tests[TESTCOUNT][2] = {
        {"492", "1170"},
        {"76d", "1901"},
        {"206b69", "2124649"},
        {"1", "1"},
        {"12", "18"},
        {"1234", "4660"},
    };

    for (int i = 0; i < TESTCOUNT; i++) {
        char result[RESULTLENGTH];
        snprintf(result, RESULTLENGTH, "%i", HexStringToInt(tests[i][0]));
        printResult(FUNCNAME, i, result, tests[i][1], success, failure);
    }
}
#undef TESTCOUNT
#undef RESULTLENGTH

#define TESTCOUNT 4
#define RESULTLENGTH 4
void TestIntToHexChar(int* success, int* failure) {
    const char FUNCNAME[] = "IntToHexChar";
    const char* tests[TESTCOUNT][2] = {
        {"0", "0"},
        {"9", "9"},
        {"10", "a"},
        {"15", "f"},
    };

    for (int i = 0; i < TESTCOUNT; i++) {
        char result[RESULTLENGTH];
        snprintf(result, RESULTLENGTH, "%c", IntToHexChar(atoi(tests[i][0])));
        printResult(FUNCNAME, i, result, tests[i][1], success, failure);
    }
}
#undef TESTCOUNT
#undef RESULTLENGTH

#define TESTCOUNT 3
#define RESULTLENGTH 8
void TestIntToHexString(int* success, int* failure) {
    const char FUNCNAME[] = "IntToHexString";
    const char* tests[TESTCOUNT][2] = {
        {"100", "64"},
        {"1901", "76d"},
        {"518", "206"},
    };

    for (int i = 0; i < TESTCOUNT; i++) {
        char result[RESULTLENGTH];
        IntToHexString(result, RESULTLENGTH, atoi(tests[i][0]));
        printResult(FUNCNAME, i, result, tests[i][1], success, failure);
    }
}
#undef TESTCOUNT
#undef RESULTLENGTH

#define TESTCOUNT 1
#define RESULTLENGTH 32
void TestHexStringToCharString(int* success, int* failure) {
    const char FUNCNAME[] = "HexStringToCharString";
    const char* tests[TESTCOUNT][2] = {
        {"48656C6C6F2065766572796F6E6521", "Hello everyone!"},
    };

    for (int i = 0; i < TESTCOUNT; i++) {
        char result[RESULTLENGTH];
        HexStringToCharString(result, RESULTLENGTH, tests[i][0]);
        printResult(FUNCNAME, i, result, tests[i][1], success, failure);
    }
}
#undef TESTCOUNT
#undef RESULTLENGTH
