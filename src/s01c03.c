#include <stdio.h>

#include "common.h"
#include "hex.h"
#include "xor.h"

void main(int argc, char * argv[])
{
    char * hexString;
    int keys[100] = {0};
    char string[100] = {'\0'};

    if (argc <= 1)
    {
        hexString = "1b37373331363f78151b7f2b783431333d78397828372d363c78373e783a393b3736";
        printf("Using %s\n", hexString);
    }
    else
    {
        hexString = argv[1];
    }

    HexStringToCharString(string, hexString);

    findKeys(keys, 100, string);

    for (int i = 0; i < 100; i++)
    {
        if (keys[i] != 0)
        {
            char result[100] = {'\0'};
            SingleXor(result, string, keys[i]);
            printf("%i: %s\n", keys[i], result);
        }
        else
        {
            break;
        }
    }
}

