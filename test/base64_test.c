#include "test.h"
#include "base64.h"

void TestIntToB64Char(int * success, int * failure)
{
    const char FUNCNAME[] = "IntToB64Char";
    const char * tests[11][2] = 
    {
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
    
    for (int i = 0; i < 11; i++)
    {
        char result[100];
        snprintf(result, 100, "%c", IntToB64Char(atoi(tests[i][0])));
        printResult(FUNCNAME, tests[i], result, success, failure);
    }
}

void TestIntToB64String(int * success, int * failure)
{
    const char FUNCNAME[] = "IntToB64String";
    const char * tests[3][2] = 
    {
        {"1170", "SS"},
        {"1901", "dt"},
        {"518", "IG"},
    };
    
    for (int i = 0; i < 3; i++)
    {
        char result[100];
        snprintf(result, 100, "%s", IntToB64String(atoi(tests[i][0])));
        printResult(FUNCNAME, tests[i], result, success, failure);
    }
}

void TestHexCharToB64String(int * success, int * failure)
{
    const char FUNCNAME[] = "HexCharToB64String";
    const char * tests[1][2] =
    {
        {"49276d206b696c6c696e6720796f757220627261696e206c696b65206120706f69736f6e6f7573206d757368726f6f6d", "SSdtIGtpbGxpbmcgeW91ciBicmFpbiBsaWtlIGEgcG9pc29ub3VzIG11c2hyb29t"}
    };

    for (int i = 0; i < 1; i++)
    {
        char result[100];
        snprintf(result, 100, "%s", HexCharToB64String(tests[i][0]));
        printResult(FUNCNAME, tests[i], result, success, failure);
    }
}
