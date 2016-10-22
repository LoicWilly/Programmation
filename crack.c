#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>


typedef struct combinationST{
  int length;
  char word[9];
} combinationT;

void combinaison(double id, char alpha[], int alphaLenght, combinationT * combi)
{
  double tmpId = id;
  int maxId = 0;
  int arrayIdAlpha[8] = {0,0,0,0,0,0,0,0};
  int p = 7;
  double power = pow(alphaLenght,p);
  printf("%f\n", power);
  while(tmpId != 0)
  {
    if(tmpId >= power)
    {
        tmpId -= power;
        if(id >= 2*power || p == 0)
        {
        arrayIdAlpha[p]++;
        }
        maxId = (maxId > 0) ? (maxId)  : (p);
    }
    else
    {
     p--;
     power = pow(alphaLenght,p);
     printf("%f\n", power);
    }
  }

  for (int j = 0; j <= maxId; j++) {
    combi->word[j] = alpha[arrayIdAlpha[j]];
  }

  for (int k = maxId+1; k < 9; k++) {
    combi->word[k] = '\0';
  }
  printf("%s\n", combi->word);
}

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


  return 0;
}
