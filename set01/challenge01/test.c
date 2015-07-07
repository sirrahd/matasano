#include <stdio.h>
#include <assert.h>
#include "HexToB64.h"

void TestHexCharToInt(int * success, int * failure)
{
    int i;
    char test[22] =
    {
        'a', 'b', 'c', 'd', 'e', 'f',
        'A', 'B', 'C', 'D', 'E', 'F',
        '0', '1', '2', '3', '4', '5',
        '6', '7', '8', '9'
    };
    int expected[22] =
    {
        10, 11, 12, 13, 14, 15,
        10, 11, 12, 13, 14, 15,
        0, 1, 2, 3, 4, 5, 6, 7, 8, 9
    };
    
    for (i = 0; i < 22; i++)
    {
        printf("HexCharToInt(\"%c\")...", test[i]);
        if (HexCharToInt(test[i]) == expected[i])
        {
            printf("PASS\n");
            (*success)++;
        }
        else
        {
            printf("FAIL (%i != %i)\n", HexCharToInt(test[i]), expected[i]);
            (*failure)++;
        }
    }
}

void TestHexStringToInt(int * success, int * failure)
{    
    int i;
    char * hexVals[6] = {"492", "76d", "206b69", "1", "12", "1234"};
    int intVals[6] = {1170, 1901, 2124649, 1, 18, 4660};

    
    for (i = 0; i < 6; i++)
    {
        printf("HexStringToInt(\"%s\")...", hexVals[i]);
        if (HexStringToInt(hexVals[i]) == intVals[i])
        {
            printf("PASS\n");
            (*success)++;
        }
        else
        {
            printf("Fail (%i != %i)\n", HexStringToInt(hexVals[i]),
                    intVals[i]);
            (*failure)++;
        }
    }
}

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
    int test[11] = {0, 15, 25, 26, 47, 51, 52, 55, 61, 62, 63};
    char result[11] = { 'A', 'P', 'Z', 'a', 'v', 'z',
                        '0', '3', '9', '+', '/'};
    
    for (i = 0; i < 11; i++)
    {
        printf("IntToB64String(\"%i\")...", test[i]);
        if (IntToB64String(test[i]) == result[i])
        {
            printf("PASS\n");
            (*success)++;
        }
        else
        {
            printf("FAIL (%s != %s)", IntToB64String(test[i]), result[i]);
            (*failure)++;
        }
    }
}

int main()
{
    int success = 0, failure = 0;
    TestHexCharToInt(&success, &failure);
    TestHexStringToInt(&success, &failure);
    TestIntToB64Char(&success, &failure);
    printf("Tests completed: %i successes and %i failures\n",
            success, failure);
}
