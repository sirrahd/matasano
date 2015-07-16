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
