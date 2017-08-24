#include "stringfunctions.h"
#include <stdlib.h>
#include <ctype.h>

char *acronymer(char *s) {
    int i = 0, j = 0;
    char *ac;
    while (s[i] != '\0') {
        i++;
    }

    if ((ac = malloc(i + 1)) == NULL) {
        return NULL;
    }
    i = 0;
    while (s[i] != '\0') {
        if (i == 0) {
            ac[j] = s[i];
            j++;
        } else if ((isspace(s[i])) && !(isspace(s[i + 1]))) {
            ac[j] = s[i + 1];
            j++;
        }
        i++;
    }

    return ac;
}
