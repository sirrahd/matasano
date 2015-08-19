#include "test.h"

void clearSpinner();

void main()
{
    int success = 0, failure = 0;
    
    // hex_test.h
    TestHexCharToInt(&success, &failure);
    TestHexStringToInt(&success, &failure);
    TestIntToHexChar(&success, &failure);
    TestIntToHexString(&success, &failure);
    TestHexStringToCharString(&success, &failure);
    
    // base64_test.h
    TestIntToB64Char(&success, &failure);
    TestIntToB64String(&success, &failure);
    TestHexStringToB64String(&success, &failure);

    // xor_test.h
    TestFixedXor(&success, &failure);

    clearSpinner();
    printf("Tests completed: %i successes and %i failures\n",
            success, failure);
}

void clearSpinner()
{
    printf("\b");
}

void updateSpinner(int * success)
{
    char spinnerStates[] = { '\\', '|', '/', '-' };

    clearSpinner();
    printf("%c", spinnerStates[*success / 4 % 4]);
}

void printResult(const char * function, const char * test[2], const char * result, int * success, int * failure)
{
    if (strcmp(test[1], result) == 0)
    {
        updateSpinner(success);
        (*success)++;
    }
    else
    {
        clearSpinner();
        printf("FAIL %s(%s): %s != %s\n", function, test[0], test[1], result);
        (*failure)++;
    }
}
