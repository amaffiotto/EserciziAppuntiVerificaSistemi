#ifndef ORDINAMENTI_H
#define ORDINAMENTI_H

#include "tipi.h"

void ScambiaInteri(int *primo, int *secondo);
void BubbleSortInteri(int vettore[], int dimensione);

void ScambiaStringhe(char prima[], char seconda[]);
void BubbleSortStringhe(char vettore[][DIM_STRINGA], int dimensione);

void ScambiaStudenti(Studente *primo, Studente *secondo);
void BubbleSortStudentiPerCognome(Studente studenti[], int dimensione);

#endif
