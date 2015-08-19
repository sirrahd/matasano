#include <stdio.h>
#include <ctype.h>
#include <string.h>
#include <ctype.h>
#include "hex.h"
#include "xor.h"

char CHARFREQ[] = "eEtTaAoOnNiIsShHrRlLdDuUcCmMwWyYfFgGpPbBvVkKjJxXqQzZ";
int * findKeys(int dest[], int tries, const char * hexString);
int isPrintable(const char * string);

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
        char result[100] = {'\0'};
        SingleXor(result, string, keys[i]);
        if (isPrintable(result) && keys[i] != 0)
        {
            printf("%i: %s\n", keys[i], result);
        }
    }

    return;
}

int isPrintable(const char * string)
{
    for (int i = 0; i < strlen(string); i++)
    {
        if (!isprint(string[i]))
        {
            return 0;
        }
    }

    return 1;
}

int * findKeys(int dest[], int tries, const char * string)
{
    int count[255] = {0};
    
    for (int i = 0; i < strlen(string); i++)
    {
        count[string[i]] += 1;
    }   

    for (int i = 0; i < tries / 10; i++)
    {
        dest[i] = 0;
        for (int j = 0; j < 255; j++)
        {
            if (count[dest[i]] < count[j])
            {
                dest[i] = j;
            }
        }
        count[dest[i]] = 0;
        
        for (int k = 0; k < 10; k++)
        {
            dest[i] = CHARFREQ[k] ^ dest[i];
        }
    }

    return dest;
}
