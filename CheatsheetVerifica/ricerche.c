#include <string.h>
#include "ricerche.h"

int RicercaBinariaInteri(const int vettore[], int dimensione, int valoreCercato)
{
    int sinistra;
    int destra;
    int centro;

    sinistra = 0;
    destra = dimensione - 1;

    while (sinistra <= destra)
    {
        centro = sinistra + (destra - sinistra) / 2;

        if (vettore[centro] == valoreCercato)
            return centro;

        if (vettore[centro] < valoreCercato)
            sinistra = centro + 1;
        else
            destra = centro - 1;
    }

    return -1;
}

int RicercaBinariaStringhe(const char vettore[][DIM_STRINGA], int dimensione,
                           const char stringaCercata[])
{
    int sinistra;
    int destra;
    int centro;
    int confronto;

    sinistra = 0;
    destra = dimensione - 1;

    while (sinistra <= destra)
    {
        centro = sinistra + (destra - sinistra) / 2;
        confronto = strcmp(vettore[centro], stringaCercata);

        if (confronto == 0)
            return centro;

        if (confronto < 0)
            sinistra = centro + 1;
        else
            destra = centro - 1;
    }

    return -1;
}

int RicercaBinariaStudentePerCognome(const Studente studenti[], int dimensione,
                                     const char cognomeCercato[])
{
    int sinistra;
    int destra;
    int centro;
    int confronto;

    sinistra = 0;
    destra = dimensione - 1;

    while (sinistra <= destra)
    {
        centro = sinistra + (destra - sinistra) / 2;
        confronto = strcmp(studenti[centro].cognome, cognomeCercato);

        if (confronto == 0)
            return centro;

        if (confronto < 0)
            sinistra = centro + 1;
        else
            destra = centro - 1;
    }

    return -1;
}
