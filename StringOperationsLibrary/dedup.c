#include "stringfunctions.h"
#include <stdlib.h>

char *dedup(char *s) {

    int i = 0, len = 0, j, k;

    while (s[i] != '\0') {
        len++;
        i++;
    }

    char *dup;
    if ((dup = malloc(len + 1)) == NULL) {
        return NULL;
    }

    i = k = 0;
    int found = 0;
    while (s[i] != '\0') {
        for (j = 0; j < k; j++) {
            if (dup[j] == s[i]) {
                found = 1;
                break;
            } else {
                found = 0;
            }
        }
        if (found == 0) {
            dup[k] = s[i];
            k++;
        }
        i++;
    }
    return dup;
}
