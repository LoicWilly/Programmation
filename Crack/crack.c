#define _GNU_SOURCE
#include <crypt.h>

#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
#include "crack.h"
#define MAX_POWER 7

void combination(double id, combiThreadT * combi)
{
  double tmpId = id;
  int maxId = 0;
  int arrayIdAlpha[8] = {0,0,0,0,0,0,0,0};
  int p = MAX_POWER;
  double power = pow(combi->alphaLength,p);
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
     power = pow(combi->alphaLength,p);
    }
  }

  for (int j = 0; j <= maxId; j++) {
    combi->word[j] = combi->alpha[arrayIdAlpha[j]];
  }

  for (int k = maxId+1; k < 9; k++) {
    combi->word[k] = '\0';
  }
}

bool testCombination(double idStart, double nbCombinations, int jump, combiThreadT * combi)
{
  struct crypt_data cdata;
  cdata.initialized = 0;

    for (double i = idStart; i < nbCombinations; i+=jump) {
      combination(i, combi);
      if (strcmp(combi->cryptedPassword, crypt_r(combi->word, combi->salt, &cdata)) == 0) {
        return true;
      }
    }
    return false;
}
