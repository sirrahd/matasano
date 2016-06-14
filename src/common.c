#include <ctype.h>
#include <string.h>

const char CHARFREQ[] = " eEtTaAoOnNiIsShHrRlLdDuUcCmMwWyYfFgGpPbBvVkKjJxXqQzZ";

int isPrintable(const char* string) {
    for (int i = 0; i < strlen(string); i++) {
        if (!isprint(string[i]) && string[i] != '\n') {
            return 0;
        }
    }

    return 1;
}

int isLikelyEnglish(const char* string) {
/*    if (!isPrintable(string)) {
        return 0;
    }
*/
    int count = 0;
    for (int i = 0; i < strlen(string); i++) {
        if (isalnum(string[i]) || isspace(string[i])) {
            count++;
        }
    }

    if ((float)count / (float)strlen(string) > 0.9)
        return 1;
    else
        return 0;
}

char* strrev(char* src) {
    size_t length = strlen(src);
    char tempChar;

    for (int i = 0; i < length / 2; ++i) {
        tempChar = src[i];
        src[i] = src[length - 1 - i];
        src[length - 1 - i] = tempChar;
    }

    return src;
}
