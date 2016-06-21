#include <stdio.h>
#include <stdlib.h>

void error(int code, char* string) {
    fprintf(stderr, "ERROR: (%i) %s\n", code, string);
    exit(code);
}

void errUnknown() {
    error(1, "An unknown error occurred");
}

void errInvalidHex() {
    error(2, "Invalid hex");
}

void errInvalidB64() {
    error(2, "Invalid Base64");
}

void errStringsNotEqual() {
    error(3, "Strings must be equal");
}

void errFileNotFound() {
    error(4, "File not found");
}
