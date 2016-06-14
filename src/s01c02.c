#include <stdio.h>
#include "xor.h"

#define MAXLENGTH 256
void main(int argc, char * argv[])
{
    char * string;
    char * key;
    char result[MAXLENGTH];

    if (argc > 2)
    {
        string = argv[1];
        key = argv[2];
    }
    else
    {
        string = "1c0111001f010100061a024b53535009181c";
        key = "686974207468652062756c6c277320657965";
        printf("Using\nString: %s\nKey: %s\n", string, key);
    }

    printf("%s\n", FixedXor(result, MAXLENGTH, string, key));
}
#undef MAXLENGTH
