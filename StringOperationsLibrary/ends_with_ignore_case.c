#include "stringfunctions.h"
#include <ctype.h>

int ends_with_ignore_case(char *s, char *suff) {

    char *t = suff;
    int suffLen = 0;

    while (*t != '\0') {
        t++;
        suffLen++;
    }

    t = s;
    while (*t != '\0') {
        t++;
    }
    t = t - suffLen;
    char *p = suff;
    char ignoreSuff = tolower(*p);
    char ignoreStr = tolower(*t);
    while (ignoreSuff == ignoreStr && *p != '\0' && *t != '\0') {
        p++;
        t++;
        ignoreSuff = tolower(*p);
        ignoreStr = tolower(*t);
    }
    if (*p == '\0')
        return 1;
    else
        return 0;
}
