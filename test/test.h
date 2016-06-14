#ifndef _TEST_H_
#define _TEST_H_

#include <stdio.h>
#include <stdlib.h>
#include <assert.h>
#include <string.h>

void printResult(const char* function, int testNumber, const char* result, const char* expectedResult, int* success, int* failure);

// hex_test.c
void TestHexCharToInt(int* success, int* failure);
void TestHexStringToInt(int* success, int* failure);
void TestIntToHexChar(int* success, int* failure);
void TestIntToHexString(int* success, int* failure);
void TestHexStringToCharString(int* success, int* failure);

// base64_test.c
void TestIntToB64Char(int* success, int* failure);
void TestIntToB64String(int* success, int* failure);
void TestHexStringToB64String(int* success, int* failure);

// xor_test.c
void TestFixedXor(int* success, int* failure);
void TestFindSingleXorKey(int* success, int* failure);

#endif
