#include <string.h>
#include <math.h>
#include <stdlib.h>

#include "base64.h"
#include "common.h"
#include "hex.h"

char* buildHexSegment(char* dest, int segmentSize, int index, const char* src) {
    for (int i = 0; i < segmentSize && i + index < strlen(src); ++i) {
        dest[i] = src[i + index];

        if (i == segmentSize || i + index < strlen(src) - 1) {
            dest[i + 1] = '\0';
        }
    }

    return dest;
}

char IntToB64Char(int src) {
    if (src >= 0 && src <= 25) {
        return 'A' + src;
    }
    else if (src >= 26 && src <= 51) {
        return 'a' + src - 26;
    }
    else if (src >= 52 && src <= 61) {
        return '0' + src - 52;
    }
    else if (src == 62) {
        return '+';
    }
    else if (src == 63) {
        return '/';
    }
    else {
        return '\0';
    }
}

char* IntToB64String(char* dest, int length, int src) {
    for (int i = 0; i < length && src > 0; ++i) {
        dest[i] = IntToB64Char(src % (int)(pow(64, i + 1)));
        src /= (int)pow(64, i + 1);

        if (i == length - 1) {
            dest[i] = '\0';
        }
        else if (src == 0) {
            dest[i + 1] = '\0';
        }
    }

    return strrev(dest);
}

char* HexStringToB64String(char* dest, int length, const char* src) {
    strcpy(dest, "");

    for (int i = 0; i < length && i < strlen(src) / 3; ++i) {
        char hexSegment[4];
        char b64Segment[3];
        buildHexSegment(hexSegment, 3, i * 3, src);
        strncat(dest, IntToB64String(b64Segment, 3, HexStringToInt(hexSegment)), length - strlen(dest));
    }

    return dest;
}
