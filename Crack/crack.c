#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
#include "crack.h"

void combinaison(double id, char alpha[], int alphaLenght, combinationT * combi)
{
  double tmpId = id;
  int maxId = 0;
  int arrayIdAlpha[8] = {0,0,0,0,0,0,0,0};
  int p = 7;
  double power = pow(alphaLenght,p);
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
    }
  }

  for (int j = 0; j <= maxId; j++) {
    combi->word[j] = alpha[arrayIdAlpha[j]];
  }

  for (int k = maxId+1; k < 9; k++) {
    combi->word[k] = '\0';
  }
}

