#include <stdio.h>
#include <math.h>
#include <stdbool.h>
#include <stdlib.h>
#include <string.h>


typedef struct combinationST{
  int length;
  char word[9];
} combinationT;

void combinaison(int id, char alpha[], int alphaLenght, combinationT * combi)
{
  int tmpId = id;
  int maxId = 0;
  bool nbDigits = false;
  bool first = false;
  int arrayIdAlpha[8] = {0,0,0,0,0,0,0,0};
  for (int i = 7; i >= 0; i--) {
    double power = pow(alphaLenght,i);

    while (tmpId >= power) {
      nbDigits = true;
      arrayIdAlpha[i]++;
      tmpId -= power;
    }
    if (nbDigits && i > 0) {
      maxId = (maxId == 0) ? (i) : (maxId);
      nbDigits = false;
    }
  }
  printf("%d = ", id);
  for (int j = 0; j <= maxId; j++) {
    combi->word[j] = alpha[arrayIdAlpha[j] - 1];
    printf("%c", alpha[arrayIdAlpha[j] - 1]);
  }

printf("\n");
  for (int k = maxId+1; k < 9; k++) {
    combi->word[k] = '\0';
  }
}

int main(int argc, char *argv[]) {
  combinationT cmb;

  char alphabet[] =
  "abcdefghijklmnopqrstuvwxyz"
  "ABCDEFGHIJKLMNOPQRSTUVWXYZ"
  "0123456789"
  "*~!";
  combinaison(atoi(argv[1]), alphabet, 66, &cmb);
  for (int i = 0; i <= 66; i++) {
   //combinaison(i*66 - 1, alphabet, 66, &cmb);
  }

  return 0;
}
