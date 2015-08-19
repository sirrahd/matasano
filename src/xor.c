#include <string.h>
#include <stdlib.h>
#include <stdio.h>

#include "hex.h"
#include "xor.h"

// Assumes equal-length numbers
char * FixedXor(char * dest, const char * num1, const char * num2)
{
    int length = strlen(num1);

    dest[length] = '\0';
    
    for (int i = 0; i < length; i++)
    {
        dest[i] = IntToHexChar(HexCharToInt(num1[i]) ^ HexCharToInt(num2[i]));
    }
    
    return dest;
}

char * SingleXor(char * dest, const char * string, int num)
{
    for (int i = 0; i < strlen(string); i++)
    {
        dest[i] = string[i] ^ num;
    }

    return dest;
}
    
