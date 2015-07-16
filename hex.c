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
