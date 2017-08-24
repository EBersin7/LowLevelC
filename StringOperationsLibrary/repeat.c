#include "stringfunctions.h"
#include <stdlib.h>

char *repeat(char *s, int x, char sep) {

    int i = 0, len = 0;

    if (s == NULL) {
        return NULL;
    }

    while (s[i] != '\0') {
        len++;
        i++;
    }

    char *rep;
    if ((rep = malloc(x * (len + 1))) == NULL) {
        return NULL;
    }
    i = 0;
    int j, k = 0;
    for (j = 0; j < x; j++) {
        if (i == len) {
            i = 0;
            rep[k] = sep;
            k++;
        }
        while (s[i] != '\0') {
            rep[k] = s[i];
            i++, k++;
        }
    }
    rep[k] = '\0';
    return rep;
}
