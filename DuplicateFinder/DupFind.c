#include <openssl/sha.h>
#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <dirent.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <errno.h>

#define SPACES_PER_INDENT_LEVEL 3
#define MAX_PATH_LENGTH 512

#define EXIT_USAGE_ERROR 1
#define EXIT_SUCCESS 0

extern int errno;

void to_hex_string(unsigned char bytes[], char str[], int len);
void make_space(int num_spaces);
int is_dir(char *path_name);
void count_num_files(char *pathname, int n, int *fileCount);
void create_hash(char *pathname, int n, char names[], unsigned char hashes[], char hashes_as_strings[]);


int main(int argc, char **argv) {

  int fileCount = 0;

  if(argc < 2){
	char cwd[MAX_PATH_LENGTH];
    	if (getcwd(cwd, sizeof(cwd)) != NULL){
        	printf("%s\n", cwd);
		count_num_files(cwd, 0, &fileCount);
		printf("The number of files in %s is %d\n", cwd, fileCount);
		char names[fileCount][MAX_PATH_LENGTH];
		unsigned char hashes[fileCount][SHA_DIGEST_LENGTH];
		char hashes_as_strings[fileCount][SHA_DIGEST_LENGTH*2+1];
		int i;
		for(i = 1; i < fileCount; i++){
			create_hash(argv[i], 0, names[i], hashes[i], hashes_as_strings[i]);
		}

		int j;
		for(i = 1; i < fileCount; i++){
			for(j = 2; j < argc; j++){
				if(hashes[i] == hashes[j]){
					printf("%s and %s are duplicates", names[i], names[j]);
				}
			}

		}
	}else{
		printf("Error\n");
		return EXIT_USAGE_ERROR;
	}
  }else{
	int i;
	int k = 0;
	for(i = 1; i < argc; i++){
		fileCount = 0;
		printf("%s\n", argv[i]);
		count_num_files(argv[i], 0, &fileCount);
		k += fileCount;
		printf("The number of files in %s is %d\n", argv[i], fileCount);
		char names[fileCount][MAX_PATH_LENGTH];
		unsigned char hashes[fileCount][SHA_DIGEST_LENGTH];
		char hashes_as_strings[fileCount][SHA_DIGEST_LENGTH];

		create_hash(argv[i], 0, names[i], hashes[i], hashes_as_strings[i]);
		int j, l;
		for(l = 1; i < k; i++){
			for(j = 2; j < argc; j++){
				if(hashes[i] == hashes[j]){
				printf("%s and %s are duplicates", names[i], names[j]);
			}

		}

	}
  }
  return EXIT_SUCCESS;}
}

int is_dir(char *path_name) {
  struct stat buff;

  if (stat(path_name, &buff) < 0){
    fprintf(stderr, "stat: %s\n", strerror(errno));
    return 0;
  }

  return S_ISDIR(buff.st_mode);
}

void count_num_files(char *pathname, int depth, int *fileCount) {
  if (is_dir(pathname)) {
    DIR *d;
    struct dirent *p;
    char path[MAX_PATH_LENGTH];

    if ((d = opendir(pathname)) == NULL){
      fprintf(stderr, "opendir %s  %s\n", path, strerror(errno));
      return;
    }

    while ((p = readdir(d)) != NULL) {
      *fileCount +=1;
      if (strcmp(".", p->d_name)==0 || strcmp("..", p->d_name)==0){
	continue;
    }
      make_space(depth*SPACES_PER_INDENT_LEVEL);
      printf("%s\n", p->d_name);
      snprintf(path, MAX_PATH_LENGTH, "%s/%s", pathname, p->d_name);
      count_num_files(path, depth+1, fileCount);
    }
    closedir(d);
  }else{
    *fileCount += 1;
  }
}

void make_space(int num_spaces) {
  int i;
  for (i=0; i<num_spaces; i++){
    putchar(' ');
  }
}

void to_hex_string(unsigned char bytes[], char str[], int len) {
  int i;

  for (i=0; i<len; i++) {
    sprintf(str, "%02X", (unsigned char)bytes[i]);
    str+=2;
  }
}

void create_hash(char *pathname, int depth, char names[], unsigned char hashes[], char hashes_as_strings[]){

  int i;
  int c;

  SHA_CTX ctx;
  FILE *fp;

  if (is_dir(pathname)) {
    DIR *d;
    struct dirent *p;
    char path[MAX_PATH_LENGTH];

    if ((d = opendir(pathname)) == NULL){
      fprintf(stderr, "opendir %s  %s\n", path, strerror(errno));
      return;
    } 

    while ((p = readdir(d)) != NULL) {
      if (strcmp(".", p->d_name)==0 || strcmp("..", p->d_name)==0){
	continue;
	}else{
      		if ((fp=fopen(argv[i], "r"))==NULL) {
      		fprintf(stderr, "error opening %s for reading\n", argv[i]);
      		continue;
      	}

    	SHA1_Init(&ctx);

    	while ((c=fgetc(fp))!=EOF) {
      		SHA1_Update(&ctx, &c, 1);
    		}

    		SHA1_Final(hashes, &ctx);
    		to_hex_string(hashes, hashes_as_strings, SHA_DIGEST_LENGTH);
    		printf("%s: %s\n", argv[i], hashes_as_strings);
	}
}
