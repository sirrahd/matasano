#include "test.h"
#include "hex.h"

void TestHexCharToInt(int * success, int * failure)
{
    const char FUNCNAME[] = "HexCharToInt";
    const char * tests[16][2] = 
    {
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

    for (int i = 0; i < 16; i++)
    {
        char result[100];
        snprintf(result, 100, "%i", HexCharToInt(tests[i][0][0]));
        printResult(FUNCNAME, tests[i], result, success, failure);
    }
}


void TestHexStringToInt(int * success, int * failure)
{    
    const char FUNCNAME[] = "HexStringToInt";
    const char * tests[6][2] =
    {
        {"492", "1170"},
        {"76d", "1901"},
        {"206b69", "2124649"},
        {"1", "1"},
        {"12", "18"},
        {"1234", "4660"},
    };
    
    for (int i = 0; i < 6; i++)
    {
        char result[100];
        snprintf(result, 100, "%i", HexStringToInt(tests[i][0]));
        printResult(FUNCNAME, tests[i], result, success, failure);
    }
}

void TestIntToHexChar(int * success, int * failure)
{
    const char FUNCNAME[] = "IntToHexChar";
    const char * tests[4][2] = 
    {
        {"0", "0"},
        {"9", "9"},
        {"10", "a"},
        {"15", "f"},
    };

    for (int i = 0; i < 4; i++)
    {
        char result[100];
        snprintf(result, 100, "%c", IntToHexChar(atoi(tests[i][0])));
        printResult(FUNCNAME, tests[i], result, success, failure);
    }
}

void TestIntToHexString(int * success, int * failure)
{
    const char FUNCNAME[] = "IntToHexString";
    const char * tests[3][2] = 
    {
        {"100", "64"},
        {"1901", "76d"},
        {"518", "206"},
    };
    
    for (int i = 0; i < 3; i++)
    {
        char result[100];
        snprintf(result, 100, "%s", IntToHexString(atoi(tests[i][0])));
        printResult(FUNCNAME, tests[i], result, success, failure);
    }
}
