#include "test.h"

int main()
{
    int success = 0, failure = 0;
    
    // hex.h
    TestHexCharToInt(&success, &failure);
    TestHexStringToInt(&success, &failure);
    TestIntToHexChar(&success, &failure);
    TestIntToHexString(&success, &failure);
    
    // base64.h
    TestIntToB64Char(&success, &failure);
    TestIntToB64String(&success, &failure);
    TestHexCharToB64String(&success, &failure);
    printf("Tests completed: %i successes and %i failures\n",
            success, failure);
}
