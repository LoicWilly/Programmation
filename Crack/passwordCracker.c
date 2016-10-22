#include <stdio.h>
#include "crack.h"

int main(int argc, char *argv[]) {
  combinationT cmb;
  char alphabet[] =
  "abcdefghijklmnopqrstuvwxyz"
  "ABCDEFGHIJKLMNOPQRSTUVWXYZ"
  "0123456789"
  "*~!";
  double idArg;
  sscanf(argv[1], "%lf", &idArg);
  combinaison(idArg, alphabet, 65, &cmb);
  printf("%s\n", cmb.word);

  return 0;
}
