#include <string.h>
#include <math.h>
#include <stdlib.h>
#include <stdio.h>

#include "common.h"
#include "hex.h"

int HexCharToInt(const char hex) {
    if ('0' <= hex && '9' >= hex) {
        return hex - '0';
    }
    else if ('a' <= hex && 'f' >= hex) {
        return hex - 'a' + 10;
    }
    else if ('A' <= hex && 'F' >= hex) {
        return hex - 'A' + 10;
    }
    else {
        return '\0';
    }
}

int HexStringToInt(const char* hex) {
    int total = 0;

    for (int i = 0; i < strlen(hex); ++i) {
        total += HexCharToInt(hex[i]) * pow(16, strlen(hex) - 1 - i);
    }

    return total;
}

char IntToHexChar(int src) {
    if (src <= 9) {
        return (char)(48 + src);
    }
    else if (src >= 10 && src <= 15) {
        return (char)(87 + src);
    }
    else {
        return '\0';
    }
}

char* IntToHexString(char* dest, int length, int src) {
    for (int i = 0; i < length && src > 0; ++i) {
        dest[i] = IntToHexChar(src % 16);
        src /= 16;

        if (i == length - 1) {
            dest[i] = '\0';
        }
        else if (src == 0) {
            dest[i + 1] = '\0';
        }
    }

    return strrev(dest);
}

char* HexStringToCharString(char* dest, int length, const char* src) {
    for (int i = 0; i < length && i < strlen(src) / 2; ++i) {
        char hexChar[3];
        snprintf(hexChar, 3, "%c%c", src[i * 2], src[i * 2 + 1]);
        dest[i] = HexStringToInt(hexChar);

        if (i == length - 1 || i == strlen(src)) {
            dest[i] = '\0';
        }
    }

    return dest;
}
