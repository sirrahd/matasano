#include <string.h>
#include <math.h>

int HexCharToInt(char hex)
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

int HexStringToInt(char * hex)
{
    int i, total;
    for (i = 0, total = 0; i < strlen(hex); i++)
    {
        total += HexCharToInt(hex[i]) * pow(16, strlen(hex) - 1 - i);
    }
    
    return total;
}

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
    return "ba";
}
