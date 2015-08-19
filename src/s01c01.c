#include <stdio.h>
#include "base64.h"

void main(int argc, char * argv[])
{
    char * hex;
    char result[100] = {'\0'};

    if (argc > 1)
    {
        hex = argv[1];
    }
    else
    {
        hex = "49276d206b696c6c696e6720796f757220627261696e206c696b65206120706f69736f6e6f7573206d757368726f6f6d";
        printf("Using %s\n", hex);
    }

    printf("%s\n", HexStringToB64String(result, hex));
}
