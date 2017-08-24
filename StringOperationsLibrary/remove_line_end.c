#include "stringfunctions.h"

void remove_line_end(char *s) {
    int i = 0;

    while (s[i] != '\0') {
        i++;
    }

    i--;

    while (s[i] == '\n') {
        s[i] = '\0';
        i--;
    }
}
