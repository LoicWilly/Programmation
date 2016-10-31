#ifndef CRACK_H_INCLUDED
#define CRACK_H_INCLUDED
#include <stdbool.h>


typedef struct combiThreadST
{
  int idThread;
  int nbThreads;
  char * cryptedPassword;
  char salt[3];

  char word[9];
  char * alpha;
  int alphaLength;
} combiThreadT;


void combination(double id, combiThreadT * combi);
bool testCombination(double idStart, double nbCombinations, int jump, combiThreadT * combi);

#endif // CRACK_H_INCLUDED
