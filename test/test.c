#include "test.h"

void clearSpinner();

int main() {
    int success = 0;
    int failure = 0;

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
    TestFindSingleXorKey(&success, &failure);

    clearSpinner();
    printf("Tests completed: %i successes and %i failures\n",
            success, failure);

    return 0;
}

void clearSpinner() {
    printf("\b");
}

void updateSpinner(int* success) {
    char spinnerStates[] = { '\\', '|', '/', '-' };

    clearSpinner();
    printf("%c", spinnerStates[*success / 4 % 4]);
}

void printResult(const char* function, int testNumber, const char* expectedResult, const char* result, int* success, int* failure) {
    if (strcmp(expectedResult, result) == 0)
    {
        updateSpinner(success);
        ++(*success);
    }
    else
    {
        clearSpinner();
        printf("FAIL %s(%i): %s != %s\n", function, testNumber + 1, expectedResult, result);
        ++(*failure);
    }
}
