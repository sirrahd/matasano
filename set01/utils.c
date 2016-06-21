#include <ctype.h>
#include <stdio.h>
#include <string.h>

#include "string.h"

const unsigned char CHARFREQ[] = " eEtTaAoOnNiIsShHrRlLdDuUcCmMwWyYfFgGpPbBvVkKjJxXqQzZ";

int isLikelyEnglish(const String* string) {
    int count = 0;
    for (int i = 0; i < string->length; ++i) {
        if (!isprint(string->data[i]) && !isspace(string->data[i])) {
            return 0;
        }

        if (isalnum(string->data[i]) || isspace(string->data[i])) {
            ++count;
        }
    }

    if ((float)count / (float)string->length > 0.9)
        return 1;
    else
        return 0;
}

unsigned char FindSingleByteXorCypher(const String* src) {
    for (int i = 0; i < 256; ++i) {
        char keyChar[2];
        snprintf(keyChar, 2, "%c", i);
        String* key = rawDecode(keyChar);
        String* decodedString = copyString(src);
        xorString(decodedString, key);

        if (isLikelyEnglish(decodedString)) {
            return i;
        }

        deleteString(key);
        deleteString(decodedString);
    }

    return 0;
}

int hammingDistance(String* s1, String* s2) {
    return 0;
}
