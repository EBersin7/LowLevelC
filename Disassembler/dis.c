#include <stdio.h>
#include <stdlib.h>

#define USAGE_ERROR 1
#define FILE_OPEN_ERROR 2

void usage(char** argv);

int main(int argc, char **argv) {

	if(argc < 2){
		usage(argv);
    		return FILE_OPEN_ERROR;
  	}

	FILE *fp = fopen(argv[1], "r");
	char c;
	int lines;

	while(!feof(fp)){
  		c = fgetc(fp);
  		if(c == '\n')
  		{
    			lines++;
  		}
	}

	int length = (lines * 2);
	int integers[length];

	fclose(fp);
	fp = fopen(argv[1], "r");

    	int i=0;
    	int num;
    	while(fscanf(fp, "%d", &num) > 0) {
        	integers[i] = num;
        	i++;
    	}

	for(i = 0; i <= length; i+=2){
		if(i == length){
			printf("%d\nEND",integers[i-1]);
		}else{
			printf("%d %d\n", integers[i], integers[i+1]);
		}
	}

    	fclose(fp);
	return 0;
}

void usage(char **argv) {
	fprintf(stderr, "Usage Error: Please enter a .txt file as a command line argument as follows ->\n%s filename\n", argv[0]);
}
