#ifndef GESTIONE_FILE_H
#define GESTIONE_FILE_H

#include "tipi.h"

void LeggiFilePerRighe(const char nomeFile[]);
int CaricaInteriDaFile(const char nomeFile[], int vettore[], int dimensione);
int CaricaStudentiDaFile(const char nomeFile[], Studente studenti[], int dimensione);
int AggiungiStudenteAlFile(const char nomeFile[], const Studente *studente);

#endif
