#include <string.h>
#include <stdlib.h>
#include <stdio.h>

#include "common.h"
#include "hex.h"
#include "xor.h"

char CHARFREQ[] = " eEtTaAoOnNiIsShHrRlLdDuUcCmMwWyYfFgGpPbBvVkKjJxXqQzZ";

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

int * findKeys(int * dest, int tries, const char * string)
{
    int count[255] = {0};
    int uniqueCharCount = 0;
    char topChars[255] = {0};
    int uniqueCharIter = 0;
    int charFreqIter = 0;

    // Get the character frequency and number of unique characters
    for (int i = 0; i < strlen(string); i++)
    {
        count[string[i]] += 1;
        if (count[string[i]] == 1)
        {
            uniqueCharCount++;
        }
    }

    // Make sorted list of most frequent characters
    for (int i = 0; i < 255; i++)
    {
        for (int j = 0; j < 255; j++)
        {
            if (count[topChars[i]] < count[j])
            {
                topChars[i] = j;
            }
        }

        if (count[topChars[i]] == 0)
        {
            break;
        }
        else
        {
            count[topChars[i]] = 0;
        }
    }

    for (int hits = 0, uniqueCharIter = 0; uniqueCharIter < uniqueCharCount && hits < tries; uniqueCharIter++)
    {
        for (charFreqIter = 0; charFreqIter < strlen(CHARFREQ); charFreqIter++)
        {
            int xorKey = CHARFREQ[charFreqIter] ^ topChars[uniqueCharIter];
            char xorString[100] = {'\0'};
            SingleXor(xorString, string, xorKey);
            if (
                    isPrintable(xorString)
                    && xorKey != 0
                    && strlen(xorString) == strlen(string)
                    && isLikelyEnglish(xorString)
                    && isUniqueInIntArray(dest, tries, xorKey)
               )
            {
                dest[hits] = xorKey;
                hits++;
                break;
            }
        }
    }

    return dest;
}
