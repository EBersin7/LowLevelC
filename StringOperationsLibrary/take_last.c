#include "stringfunctions.h"

void take_last(char *s, int n) {

    int i = 0, len = 0, j;

    while (s[i] != '\0') {
        len++;
        i++;
    }

    char temp[len];
    i = 0;
    while (s[i] != '\0') {
        temp[i] = s[i];
        i++;
    }
    temp[i] = '\0';

    if (n >= len) {
        return;
    } else {
        for (i = len - n, j = 0; i < len; i++, j++) {
            s[j] = temp[i];
        }
        s[j] = '\0';
    }
    return;
}
