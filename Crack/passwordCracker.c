#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>
#include <string.h>
#include "crack.h"
#define ALPHABET_LENGTH 65

void splitSaltPassword(char * saltPassword,combiThreadT * combi)
{
    int length = strlen(saltPassword);
    combi->salt[0] = saltPassword[0];
    combi->salt[1] = saltPassword[1];
    combi->salt[2] = '\0';
    for (int i = 2; i < length; i++) {
      combi->cryptedPassword[i-2] = saltPassword[i];
    }
    combi->cryptedPassword[length] = '\0';
}

int main(int argc, char *argv[]) {
  if (argc != 3) {
    fprintf(stderr, "syntax: %s P N\nWhere: P is the password to decrypt and N the number of threads.\n", argv[0]);
    return EXIT_FAILURE;
  }

  //int N = atoi(argv[2]);


  char alphabet[] =
  "abcdefghijklmnopqrstuvwxyz"
  "ABCDEFGHIJKLMNOPQRSTUVWXYZ"
  "0123456789"
  "*~!";


  // pthread_t th[M];
	// param_t params[M];
	// for (int i = 0; i < M; i++) {
	// 	param_t p = { i+1, M, N, &sum[i] };
	// 	params[i] = p;
	// 	if (pthread_create(&th[i], NULL, compute, &params[i]) != 0) {
	// 		fprintf(stderr, "pthread_create failed!\n");
	// 		return EXIT_FAILURE;
	// 	}
	// }



  return EXIT_SUCCESS;

}
