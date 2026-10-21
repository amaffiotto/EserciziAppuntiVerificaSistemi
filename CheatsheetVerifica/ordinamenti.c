#include <string.h>
#include "ordinamenti.h"

void ScambiaInteri(int *primo, int *secondo)
{
    int temporaneo;

    temporaneo = *primo;
    *primo = *secondo;
    *secondo = temporaneo;
}

void BubbleSortInteri(int vettore[], int dimensione)
{
    int i;
    int ultimo;
    int scambio;

    ultimo = dimensione - 1;

    do
    {
        scambio = 0;

        for (i = 0; i < ultimo; i++)
        {
            if (vettore[i] > vettore[i + 1])
            {
                ScambiaInteri(&vettore[i], &vettore[i + 1]);
                scambio = 1;
            }
        }

        ultimo--;
    }
    while (scambio == 1 && ultimo > 0);
}

void ScambiaStringhe(char prima[], char seconda[])
{
    char temporanea[DIM_STRINGA];

    strcpy(temporanea, prima);
    strcpy(prima, seconda);
    strcpy(seconda, temporanea);
}

void BubbleSortStringhe(char vettore[][DIM_STRINGA], int dimensione)
{
    int i;
    int ultimo;
    int scambio;

    ultimo = dimensione - 1;

    do
    {
        scambio = 0;

        for (i = 0; i < ultimo; i++)
        {
            // strcmp > 0: la prima stringa viene dopo la seconda.
            if (strcmp(vettore[i], vettore[i + 1]) > 0)
            {
                ScambiaStringhe(vettore[i], vettore[i + 1]);
                scambio = 1;
            }
        }

        ultimo--;
    }
    while (scambio == 1 && ultimo > 0);
}

void ScambiaStudenti(Studente *primo, Studente *secondo)
{
    Studente temporaneo;

    // Una sola assegnazione copia insieme tutti i campi della struttura.
    temporaneo = *primo;
    *primo = *secondo;
    *secondo = temporaneo;
}

void BubbleSortStudentiPerCognome(Studente studenti[], int dimensione)
{
    int i;
    int ultimo;
    int scambio;

    ultimo = dimensione - 1;

    do
    {
        scambio = 0;

        for (i = 0; i < ultimo; i++)
        {
            if (strcmp(studenti[i].cognome, studenti[i + 1].cognome) > 0)
            {
                // Vengono scambiati gli studenti completi, non solo i cognomi.
                ScambiaStudenti(&studenti[i], &studenti[i + 1]);
                scambio = 1;
            }
        }

        ultimo--;
    }
    while (scambio == 1 && ultimo > 0);
}
