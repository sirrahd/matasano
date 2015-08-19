#include <string.h>
#include <math.h>
#include <stdlib.h>
#include <stdio.h>

int HexCharToInt(const char hex)
{
    if ('0' <= hex && '9' >= hex)
    {
        return hex - '0';
    }
    
    if ('a' <= hex && 'f' >= hex)
    {
        return hex - 'a' + 10;
    }
    
    if ('A' <= hex && 'F' >= hex)
    {
        return hex - 'A' + 10;
    }
}

int HexStringToInt(const char * hex)
{
    int i, total;
    for (i = 0, total = 0; i < strlen(hex); i++)
    {
        total += HexCharToInt(hex[i]) * pow(16, strlen(hex) - 1 - i);
    }
    
    return total;
}

char IntToHexChar(int num)
{
    if (num <= 9)
    {
        return (char)(48 + num);
    }
    else if (num >= 10 && num <= 15)
    {
        return (char)(87 + num);
    }
    else
    {
        return '!';
    }
}

char * IntToHexString(char * dest, int num)
{
    int length = (int)(log(num) / log(16)) + 1;
    dest[length] = '\0';
    
    for (int i = 1; i <= length; i++)
    {
        dest[length - i] = IntToHexChar(num % 16);
        num /= 16;
    }
    
    return dest;
}

char * HexStringToCharString(char * dest, const char * hex)
{
    strncpy(dest, "\0", 1);
    for (int i = 0; i < strlen(hex) - 1; i += 2)
    {
        char hexChar[3];
        char stringChar[2];
        snprintf(hexChar, 3, "%c%c", hex[i], hex[i+1]);
        stringChar[0] = HexStringToInt(hexChar);
        strncat(dest, stringChar, 1);
    }

    return dest;
}
