#include <stdio.h>

#include "test.h"
#include "../src/hex.h"
#include "../src/xor.h"

#define TESTCOUNT 1
#define RESULTLENGTH 64
void TestFixedXor(int* success, int* failure) {
    const char FUNCNAME[] = "FixedXor";
    const char* tests[TESTCOUNT][3] = {
        {"1c0111001f010100061a024b53535009181c", "686974207468652062756c6c277320657965", "746865206b696420646f6e277420706c6179"},
    };

    for (int i = 0; i < TESTCOUNT; ++i)
    {
        char result[RESULTLENGTH];
        FixedXor(result, RESULTLENGTH, tests[i][0], tests[i][1]);
        printResult(FUNCNAME, i, result, tests[i][2], success, failure);
    }
}
#undef TESTCOUNT
#undef RESULTLENGTH

#define TESTCOUNT 1
#define RESULTLENGTH 128
void TestFindSingleXorKey(int* success, int* failure) {
    const char FUNCNAME[] = "FindSingleXorKey";
    const char* tests[TESTCOUNT][3] = {
        {"1b37373331363f78151b7f2b783431333d78397828372d363c78373e783a393b3736", "Cooking MC's like a pound of bacon", "88"}
    };

    for (int i = 0; i < TESTCOUNT; ++i) {
        char charString[RESULTLENGTH];
        char xorKey[RESULTLENGTH];
        char xorString[RESULTLENGTH];

        HexStringToCharString(charString, RESULTLENGTH, tests[i][0]);
        snprintf(xorKey, RESULTLENGTH, "%i", FindSingleXorKey(xorString, RESULTLENGTH, charString));
        printResult(FUNCNAME, i, xorString, tests[i][1], success, failure);
        printResult(FUNCNAME, i, xorKey, tests[i][2], success, failure);
    }
}
#undef TESTCOUNT
#undef RESULTLENGTH

void TestRepeatingKeyXor(int* success, int* failure) {
    const char FUNCNAME[] = "RepeatingKeyXor";
    const char* tests[2][2] = {
        {"Burning 'em, if you ain't quick and nimble", "0b3637272a2b2e63622c2e69692a23693a2a3c6324202d623d63343c2a26226324272765272"},
        {"I go crazy when I hear a cymbal", "a282b2f20430a652e2c652a3124333a653e2b2027630c692b20283165286326302e27282f"},
    };
}
