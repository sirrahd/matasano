#include <ctype.h>
#include <string.h>

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

int isLikelyEnglish(const char * string)
{
    int count = 0;
    for (int i = 0; i < strlen(string); i++)
    {
        if (isalnum(string[i]) || isspace(string[i]))
        {
            count++;
        }
    }

    if ((float)count / (float)strlen(string) > 0.9)
        return 1;
    else
        return 0;
}

int isUniqueInIntArray(const int * array, int size, int value)
{
    for (int i = 0; i < size; i++)
    {
        if (array[i] == value)
        {
            return 0;
        }
    }

    return 1;
}
