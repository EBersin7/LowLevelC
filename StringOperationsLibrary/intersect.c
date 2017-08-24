#include "stringfunctions.h"
#include <stdlib.h>

char *intersect(char *s1, char *s2) {

    int i = 0, j, k, len1 = 0, len2 = 0;
    while (s1[i] != '\0') {
        len1++;
        i++;
    }
    i = 0;
    while (s2[i] != '\0') {
        len2++;
        i++;
    }
    char *inter;
    if ((inter = malloc(len1 + 1)) == NULL) {
        return NULL;
    }


    for (i = 0; i < len1; i++) {
        for (j = 0; j < len2; j++) {
            if (s1[i] == s2[j]) {
                inter[k] = s1[i];
                k++;
            }
        }
    }

    if (is_empty(inter)) {
        return NULL;
    }
    inter = dedup(inter);
    return inter;
}
