#ifndef CRACK_H_INCLUDED
#define CRACK_H_INCLUDED

typedef struct combinationST{
  int length;
  char word[9];
} combinationT;

void combinaison(double id, char alpha[], int alphaLenght, combinationT * combi);

#endif // CRACK_H_INCLUDED
