#include <stdio.h>

#include "hex.h"
#include "xor.h"

void main(int argc, char * argv[])
{
    if (argc <= 1)
    {
        printf("Provide string(s) to process\n");
        return;
    }

    for (int i = 1; i < argc; i++)
    {
        int keys[100] = {0};
        char string[100] = {'\0'};

        HexStringToCharString(string, argv[i]);
        findKeys(keys, 100, string);

        for (int keyIter = 0; keyIter < 100; keyIter++)
        {
            if (keys[keyIter] != 0)
            {
                char result[100] = {'\0'};
                SingleXor(result, string, keys[keyIter]);
                printf("String found on line %i with key %i (%s):\n%s\n", i, keys[keyIter], argv[i], result);
            }
            else
            {
                break;
            }
        }
    }
}
