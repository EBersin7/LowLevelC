#include "stringfunctions.h"

void take(char *s, int n) {
    char *t = s;
    int length = 0;

    while (*t != '\0') {
        length++;
        t++;
    }

    if (n >= length) {
        return;
    } else {
        int i;
        for (i = 0; i < n; i++) {
            s++;
        }
        *s = '\0';

    }
    return;
}
