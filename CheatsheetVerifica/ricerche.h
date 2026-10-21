#ifndef RICERCHE_H
#define RICERCHE_H

#include "tipi.h"

int RicercaBinariaInteri(const int vettore[], int dimensione, int valoreCercato);
int RicercaBinariaStringhe(const char vettore[][DIM_STRINGA], int dimensione,
                           const char stringaCercata[]);
int RicercaBinariaStudentePerCognome(const Studente studenti[], int dimensione,
                                     const char cognomeCercato[]);

#endif
