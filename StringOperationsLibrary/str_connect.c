#include "stringfunctions.h"
#include <stdlib.h>

char *str_connect(char **strs, int n, char c) {

    int i, j, k, len = 0;
    i = 0;
    while (i < n) {
        for (j = 0; strs[i][j] != '\0'; j++) {
            len++;
        }
        i++;
    }

    char *connect;
    if ((connect = malloc(len + 1)) == NULL) {
        return NULL;
    }
    i = k = 0;
    while (i < n) {
        for (j = 0; strs[i][j] != '\0'; j++) {
            connect[k] = strs[i][j];
            k++;
        }
        if (i + 1 < n) {
            connect[k] = c;
            k++;
        }
        i++;
    }
    return connect;
}
