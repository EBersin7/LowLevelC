#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(int argc, char **argv) {

    int c, i, j, len, msgChar;
    FILE *fpIn, *fpOut;
    char inputfile[256], outputfile[256], secretMsg[256];

    printf("Please, enter the name of the original image file: ");
    scanf("%s",&inputfile);

    printf("Please, enter the name of the image file to be modified: ");
    scanf("%s",&outputfile);

    printf("Please, enter the secret message: ");
    scanf("%s",&secretMsg);

    len = strlen(secretMsg);

    if ((fpIn = fopen(inputfile, "r")) == NULL) {
        printf("Error: Unable to open file '%s' for reading.", inputfile);
        return 1;
    }

    if ((fpOut = fopen(outputfile, "w")) == NULL) {
        printf("Error: Unable to open file '%s' for writing.", outputfile);
        return 1;
    }

char x;
while((x = fgetc(fpIn)) != '\n'){
fprintf(fpOut, "%c", x);
printf("%c\n", x);
}

printf("%c", x);
fprintf(fpOut, "%c", x);

while((x = fgetc(fpIn)) == '#'){
 printf("%c", x);
fprintf(fpOut, "%c", x);
 while((x = fgetc(fpIn)) != '\n'){
  printf("%c", x);
fprintf(fpOut, "%c", x);
  }
}
ungetc(x, fpIn);

int width;
fscanf(fpIn, "%d", &width);
printf("\n%d", width);

int height;
fscanf(fpIn, "%d", &height);
printf("\n%d\n", height);

int color;
fscanf(fpIn, "%d", &color);
printf("%d\n", color);


   /* if ((fgets(line, MAX_LENGTH, fpIn)) != NULL) {
        fprintf(fpOut, "%s", line);
        if ((line[0] != 'P') && (line[1] != '6')) {
            printf("Error: Not a .ppm file.\n");
            return 1;
        } else if ((fgets(line, MAX_LENGTH, fpIn)) != NULL) {
            fprintf(fpOut, "%s", line);
            while ((line[0] == '#') && ((fgets(line, MAX_LENGTH, fpIn)) != NULL)) {
                fprintf(fpOut, "%s", line);
            }
        }
    }

    if ((fgets(line, MAX_LENGTH, fpIn)) != NULL) {
        fprintf(fpOut, "%s", line);
    }

    if ((fgets(line, MAX_LENGTH, fpIn)) != NULL) {
        fprintf(fpOut, "%s", line);
    }

    for (i = 0; i < 8; i++) {
        c = fgetc(fpIn);
        unsigned int temp = (len >> i) & 1;
        if ((c & 1) && (temp == 0)) {
            c--;
            fprintf(fpOut, "%c", c);
        } else {
            c |= temp;
            fprintf(fpOut, "%c", c);
        }
    }
    for (i = 0; i < len; i++) {
        msgChar = secretMsg[i];
        for (j = 0; j < 8; j++) {
            c = fgetc(fpIn);
            unsigned int temp = (msgChar >> j) & 1;
            if ((c & 1) && (temp == 0)) {
                c--;
                fprintf(fpOut, "%c", c);
            } else {
                c |= temp;
                fprintf(fpOut, "%c", c);
            }
        }
    }

    while (!feof(fpIn)) {
        c = fgetc(fpIn);
        fprintf(fpOut, "%c", c);
    }

    printf("Writing Complete.\n");

    fclose(fpIn);
    fclose(fpOut);

    fpIn = fopen(outputfile, "r");

    printf("Reading Modified File...\n");

    if ((fgets(line, MAX_LENGTH, fpIn)) != NULL) {
        if (line[0] != 'P' && line[1] != '6') {
            printf("Error: Not a .ppm file\n");
            return 1;
        }
    }

    fgets(line, MAX_LENGTH, fpIn);
    fgets(line, MAX_LENGTH, fpIn);
    fgets(line, MAX_LENGTH, fpIn);
    fgets(line, MAX_LENGTH, fpIn);

    msgChar = 1;
    for (j = 0; j < 8; j++) {
        c = fgetc(fpIn);
        unsigned int temp = c & 1;
        temp <<= (7 - j);
        msgChar &= temp;
        msgChar <<= 1;
    }

    printf("The length of the message is: %d\n", len);
    
    for (i = 0; i < len; i++) {
        msgChar = 0;
        for (j = 0; j < 8; j++) {
            c = fgetc(fpIn);
            unsigned int temp = c & 1;
            temp <<= (7 - j);
            msgChar &= temp;
        }
    }
    
    printf("The message is: %s\n", secretMsg);
    */
    return 0;
}
