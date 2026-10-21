#include <stdio.h>
#include "gestione_file.h"
#include "input.h"
#include "ordinamenti.h"
#include "ricerche.h"
#include "tipi.h"

void StampaInteri(const int vettore[], int dimensione);
void StampaStringhe(const char vettore[][DIM_STRINGA], int dimensione);

int main(void)
{
    int numeri[] = {32, 7, 18, 4, 25};
    char nomi[][DIM_STRINGA] = {"Luca", "Anna", "Marco", "Giulia"};
    int dimensioneNumeri;
    int dimensioneNomi;
    int posizione;
    Studente studenti[MAX_ELEMENTI];
    int numeroStudenti;

    dimensioneNumeri = sizeof(numeri) / sizeof(numeri[0]);
    dimensioneNomi = sizeof(nomi) / sizeof(nomi[0]);

    BubbleSortInteri(numeri, dimensioneNumeri);
    StampaInteri(numeri, dimensioneNumeri);

    posizione = RicercaBinariaInteri(numeri, dimensioneNumeri, 18);
    printf("Posizione del numero 18: %d\n\n", posizione);

    BubbleSortStringhe(nomi, dimensioneNomi);
    StampaStringhe(nomi, dimensioneNomi);

    posizione = RicercaBinariaStringhe(nomi, dimensioneNomi, "Marco");
    printf("Posizione di Marco: %d\n\n", posizione);

    numeroStudenti = CaricaStudentiDaFile("Studenti.txt",
                                          studenti,
                                          MAX_ELEMENTI);
    BubbleSortStudentiPerCognome(studenti, numeroStudenti);
    posizione = RicercaBinariaStudentePerCognome(studenti,
                                                  numeroStudenti,
                                                  "Rossi");

    if (posizione != -1)
    {
        printf("Studente trovato: %d %s %s %s %s\n",
               studenti[posizione].matricola,
               studenti[posizione].cognome,
               studenti[posizione].nome,
               studenti[posizione].classe,
               studenti[posizione].specializzazione);
    }

    /* ESEMPIO INPUT

    int scelta;
    char testo[DIM_STRINGA];

    printf("Inserisci un numero: ");
    if (scanf("%d", &scelta) != 1)
    {
        printf("Valore non valido\n");
        PulisciBufferInput();
        return 1;
    }

    // scanf lascia '\n': pulire il buffer prima di chiamare fgets.
    PulisciBufferInput();

    printf("Inserisci una stringa: ");
    LeggiStringa(testo, DIM_STRINGA);
    */

    /* ESEMPIO FILE DI INTERI

    int valori[MAX_ELEMENTI];
    int numeroValori;

    numeroValori = CaricaInteriDaFile("numeri.txt", valori, MAX_ELEMENTI);
    BubbleSortInteri(valori, numeroValori);
    posizione = RicercaBinariaInteri(valori, numeroValori, 25);
    */

    /* VERSIONE DA COPIARE: FILE E RICERCA SU STRUTTURE

    Studente studenti[MAX_ELEMENTI];
    int numeroStudenti;

    numeroStudenti = CaricaStudentiDaFile("Studenti.txt",
                                          studenti,
                                          MAX_ELEMENTI);

    // La ricerca binaria per cognome richiede prima lo stesso ordinamento.
    BubbleSortStudentiPerCognome(studenti, numeroStudenti);
    posizione = RicercaBinariaStudentePerCognome(studenti,
                                                  numeroStudenti,
                                                  "Rossi");

    if (posizione != -1)
    {
        printf("%d %s %s %s %s\n",
               studenti[posizione].matricola,
               studenti[posizione].cognome,
               studenti[posizione].nome,
               studenti[posizione].classe,
               studenti[posizione].specializzazione);
    }
    */

    return 0;
}

void StampaInteri(const int vettore[], int dimensione)
{
    int i;

    for (i = 0; i < dimensione; i++)
    {
        printf("%d ", vettore[i]);
    }
    printf("\n");
}

void StampaStringhe(const char vettore[][DIM_STRINGA], int dimensione)
{
    int i;

    for (i = 0; i < dimensione; i++)
    {
        printf("%s ", vettore[i]);
    }
    printf("\n");
}
