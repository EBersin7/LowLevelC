#include <stdio.h>
#include <stdlib.h>

#define FILE_OPEN_ERROR 1

/* SIM1 operation codes (plus JMP) with format naaa where       */
/* aaa is a 3-digit address and n is as follows:                */

#define HALT       0          /* halt processor                 */
#define LD         1          /* load accumulator instruction   */
#define ST         2          /* store accumulator instruction  */
#define ADD        3          /* add (to accumulator)           */
#define SUB        4          /* subtract (from accumulator)    */
#define LDA        5          /* load address                   */
#define JMP        6          /* jump (branch) to address       */
#define SKIPSET    7          /* skip instructions              */
#define ACCSET     8          /* accumulator instructions       */

/* SIM2 skip operation codes with format 7n0r where r is a general    */
/* register and n is as follows:                                      */
#define SKIP       0          /* unconditional skip                   */
#define SKEQ       1          /* skip if acc equals 0                 */
#define SKNE       2          /* skip if acc not equal to 0           */
#define SKGT       3          /* skip if acc greater than 0           */
#define SKGE       4          /* skip if acc greater or equal to  0   */
#define SKLT       5          /* skip if acc less than 0              */
#define SKLE       6          /* skip if acc less than or equal to 0  */

/* accumulator operation codes (format 8n00, where n is as follows)   */
#define IN         0          /* input a 4-digit number into acc      */
#define OUT        1          /* output the 4-digit number from acc   */
#define CLR        2          /* clear the acc (acc = 0)              */
#define INC        3          /* increment (add 1) to the acc         */
#define DEC        4          /* decrement (subtract 1) from the acc  */
#define NEG        5          /* negate the number in acc             */
#define SHFTL      6          /* shift acc left (acc=acc*10)          */
#define SHFTR      7          /* shift acc right (acc=acc/10)         */

void usage(char** argv);

int main(int argc, char **argv) {

	if(argc < 2){
		usage(argv);
    		return FILE_OPEN_ERROR;
  	}

	FILE *fp = fopen(argv[1], "r");
	char c;
	int lines = 0;

	while((c = fgetc(fp)) != EOF){
  		if(c == '\n')
  		{
    			lines++;
  		}
	}

	printf("The number of lines is: %d\n", lines);

	int length = (lines * 2);

	printf("The length used for the array is: %d\n", length);

	int integers[length];

	rewind(fp);

    	int i=0;
    	int num;
    	while(fscanf(fp, "%d", &num) > 0) {
        	integers[i] = num;
        	i++;
    	}

	i = 0;
	int count = 0;

	for(i = 0; i <= length; i+=2){

		int tempdigit1 = (integers[i+1]/1000);
      		int tempdigit2 = (integers[i+1]/100)%10;
      		int tempdigit3 = (integers[i+1]/10)%10;
		int tempdigit4 = integers[i+1]%10;
		int tempdigit234 = integers[i+1]%1000;

		if(i == length){
			printf("%03d\n End of instructions\n", integers[i-1]);
		}else if((integers[i+1] == 0) && (count == 0)){
			printf("%03d %04d HALT\n", integers[i], integers[i+1]);
			count++;
		}else{
			switch(tempdigit1){
			case HALT:
				printf("%03d %04d .words\n", integers[i], integers[i+1]);
				break;
        		case LD:
				printf("%03d %d LD %d\n", integers[i], integers[i+1], tempdigit234);
           			break;
        		case ST:
				printf("%03d %d ST %d\n", integers[i], integers[i+1], tempdigit234);
           			break;
        		case ADD:
				printf("%03d %d ADD %d\n", integers[i], integers[i+1], tempdigit234);
           			break;
        		case SUB:
				printf("%03d %d SUB %d\n", integers[i], integers[i+1], tempdigit234);
           			break;
        		case LDA:
				printf("%03d %d LDA %d\n", integers[i], integers[i+1], tempdigit234);
           			break;
        		case JMP:
				printf("%03d %d JMP %d\n", integers[i], integers[i+1], tempdigit234);
           			break;
        		case SKIPSET:
				printf("Using SKIPSET\n");
				switch(tempdigit2){
 				case SKIP:
         				printf("%03d %d SKIP %d\n", integers[i], integers[i+1], tempdigit4);
					break;
      				case SKEQ:
         				printf("%03d %d SKEQ %d\n", integers[i], integers[i+1], tempdigit4);
					break;
      				case SKNE:
         				printf("%03d %d SKNE %d\n", integers[i], integers[i+1], tempdigit4);
					break;
      				case SKGT:
					printf("%03d %d SKGT %d\n", integers[i], integers[i+1], tempdigit4);
         				break;
      				case SKGE:
					printf("%03d %d SKGE %d\n", integers[i], integers[i+1], tempdigit4);
         				break;
      				case SKLT:
					printf("%03d %d SKLT %d\n", integers[i], integers[i+1], tempdigit4);
         				break;
      				case SKLE:
					printf("%03d %d SKLE %d\n", integers[i], integers[i+1], tempdigit4);
         				break;
				}
				printf("Exiting SKIPSET\n");
           			break;
        		case ACCSET:
				printf("Using ACCSET\n");
				switch(tempdigit2){
				case IN:
					printf("%03d %d ACC IN\n", integers[i], integers[i+1]);
         				break;
      				case OUT:
					printf("%03d %d ACC OUT\n", integers[i], integers[i+1]);
         				break;
      				case CLR:
					printf("%03d %d ACC CLR\n", integers[i], integers[i+1]);
         				break;
      				case INC:
					printf("%03d %d ACC INC\n", integers[i], integers[i+1]);
         				break;
      				case DEC:
					printf("%03d %d ACC DEC\n", integers[i], integers[i+1]);
         				break;
      				case NEG:
					printf("%03d %d ACC NEG\n", integers[i], integers[i+1]);
         				break;
      				case SHFTL:
					printf("%03d %d ACC SHFTL\n", integers[i], integers[i+1]);
         				break;
      				case SHFTR:
					printf("%03d %d ACC SHFTR\n", integers[i], integers[i+1]);
         				break;
				}
				printf("Exiting ACCSET\n");
				break;
			}
		}
	}

    	fclose(fp);
	return 0;
}

void usage(char **argv) {
	fprintf(stderr, "Usage Error: Please enter a .txt file as a command line argument as follows ->\n%s filename\n", argv[0]);
}
