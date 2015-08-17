#include <string.h>
#include <math.h>
#include <stdlib.h>

#include "hex.h"
#include "base64.h"

char IntToB64Char(int num)
{
    if (num >= 0 && num <= 25)
    {
        return 'A' + num;
    }
    else if (num >= 26 && num <= 51)
    {
        return 'a' + num - 26;
    }
    else if (num >= 52 && num <= 61)
    {
        return '0' + num - 52;
    }
    else if (num == 62)
    {
        return '+';
    }
    else if (num == 63)
    {
        return '/';
    }
}

char * IntToB64String(int num)
{
    int length, i;
    
    length = (int)(log(num) / log(64)) + 1;
    
    char * retVal = malloc(sizeof(char) * (length));
    
    for (i = 1; i <= length; i++)
    {
        retVal[length - i] = IntToB64Char(num % (int)(pow(64, i)));
        num /= (int)pow(64, i);
    }
    
    return retVal;
}

char * HexCharToB64String(const char * hex)
{
    int length = strlen(hex);
    char * retVal = malloc(sizeof(char) * (length * 2 / 3) + 1); 
    char tempString[4] = "\0";

    for (int i = 0; i < length; i += 3)
    {
        for (int j = 0; i + j < length && j < 3; j++)
        {
            tempString[j] = hex[i + j];
        }
        strcat(retVal, IntToB64String(HexStringToInt(tempString)));
    }
    
    return retVal;
}
