#ifndef TIPI_H
#define TIPI_H

#define MAX_ELEMENTI 100
#define DIM_STRINGA 50
#define DIM_CLASSE 10
#define DIM_SPECIALIZZAZIONE 20

typedef struct
{
    int matricola;
    char cognome[DIM_STRINGA];
    char nome[DIM_STRINGA];
    char classe[DIM_CLASSE];
    char specializzazione[DIM_SPECIALIZZAZIONE];
} Studente;

#endif
