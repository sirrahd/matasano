#include <math.h>

#include "errors.h"
#include "string.h"

char hexToChar(const char src) {
    if ('0' <= src && '9' >= src) {
        return src - '0';
    }
    else if ('a' <= src && 'f' >= src) {
        return src - 'a' + 10;
    }
    else if ('A' <= src && 'F' >= src) {
        return src - 'A' + 10;
    }
    else {
        errInvalidHex();
        return 0;
    }
}

char hexPairToChar(const char* src) {
    return hexToChar(src[0]) * 16 + hexToChar(src[1]);
}

char intToHex(int src) {
    if (src <= 9) {
        return (char)(48 + src);
    }
    else if (src >= 10 && src <= 15) {
        return (char)(87 + src);
    }
    else {
        errInvalidHex();
        return 0;
    }
}

char* intToHexPair(char* dest, const String* s, int index) {
    for (int i = 0; i < 2; ++i) {
        dest[i] = intToHex(s->data[index] / (int)pow(16, 1 - i) % 16);
    }
    dest[2] = '\0';

    return dest;
}

char intToB64(int src) {
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
        errUnknown();
        return 0;
    }
}

int b64ToInt(char src) {
    if (src >= 'A' && src <= 'Z') {
        return src - 'A';
    }
    else if (src >= 'a' && src <= 'z') {
        return src - 'a' + 26;
    }
    else if (src >= '0' && src <= '9') {
        return src - '0' + 52;
    }
    else if (src == '+') {
        return 62;
    }
    else if (src == '/') {
        return 63;
    }
    else if (src == '=') {
        return 0;
    }
    else {
        errUnknown();
        return 0;
    }
}

char* charTriadToB64Quad(char* dest, const String* s, int index) {
    int triLength = s->length - index > 3 ? 3 : s->length - index;

    int value = 0;
    for (int i = 0; i < 3; ++i) {
        value += s->data[index + i] * (int)pow(256, 2 - i);
    }

    for (int i = 0; i < 4; ++i) {
        dest[i] = intToB64(value / (int)pow(64, 3 - i) % 64);
    }
    dest[4] = '\0';

    return dest;
}

int b64QuadToCharTriad(char* dest, const char* src) {
    int length;
    for (length = 4; src[length - 1] == '='; --length);

    int value = 0;
    for (int i = 0; i < 4; ++i) {
        value += b64ToInt(src[i]) * pow(64, 3 - i);
    }

    for (int i = 0; i < 3; ++i) {
        dest[i] = value / (int)pow(256, 2 - i) % 256;
    }
    dest[length] = '\0';

    return length;
}
