#include "test.h"

int main()
{
    int success = 0, failure = 0;
    TestHexCharToInt(&success, &failure);
    TestHexStringToInt(&success, &failure);
    TestIntToB64Char(&success, &failure);
    TestIntToB64String(&success, &failure);
    TestHexCharToB64String(&success, &failure);
    printf("Tests completed: %i successes and %i failures\n",
            success, failure);
}
