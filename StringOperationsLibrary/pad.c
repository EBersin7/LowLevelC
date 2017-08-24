#include "stringfunctions.h"
#include <stdlib.h>

char *pad(char *s, int d) {

    int i = 0, len = 0;

    if (s == NULL) {
        return NULL;
    }
    while (s[i] != '\0') {
        len++;
        i++;
    }

    if (len % (2 * d) == 0) {
        return;
    }
    char *padded;
    if ((padded = malloc(len + 1)) == NULL) {
        return NULL;
    }
    i = 0;
    while (s[i] != '\0') {
        padded[i] = s[i];
        i++;
    }
    while (i % (2 * d) != 0) {
        padded[i] = '+';
        i++;
    }
    return padded;
}
