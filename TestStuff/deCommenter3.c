#include <stdio.h>

#define IN 1
#define OUT 0

int main(int argc, char **argv){

int c, d, e, state = OUT, lineCount = 0;

while((c = getchar()) != EOF){

	if((c == '/') && (state == OUT)){
		d = getchar();
		if(d == '*'){
			state = IN;
			}else{
			state = OUT;
			putchar(c);
			putchar(d);
			}
		}
	else if ((c == '*') && (state == IN)){
			d = getchar();
			if(d == '/'){
				state = OUT;
				e = getchar();
					if(e != ' '){
						putchar(' ');
						putchar(e);
					}else{
						putchar(e);
					}
			}
		}
	else if((c == '"') && (state != IN)){
		putchar(c);
		while((d = getchar()) != '"'){
			putchar(d);
			}putchar(d);
		}
	else if(c == '\n'){
	lineCount++;
	putchar(c);
	}
	else if(state == OUT){
		putchar(c);
		}
	}

if(((c = getchar()) == EOF) && (state == IN)){
	printf("Error: Unterminated comment at line number %d", lineCount);
	}

putchar('\n');

return (0);
}
