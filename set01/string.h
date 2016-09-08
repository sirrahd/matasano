#pragma once

typedef struct {
    unsigned char* data;
    unsigned int length;
    char* hexEncoded;
    char* b64Encoded;
} String;

String* copyString(const String* s);
String* rawDecode(const char* src);
String* hexDecode(const char* src);
String* b64Decode(const char* src);
const char* hexEncode(String* s);
const char* b64Encode(String* s);
void deleteString(String* s);

String* xorString(String* s1, const String* key);
