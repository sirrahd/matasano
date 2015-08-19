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

char * IntToB64String(char * dest, int num)
{
    int length = (int)(log(num) / log(64)) + 1;
    dest[length] = '\0';
    
    for (int i = 1; i <= length; i++)
    {
        dest[length - i] = IntToB64Char(num % (int)(pow(64, i)));
        num /= (int)pow(64, i);
    }
    
    return dest;
}

char * HexStringToB64String(char * dest, const char * hex)
{
    int length = strlen(hex);
    char hexSegment[4] = {'\0'};
    char b64Segment[3] = {'\0'};
    dest[0] = '\0';

    for (int i = 0; i < length; i += 3)
    {
        char hexSegment[4] = {'\0'};
        for (int j = 0; i + j < length && j < 3; j++)
        {
            hexSegment[j] = hex[i + j];
        }
        strcat(dest, IntToB64String(b64Segment, HexStringToInt(hexSegment)));
    }
    
    return dest;
}
