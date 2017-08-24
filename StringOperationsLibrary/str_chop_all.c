#include "stringfunctions.h"
#include <stdlib.h>

char **str_chop_all(char *s, char c) {

    int i = 0, j, len = 0, charCount = 0;
    while (s[i] != '\0') {
        len++;
        i++;
    }

    char **chop = malloc(10 * sizeof (char*));
    if (chop == NULL) {
        return NULL;
    }

    for (i = 0; i < len; i++) {
        chop[i] = malloc(20);
    }

    int k = 0;
    i = j = 0;
    while(s[i] != '\0'){
        if(s[i] == c){
            j=0;
            k++;
        }
        chop[k][j] = s[i];
        i++, j++;
    }
    
    k++;
    chop[k] = "(null)";
    return chop;
}
