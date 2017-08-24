#include "stringfunctions.h"
#include <ctype.h>
#include <stdlib.h>
#include <stdio.h>

int main(int argc, char** argv) {

    //Test remove trailing newline function
    char str1[50] = "Hello\nHello\n\n\n";
    printf("This is the original string: %s", str1);
    remove_line_end(str1);
    printf("This is the string with trailing newline characters removed: %s\n", str1);
    

    //Test index of function
    char str2[50] = "Testing the index of function.";
    char c1[50] = "x";
    int index = index_of(str2, c1);
    printf("This is the index of the first occurrence of '%s' in the string '%s': %d\n", c1, str2, index);

    //Test address of function
    char str3[50] = "Testing the address of function.";
    char c2[50] = "a";
    char *address = address_of(str3, c2);
    printf("This is the address of the first occurence of '%s' in the string '%s': %d\n", c2, str3, address);
    
    //Test is empty function
    char str4a[50] = "";
    char str4b[50] = "I am not a NULL string!";
    if(is_empty(str4a)){
        printf("String A is NULL\n");
    }else{
        printf("String A is not NULL\n");
    }
    if(is_empty(str4b)){
        printf("String B is NULL\n");
    }else{
        printf("String B is not NULL\n");
    }

    //Test zip function
    char str5a[30] = "Spongebob";
    char str5b[30] = "Patrick";
    char *zip = str_zip(str5a, str5b);
    printf("The string '%s' interlaced with the string '%s' produces the string: %s\n", str5a, str5b, zip);

    //Test acronymer function
    char str6[50] = "Royal Australian Air Force";
    char *ac = acronymer(str6);
    printf("The string '%s' made into an acronym is: %s\n", str6, ac);

    //Test string compare ignore case function
    char str7a[50] = "Hello World";
    char str7b[50] = "ello worldh";
    if (strcmp_ign_case(str7a, str7b) == -1) {
        printf("String A comes before String B in the dictionary.\n");
    } else if (strcmp_ign_case(str7a, str7b) == 1) {
        printf("String B comes before String A in the dictionary.\n");
    } else {
        printf("String A is equal to String B.\n");
    }

    //Test take function
    char str8[50] = "Brubeck";
    printf("The original string: %s\n", str8);
    take(str8, 5);
    printf("The truncated string: %s\n", str8);

    //Test take last function
    char str9[50] = "Brubeck";
    printf("The original string: %s\n", str9);
    take_last(str9, 5);
    printf("The truncated string: %s\n", str9);

    //Test dedup function
    char str10[50] = "There's always money in the banana stand!";
    char *dup;
    dup = dedup(str10);
    printf("The string '%s' with duplicate characters removed is: %s\n", str10, dup);

    //Test pad function
    char str11[50] = "Edward";
    char *padded;
    padded = pad(str11, 4);
    printf("The original string is '%s', but with padded spaces it is: %s\n", str11, padded);

    //Test begins with ignore case function
    char str12[50] = "Edward";
    char pre[50] = "ed";
    int p = begins_with_ignore_case(str12, pre);
    if(p == 1){
        printf("The string '%s' contains the prefix '%s'\n", str12, pre);
    }else if(p == 0){
        printf("The string '%s' does not contain the prefix '%s'\n", str12, pre);
    }

    //Test ends with ignore case function
    char str13[50] = "Edward";
    char suff[50] = "rd";
    int s = ends_with_ignore_case(str13, suff);
    if (s == 1) {
        printf("The string '%s' contains the suffix '%s'\n", str13, suff);
    } else if (s == 0) {
        printf("The string '%s' does not contain the suffix '%s'\n", str13, suff);
    }

    //Test repeat function
    char str14[50] = "Wow";
    char *rep;
    rep = repeat(str14, 5, ',');
    printf("The original string is '%s', the repetition string is: %s\n", str14, rep);

    //Test intersect function
    char str15a[50] = "Temple";
    char str15b[50] = "University";
    char *inter;
    inter = intersect(str15a, str15b);
    printf("The intersection of the string '%s' and the string '%s' is: %s\n", str15a, str15b, inter);

    //Test string connect
    char *str16[3] = {"Washington", "Adams", "Jefferson"};
    int i;
    char *connect;
    connect = str_connect(str16, 3, '+');
    printf("The connected string is: %s\n", connect);

    //Test string chop
    char str17[50] = "Kanye+Tay Tay";
    char **chop = str_chop(str17, '+');
    for (i = 0; i < 3; i++) {
        printf("%s\n", chop[i]);
    }
    
    //Test string chop all
    char str18[50] = "I am ready for a nice vacation";
    char **ch_all = str_chop_all(str18, ' ');
    char c = ' ';
    int charCount = 0;
    i = 0;
    while(str18[i] != '\0'){
        if(str18[i] == c){
            charCount++;
        }
        i++;
    }
    for(i = 0; i < charCount+2; i++){
        printf("%s\n",ch_all[i]);
    }
    return (1);
}
