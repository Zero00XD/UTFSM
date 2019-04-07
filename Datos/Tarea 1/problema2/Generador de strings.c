#include <time.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/* alphabet: [a-z0-9] */
const char alphabet[] = "abcdefghijklmnopqrstuvwxyz";

/**
 * not a cryptographically secure number
 * return interger [0, n).
 */
int intN(int n) { return rand() % n; }

/**
 * Input: length of the random string [a-z0-9] to be generated
 */
char *randomString(int len) {
  char *rstr = malloc((len + 1) * sizeof(char));
  int i;
  for (i = 0; i < len; i++) {
    rstr[i] = alphabet[intN(strlen(alphabet))];
  }
  rstr[len] = '\0';
  return rstr;
}

int main(int argc, char **argv) {
  // the seed for a new sequence of pseudo-random integers
  // to be returned by rand()
  srand(time(NULL));
  FILE*fp=fopen("string.txt","w");
  char *p;
  for(int i=0;i<10000000;i++){
    int r;
    r=200;
    p = randomString(r);
    fprintf(fp,"%s\n",p);
    free(p);
  }
  return 0;
}