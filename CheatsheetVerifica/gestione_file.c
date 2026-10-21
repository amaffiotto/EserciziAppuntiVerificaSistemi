#include <stdio.h>
#include "gestione_file.h"

void LeggiFilePerRighe(const char nomeFile[])
{
    FILE *fp;
    char riga[200];

    fp = fopen(nomeFile, "r");
    if (fp == NULL)
    {
        printf("Errore nell'apertura del file %s\n", nomeFile);
        return;
    }

    // Non usare while (!feof(fp)): si controlla il risultato della lettura.
    while (fgets(riga, sizeof(riga), fp) != NULL)
    {
        printf("%s", riga);
    }

    fclose(fp);
}

int CaricaInteriDaFile(const char nomeFile[], int vettore[], int dimensione)
{
    FILE *fp;
    int numeroElementi;

    fp = fopen(nomeFile, "r");
    if (fp == NULL)
    {
        printf("Errore nell'apertura del file %s\n", nomeFile);
        return 0;
    }

    numeroElementi = 0;

    // Gli interi possono essere separati da spazi oppure da caratteri a capo.
    while (numeroElementi < dimensione &&
           fscanf(fp, "%d", &vettore[numeroElementi]) == 1)
    {
        numeroElementi++;
    }

    fclose(fp);
    return numeroElementi;
}

int CaricaStudentiDaFile(const char nomeFile[], Studente studenti[], int dimensione)
{
    FILE *fp;
    int numeroStudenti;

    fp = fopen(nomeFile, "r");
    if (fp == NULL)
    {
        printf("Errore nell'apertura del file %s\n", nomeFile);
        return 0;
    }

    numeroStudenti = 0;

    /*
        Formato di ogni riga:
        matricola cognome nome classe specializzazione

        Le dimensioni in %49s, %9s e %19s impediscono di superare
        lo spazio disponibile negli array della struttura.
    */
    while (numeroStudenti < dimensione &&
           fscanf(fp, "%d %49s %49s %9s %19s",
                  &studenti[numeroStudenti].matricola,
                  studenti[numeroStudenti].cognome,
                  studenti[numeroStudenti].nome,
                  studenti[numeroStudenti].classe,
                  studenti[numeroStudenti].specializzazione) == 5)
    {
        numeroStudenti++;
    }

    fclose(fp);
    return numeroStudenti;
}

int AggiungiStudenteAlFile(const char nomeFile[], const Studente *studente)
{
    FILE *fp;

    fp = fopen(nomeFile, "a");
    if (fp == NULL)
    {
        printf("Errore nell'apertura del file %s\n", nomeFile);
        return 0;
    }

    fprintf(fp, "%d %s %s %s %s\n",
            studente->matricola,
            studente->cognome,
            studente->nome,
            studente->classe,
            studente->specializzazione);

    fclose(fp);
    return 1;
}
