#include "stringfunctions.h"
#include <stdlib.h>

char **str_chop(char *s, char c) {

    int i = 0, j, len = 0;
    while (s[i] != '\0') {
        len++;
        i++;
    }

    char **chop = malloc(10 * sizeof (char*));
    if (chop == NULL) {
        return NULL;
    }

    for (i = 0; i < 3; i++) {
        chop[i] = malloc(20 * sizeof (char));
    }

    i = j = 0;
    while(s[i] != c){
        chop[0][j] = s[i];
        i++, j++;
    }
    
    chop[1][0] = c;
    i++;
    j = 0;
    while(s[i] != '\0'){
        chop[2][j] = s[i];
        i++, j++;
    }
    return chop;

}
