#include <stdio.h>
#include <assert.h>
#include <string.h>

// hex.c
void TestHexCharToInt(int * success, int * failure);
void TestHexStringToInt(int * success, int * failure);

// base64.c
void TestIntToB64Char(int * success, int * failure);
void TestIntToB64String(int * success, int * failure);
void TestHexCharToB64String(int * success, int * failure);
