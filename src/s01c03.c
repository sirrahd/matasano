#include <stdio.h>

#include "common.h"
#include "hex.h"
#include "xor.h"

#define MAXLENGTH 256
int main(int argc, char* argv[]) {
    char* hexString;
    if (argc <= 1)
    {
        hexString = "1b37373331363f78151b7f2b783431333d78397828372d363c78373e783a393b3736";
        printf("Using %s\n", hexString);
    }
    else
    {
        hexString = argv[1];
    }

    char string[MAXLENGTH];
    HexStringToCharString(string, MAXLENGTH, hexString);

    char xorString[MAXLENGTH];
    int xorKey = FindSingleXorKey(xorString, MAXLENGTH, string);

    if (xorKey) {
        printf("Key: %i\nMessage: %s\n", xorKey, xorString);
    }
    else {
        printf("Key not found.\n");
    }

    return 0;
}
#undef MAXLENGTH
