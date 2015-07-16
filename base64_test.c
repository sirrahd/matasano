#include "test.h"
#include "base64.h"

void TestIntToB64Char(int * success, int * failure)
{
    int i;
    int test[11] = {0, 15, 25, 26, 47, 51, 52, 55, 61, 62, 63};
    char result[11] = { 'A', 'P', 'Z', 'a', 'v', 'z',
                        '0', '3', '9', '+', '/'};
    
    for (i = 0; i < 11; i++)
    {
        printf("IntToB64Char(\"%i\")...", test[i]);
        if (IntToB64Char(test[i]) == result[i])
        {
            printf("PASS\n");
            (*success)++;
        }
        else
        {
            printf("FAIL (%c != %c)", IntToB64Char(test[i]), result[i]);
            (*failure)++;
        }
    }
}

void TestIntToB64String(int * success, int * failure)
{
    int i;
    int test[3] = { 1170, 1901, 518 };
    char result[3][3] = { "SS", "dt", "IG" };
    
    for (i = 0; i < 3; i++)
    {
        printf("IntToB64String(\"%i\")...", test[i]);
        if (strcmp(IntToB64String(test[i]), result[i]) == 0)
        {
            printf("PASS\n");
            (*success)++;
        }
        else
        {
            printf("FAIL (%s)\n", test[i]);
            (*failure)++;
        }
    }
}

void TestHexCharToB64String(int * success, int * failure)
{
    printf("HexCharToB64String()...");
    char testHex[] = "49276d206b696c6c696e6720796f757220627261696e206c696b65206120706f69736f6e6f7573206d757368726f6f6d";
    char testResult[] = "SSdtIGtpbGxpbmcgeW91ciBicmFpbiBsaWtlIGEgcG9pc29ub3VzIG11c2hyb29t";
    
    if (strcmp(testResult, HexCharToB64String(testHex)) == 0)
    {
        printf("PASS\n");
        (*success)++;
    }
    else
    {
        printf("FAIL (%s != %s)\n", HexCharToB64String(testHex), "SSdtIGtpbGxpbmcgeW91ciBicmFpbiBsaWtlIGEgcG9pc29ub3VzIG11c2hyb29t");
        (*failure)++;
    }
}
