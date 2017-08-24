#include "stringfunctions.h"

int index_of(char *h, char *n) {
    int i = 0, j = 0;

    while (h[i] != '\0') {
        if (h[i] == n[0]) {
            while (h[i + j] == n[j]) {
                j++;
                if (n[j] == '\0') {
                    return i;
                }
            }
            j = 0;
        }
        i++;
    }
    return -1;
}
