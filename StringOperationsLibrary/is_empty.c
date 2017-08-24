#include "stringfunctions.h"
#include <ctype.h>
#define NULL 0
int is_empty(char *s) {
    if (s == NULL) {
        return 1;
    } else {
        while (*s != '\0') {
            if ((!(isspace(*s)))&&(*s != '\0')) {
                return 0;
            }
            s++;
        }
    }
    return 1;
}
