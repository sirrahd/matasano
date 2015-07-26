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

char IntToHexChar(int num)
{
    if (num <= 9)
    {
        return num;
    }
    else
    {
        return (char)(87 + num);
    }
}

char * IntToHexString(int num);
{
    int length = (int)(log(num) / log(16)) + 1;
    
    char * retVal = malloc(sizeof(char) * (length + 1));
    retVal[length = '\0';
    
    for (int i = 1; i <= length; i++)
    {
        retVal[length - i] = IntToHexChar(num % (int)(pow(16, i)));
        num /= (int)pow(16, i);
    }
    
    return retVal;
}
