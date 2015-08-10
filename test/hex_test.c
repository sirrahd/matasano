#include "test.h"
#include "hex.h"

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

void TestIntToHexChar(int * success, int * failure)
{
    int i;
    int test[116] = {0, 1, 2, 3, 4, 5, 6, 7, 8, 9,
                    10, 11, 12, 13, 14, 15};
    char result[16] = { '0', '1', '2', '3', '4', '5',
                        '6', '7', '8', '9', 'a', 'b',
                        'c', 'd', 'e', 'f'};
    
    for (i = 0; i < 11; i++)
    {
        printf("IntToHexChar(\"%i\")...", test[i]);
        if (IntToHexChar(test[i]) == result[i])
        {
            printf("PASS\n");
            (*success)++;
        }
        else
        {
            printf("FAIL (%c != %c)\n", IntToHexChar(test[i]), result[i]);
            (*failure)++;
        }
    }
}

void TestIntToHexString(int * success, int * failure)
{
    int i;
    int test[3] = { 100, 1901, 518 };
    char result[3][3] = { "64", "dt", "IG" };
    
    for (i = 0; i < 3; i++)
    {
        printf("IntToB64String(\"%i\")...", test[i]);
        if (strcmp(IntToHexString(test[i]), result[i]) == 0)
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
