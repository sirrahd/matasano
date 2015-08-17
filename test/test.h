#include <stdio.h>
#include <stdlib.h>
#include <assert.h>
#include <string.h>

void printResult(const char * function, const char * test[2], const char * result, int * success, int * failure);

// hex_test.c
void TestHexCharToInt(int * success, int * failure);
void TestHexStringToInt(int * success, int * failure);
void TestIntToHexChar(int * success, int * failure);
void TestIntToHexString(int * success, int * failure);

// base64_test.c
void TestIntToB64Char(int * success, int * failure);
void TestIntToB64String(int * success, int * failure);
void TestHexCharToB64String(int * success, int * failure);

// xor_test.c
void TestFixedXor(int * success, int * failure);
