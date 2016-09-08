#pragma once

#include "string.h"

char hexPairToChar(const char* src);
int b64QuadToCharTriad(char* dest, const char* src);
char* intToHexPair(char* dest, const String* s, int index);
char* charTriadToB64Quad(char* dest, const String* s, int index);
