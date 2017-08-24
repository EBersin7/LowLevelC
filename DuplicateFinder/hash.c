#include <stdio.h>
#include <openssl/sha.h>

/* When compiling, rememeber to add -lcrypto

   For example, in class, we did:
   gcc -o sha1_openssl sha1_openssl.c -lcrypto */

void to_hex_string(unsigned char bytes[], char str[], int len);

int main(int argc, char **argv) {
  int i;
  int c;
  unsigned char hash[SHA_DIGEST_LENGTH];
  char hash_as_string[SHA_DIGEST_LENGTH*2+1];

  SHA_CTX ctx;
  FILE *fp;
  
  for (i=1; i<argc; i++) {
    if ((fp=fopen(argv[i], "r"))==NULL) {
      fprintf(stderr, "error opening %s for reading\n", argv[i]);
      continue;
    }

    SHA1_Init(&ctx);
    while ((c=fgetc(fp))!=EOF) {
      SHA1_Update(&ctx, &c, 1);
    }
    SHA1_Final(hash, &ctx);
    to_hex_string(hash, hash_as_string, SHA_DIGEST_LENGTH);
    printf("%s: %s\n", argv[i], hash_as_string);
  }

  return 0;
}

/* fills str with a C-string version of the digest stored
   in bytes[] */
void to_hex_string(unsigned char bytes[], char str[], int len) {
  int i;

  for (i=0; i<len; i++) {
    sprintf(str, "%02X", (unsigned char)bytes[i]);
    str+=2;
  }
}
