#include <stdlib.h>
#include <string.h>

#include "encodings.h"
#include "errors.h"
#include "string.h"

String* createString() {
    String* s = malloc(sizeof(String));
    s->length = 0;
    s->data = 0;
    s->hexEncoded = 0;
    s->b64Encoded = 0;

    return s;
}

String* clearString(String* s) {
    if (s->hexEncoded) {
        free(s->hexEncoded);
        s->hexEncoded = 0;
    }
    if (s->b64Encoded) {
        free(s->b64Encoded);
        s->b64Encoded = 0;
    }

    return s;
}

void deleteString(String* s) {
    free(s->data);
    if (s->hexEncoded) {
        free(s->hexEncoded);
    }
    if (s->b64Encoded) {
        free(s->b64Encoded);
    }
    free(s);
}

String* copyString(const String* s) {
    String* copy = createString();
    copy->data = malloc(sizeof(char) * s->length);
    copy->data = memcpy(copy->data, s->data, sizeof(char) * s->length);
    copy->length = s->length;

    return copy;
}

String* rawDecode(const char* src) {
    String* s = createString();
    s->length = strlen(src);
    s->data = malloc(sizeof(char) * s->length);
    memcpy(s->data, src, s->length);

    return s;
}

String* hexDecode(const char* src) {
    if (strlen(src) % 2 > 0) { errInvalidHex(); }

    String* s = createString();
    s->length = strlen(src) / 2;
    s->data = malloc(sizeof(char) * (s->length + 1));
    for (int i = 0; i < s->length; ++i) {
        s->data[i] = hexPairToChar(src + i * 2);
    }
    s->data[s->length] = '\0';

    return s;
}

String* b64Decode(const char * src) {
    if (strlen(src) % 4 > 0) { errInvalidB64(); }

    String* s = createString();
    s->length = strlen(src) * 3 / 4;
    s->data = malloc(sizeof(char) * (s->length + 1));
    for (int i = 0; i < s->length / 3; ++i) {
        int length = b64QuadToCharTriad(s->data + i * 3, src + i * 4);
        if (length < 4) {
            s->length -= 4 - length;
        }
    }
    s->data[s->length] = '\0';

    return s;
}

const char* hexEncode(String* s) {
    if (s->hexEncoded) {
        return s->hexEncoded;
    }

    s->hexEncoded = malloc(sizeof(char) * (s->length * 2 + 1));

    strcpy(s->hexEncoded, "");

    for (int i = 0; i < s->length; ++i) {
        intToHexPair(s->hexEncoded + i * 2, s, i);
    }

    return s->hexEncoded;
}

const char* b64Encode(String* s) {
    if (s->b64Encoded) {
        return s->b64Encoded;
    }

    s->b64Encoded = malloc(sizeof(char) * (s->length * 4 / 3 + 1));

    int triCount = strlen(s->data) / 3;
    if (strlen(s->data) % 3) {
        ++triCount;
    }

    strcpy(s->b64Encoded, "");

    for (int i = 0; i < triCount; ++i) {
        charTriadToB64Quad(s->b64Encoded + i * 4, s, i * 3);
    }

    for (int i = 0; i < 2; ++i) {
        if (s->b64Encoded[strlen(s->b64Encoded) - 1 - i] == 'A') {
            s->b64Encoded[strlen(s->b64Encoded) - 1- i] = '=';
        }
    }

    return s->b64Encoded;
}

String* xorString(String* s1, const String* key) {
    clearString(s1);
    for (int i = 0, k = 0; i < s1->length; ++i) {
        s1->data[i] = s1->data[i] ^ key->data[k];

        if (k < key->length - 1) {
            ++k;
        }
        else {
            k = 0;
        }
    }

    return s1;
}
