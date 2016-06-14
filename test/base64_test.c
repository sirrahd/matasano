#include "test.h"
#include "../src/base64.h"

#define TESTCOUNT 11
#define RESULTLENGTH 2
void TestIntToB64Char(int* success, int* failure) {
    const char FUNCNAME[] = "IntToB64Char";
    const char* tests[TESTCOUNT][2] = {
        {"0", "A"},
        {"15", "P"},
        {"25", "Z"},
        {"26", "a"},
        {"47", "v"},
        {"51", "z"},
        {"52", "0"},
        {"55", "3"},
        {"61", "9"},
        {"62", "+"},
        {"63", "/"},
    };

    for (int i = 0; i < RESULTLENGTH; ++i) {
        char result[TESTCOUNT];
        snprintf(result, TESTCOUNT, "%c", IntToB64Char(atoi(tests[i][0])));
        printResult(FUNCNAME, i, result, tests[i][1], success, failure);
    }
}
#undef TESTCOUNT
#undef RESULTLENGTH

#define TESTCOUNT 3
#define RESULTLENGTH 3
void TestIntToB64String(int* success, int* failure) {
    const char FUNCNAME[] = "IntToB64String";
    const char* tests[TESTCOUNT][2] = {
        {"1170", "SS"},
        {"1901", "dt"},
        {"518", "IG"},
    };

    for (int i = 0; i < TESTCOUNT; i++) {
        char result[RESULTLENGTH];
        IntToB64String(result, RESULTLENGTH, atoi(tests[i][0]));
        printResult(FUNCNAME, i, result, tests[i][1], success, failure);
    }
}
#undef TESTCOUNT
#undef RESULTLENGTH

#define TESTCOUNT 1
#define RESULTLENGTH 64
void TestHexStringToB64String(int* success, int* failure) {
    const char FUNCNAME[] = "HexStringToB64String";
    const char* tests[TESTCOUNT][2] = {
        {"49276d206b696c6c696e6720796f757220627261696e206c696b65206120706f69736f6e6f7573206d757368726f6f6d", "SSdtIGtpbGxpbmcgeW91ciBicmFpbiBsaWtlIGEgcG9pc29ub3VzIG11c2hyb29t"}
    };

    for (int i = 0; i < TESTCOUNT; i++) {
        char result[RESULTLENGTH];
        HexStringToB64String(result, RESULTLENGTH, tests[i][0]);
        printResult(FUNCNAME, i, result, tests[i][1], success, failure);
    }
}
