#include "stringfunctions.h"
#include <ctype.h>

int strcmp_ign_case(char *s1, char *s2) {

    int i = 0, j = 0;
    while (s1[i] != '\0') {
        i++;
    }

    while (s2[j] != '\0') {
        j++;
    }

    char temp1[i + 1];
    char temp2[j + 1];

    i = j = 0;
    while (s1[i] != '\0') {
        temp1[i] = toupper(s1[i]);
        i++;
    }
    temp1[i] = '\0';

    while (s2[j] != '\0') {
        temp2[j] = toupper(s2[j]);
        j++;
    }
    temp2[j] = '\0';

    i = 0;
    while (temp1[i] != '\0') {
        if (temp1[i] != temp2[i]) {
            if (temp1[i] < temp2[i]) {
                return -1;
            } else {
                return 1;
            }
        }
        i++;
    }
    return 0;
}
