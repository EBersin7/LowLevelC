#include "stringfunctions.h"
#define NULL 0
char *address_of(char *h, char *n) {

    int i = 0, j = 0;

    char *address;

    while (h[i] != '\0') {
        if (h[i] == n[0]) {
            address = &h[i];
            while (h[i + j] == n[j]) {
                j++;
                if (n[j] == '\0') {
                    return address;
                }
            }
            j = 0;
        }
        i++;
    }
    return NULL;
}
