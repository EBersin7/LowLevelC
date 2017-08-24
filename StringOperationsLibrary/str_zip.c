#include "stringfunctions.h"
#include <stdlib.h>

char *str_zip(char *s1, char *s2) {
    int len1, len2, i = 0, j = 0;

    while (s1[i] != '\0') {
        i++;
    }
    while (s2[j] != '\0') {
        j++;
    }

    len1 = i;
    len2 = j;

    char *zip;
    if ((zip = malloc(i + j + 1)) == NULL) {
        return NULL;
    }

    int k = i = j = 0;
    while ((i < len1) || (j < len2)) {
        if ((i < len1) && (j < len2)) {
            zip[k] = s1[i];
            zip[k + 1] = s2[j];
            i++, j++, k += 2;
        } else if (i == len1 && j != len2) {
            zip[k] = s2[j];
            j++, k++;
        } else if (i != len1 && j == len2) {
            zip[k] = s1[i];
            i++, k++;
        }
    }
    zip[k] = '\0';
    return zip;
}
