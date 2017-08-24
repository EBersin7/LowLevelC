#include "stringfunctions.h"
#include <ctype.h>

int begins_with_ignore_case(char *s, char *pre) {

    char *t = s;
    char *p = pre;

    char lowerPre = tolower(*p);
    char lowerStr = tolower(*t);

    while (lowerPre == lowerStr && *p != '\0' && *t != '\0') {
        p++;
        t++;
        lowerPre = tolower(*p);
        lowerStr = tolower(*t);
    }
    if (*p == '\0')
        return 1;
    else
        return 0;

}
