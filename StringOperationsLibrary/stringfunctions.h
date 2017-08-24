#ifndef STRINGFUNCTIONS_H_
#define STRINGFUNCTIONS_H_

void remove_line_end(char *s);
int index_of(char *h, char *n);
char *address_of(char *h, char *n);
int is_empty(char *s);
char *str_zip(char *s1, char *s2);
char *acronymer(char *s);
int strcmp_ign_case(char *s1, char *s2);
void take(char *s, int n);
void take_last(char *s, int n);
char *dedup(char *s);
char *pad(char *s, int d);
int begins_with_ignore_case(char *s, char *pre);
int ends_with_ignore_case(char *s, char *suff);
char *repeat(char *s, int x, char sep);
char *intersect(char *s1, char *s2);
char *str_connect(char **strs, int n, char c);
char **str_chop(char *s, char c);
char **str_chop_all(char *s, char c);

#endif
