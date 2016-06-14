#include <string.h>

#include "common.h"
#include "hex.h"
#include "xor.h"

char* FixedXor(char* dest, int length, const char* num1, const char* num2) {
    for (int i = 0; i < length && i < strlen(num1) && i < strlen(num2); ++i) {
        dest[i] = IntToHexChar(HexCharToInt(num1[i]) ^ HexCharToInt(num2[i]));

        if (i == length - 1) {
            dest[i] = '\0';
        }
        else if (i == strlen(num1) - 1 || i == strlen(num2) - 1) {
            dest[i + 1] = '\0';
        }
    }

    return dest;
}

char* SingleXor(char* dest, int length, const char* string, int key) {
    for (int i = 0; i < length && i < strlen(string); ++i) {
        dest[i] = string[i] ^ key;

        if (i == length - 1) {
            dest[i] = '\0';
        }
        else if (i == strlen(string) - 1) {
            dest[i + 1] = '\0';
        }
    }

    return dest;
}

int FindSingleXorKey(char* xorString, int length, const char* string) {

    // Get the character frequency and number of unique characters
    int count[255] = {0};
    int uniqueCharCount = 0;
    for (int i = 0; i < strlen(string); ++i) {
        count[string[i]] += 1;
        if (count[string[i]] == 1) {
            ++uniqueCharCount;
        }
    }

    // Make sorted list of most frequent characters
    char topChars[255] = {0};
    for (int i = 0; i < 255; i++) {
        for (int j = 0; j < 255; j++) {
            if (count[topChars[i]] < count[j]) {
                topChars[i] = j;
            }
        }

        if (count[topChars[i]] == 0) {
            break;
        }
        else {
            count[topChars[i]] = 0;
        }
    }

    for (int uniqueCharIter = 0; uniqueCharIter < uniqueCharCount; uniqueCharIter++) {
        for (int charFreqIter = 0; charFreqIter < strlen(CHARFREQ); charFreqIter++) {
            int xorKey = CHARFREQ[charFreqIter] ^ topChars[uniqueCharIter];
            SingleXor(xorString, length, string, xorKey);
            if (
                    xorKey != 0
                    && strlen(xorString) == strlen(string)
                    && isLikelyEnglish(xorString)
               ) {
                return xorKey;
            }
        }
    }

    return 0;
}

char* RepeatingKeyXor(char* dest, int length, char* source, char* key) {
    char tempChar;
    char tempString[5];
    dest = "";

    for (int i = 0; i < length && i < strlen(source); ++i) {
        tempChar = source[i];
        //strncpy(dest, SingleXor(tempString, tempChar, key[i % strlen(key)])length - strlen(dest))
    }

    return dest;
}
