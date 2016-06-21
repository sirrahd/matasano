#include <stdio.h>
#include <string.h>

#include "errors.h"
#include "string.h"
#include "utils.h"

int challenge01() {
    String* s = hexDecode("49276d206b696c6c696e6720796f757220627261696e206c696b65206120706f69736f6e6f7573206d757368726f6f6d");

    int result = 0 == strcmp(b64Encode(s), "SSdtIGtpbGxpbmcgeW91ciBicmFpbiBsaWtlIGEgcG9pc29ub3VzIG11c2hyb29t");

    deleteString(s);

    return result;
}

int challenge02() {
    String* s1 = hexDecode("1c0111001f010100061a024b53535009181c");
    String* s2 = hexDecode("686974207468652062756c6c277320657965");
    xorString(s1, s2);

    int result = 0 == strcmp(hexEncode(s1), "746865206b696420646f6e277420706c6179");

    deleteString(s1);
    deleteString(s2);

    return result;
}

int challenge03() {
    String* e = hexDecode("1b37373331363f78151b7f2b783431333d78397828372d363c78373e783a393b3736");
    //e = hexDecode("")

    unsigned char xorKey = FindSingleByteXorCypher(e);
    deleteString(e);

    return xorKey == 88;
}

int challenge04() {
    FILE* file = fopen("share/4.txt", "r");

    if (!file) {
        errFileNotFound();
    }

    int hitCount = 0;
    char line[256];
    while (fgets(line, 256, file) != NULL) {
        if (line[strlen(line) - 1] == '\n') {
            line[strlen(line) - 1] = '\0';
        }

        String* source = hexDecode(line);
        unsigned char xorKey = FindSingleByteXorCypher(source);

        if (xorKey) {
            ++hitCount;
        }
    }

    return hitCount == 1;
}

int challenge05() {
    String* line1 = rawDecode("Burning 'em, if you ain't quick and nimble");
    String* line2 = rawDecode("I go crazy when I hear a cymbal");
    String* key = rawDecode("ICE");

    xorString(line1, key);
    xorString(line2, key);

    int result =
        strcmp(hexEncode(line1), "0b3637272a2b2e63622c2e69692a23693a2a3c6324202d623d63343c2a26226324272765272") &&
        strcmp(hexEncode(line2), "a282b2f20430a652e2c652a3124333a653e2b2027630c692b20283165286326302e27282f");

    deleteString(line1);
    deleteString(line2);
    deleteString(key);

    return result;
}

int challenge06() {
    return 0;
}

int runTests() {
    printf("Challenge 1: %s", challenge01() ? "PASS\n" : "FAIL\n");
    printf("Challenge 2: %s", challenge02() ? "PASS\n" : "FAIL\n");
    printf("Challenge 3: %s", challenge03() ? "PASS\n" : "FAIL\n");
    printf("Challenge 4: %s", challenge04() ? "PASS\n" : "FAIL\n");
    printf("Challenge 5: %s", challenge05() ? "PASS\n" : "FAIL\n");
    printf("Challenge 6: %s", challenge06() ? "PASS\n" : "FAIL\n");

    return 0;
}

int main(int argc, char* argv[]) {
    runTests();

    return 0;
}
