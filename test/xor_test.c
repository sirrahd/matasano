#include "test.h"
#include "xor.h"

void TestFixedXor(int * success, int * failure)
{
    const char FUNCNAME[] = "FixedXor";
    const char * tests[1][2] = 
    {
        {"1c0111001f010100061a024b53535009181c", "746865206b696420646f6e277420706c6179"},
    };
    const char * keys[1] = 
    {
        "686974207468652062756c6c277320657965",
    };
    
    for (int i = 0; i < 1; i++)
    {
        char result[100];
        snprintf(result, 100, "%s", FixedXor(tests[i][0], keys[i]));
        printResult(FUNCNAME, tests[i], result, success, failure);
    }
}
