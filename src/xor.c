#include <string.h>
#include <stdlib.h>

#include "hex.h"
#include "xor.h"

// Assumes equal-length numbers
char * FixedXor(const char * num1, const char * num2)
{
    int length = strlen(num1);
    char * result = malloc(sizeof(char) * (length + 1));
    
    result[length] = '\0';
    
    for (int i = 0; i < length; i++)
    {
        result[i] = IntToHexChar(HexCharToInt(num1[i]) ^ HexCharToInt(num2[i]));
    }
    
    return result;
}
