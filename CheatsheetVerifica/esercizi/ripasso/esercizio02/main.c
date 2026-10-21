#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "funzioni.h"

// Studenti.txt
// NMATR Cognome Nome Classe Specializzazione

void DisegnaMenu(void);
void Attesa(void);
void LeggiStringa(char testo[], int dimensione);

void InserisciStudente(void);
void RicercaStudente(void);
void RicercaClasse();

int main(void)
{
    int scelta;
    FILE *fp;

    fp = fopen("Studenti.txt", "a");
    if (fp == NULL)
    {
        printf("Errore nell'apertura del file Studenti.txt\n");
        return 1;
    }
    fclose(fp);

    // MENU

    do
    {
        DisegnaMenu();
        if (scanf("%d", &scelta) != 1)
        {
            scelta = -1;
        }
        while (getchar() != '\n');

        switch (scelta)
        {
        case 1:
            InserisciStudente();
            break;
        case 2:
            RicercaStudente();
            break;
        case 3:
            RicercaClasse();
            break;
        default:
            break;
        }
        if (scelta != 0)
        {
            Attesa();
        }
        
    } while (scelta != 0);

    return 0;
}

void DisegnaMenu(void){
    clrscr();
    printf("=== Esercizio 2 - Gestione file studenti ===\n");
    printf("1 - Inserimento nuovo studente\n");
    printf("2 - Ricerca Studente per Cognome/Nome\n");
    printf("3 - Visualizza gli studenti per classe\n");
    printf("4* - Visualizza file studenti\n");
    printf("5 - Modifica Studente\n");
    printf("6 - Elimina studente\n\n");
    printf("0 - Esci\n================================\n");
    printf("\n\n nScelta ===> ");
}

void Attesa(void){
    printf("\nPremi INVIO per continuare...");
    getchar();
}

void LeggiStringa(char testo[], int dimensione)
{
    fgets(testo, dimensione, stdin);
    testo[strcspn(testo, "\n")] = '\0';
}

void InserisciStudente(void)
{
    FILE *fp;
    char matricola[20];
    char cognome[50];
    char nome[50];
    char classe[20];
    char specializzazione[50];

    clrscr();
    printf("=== Inserimento nuovo studente ===\n\n");

    printf("Matricola: ");
    LeggiStringa(matricola, 20);

    printf("Cognome: ");
    LeggiStringa(cognome, 50);

    printf("Nome: ");
    LeggiStringa(nome, 50);

    printf("Classe: ");
    LeggiStringa(classe, 20);

    printf("Specializzazione: ");
    LeggiStringa(specializzazione, 50);

    fp = fopen("Studenti.txt", "a");
    if (fp == NULL)
    {
        printf("\nErrore nell'apertura del file Studenti.txt\n");
        return;
    }

    fprintf(fp, "%s %s %s %s %s\n", matricola, cognome, nome, classe, specializzazione);

    fclose(fp);

    printf("\nStudente inserito correttamente.\n");
}

void RicercaStudente(void)
{
    FILE *fp;
    char cognomeRicerca[50];
    char nomeRicerca[50];
    char matricola[20];
    char cognome[50];
    char nome[50];
    char classe[20];
    char specializzazione[50];
    int trovato;

    clrscr();
    printf("=== Ricerca studente ===\n\n");

    printf("Cognome: ");
    LeggiStringa(cognomeRicerca, 50);

    printf("Nome: ");
    LeggiStringa(nomeRicerca, 50);

    fp = fopen("Studenti.txt", "r");
    if (fp == NULL)
    {
        printf("\nErrore nell'apertura del file Studenti.txt\n");
        return;
    }

    trovato = 0;

    while (fscanf(fp, "%19s %49s %49s %19s %49s",
                  matricola, cognome, nome, classe, specializzazione) == 5)
    {
        if (strcmp(cognome, cognomeRicerca) == 0 &&
            strcmp(nome, nomeRicerca) == 0)
        {
            printf("\nStudente trovato:\n");
            printf("Matricola: %s\n", matricola);
            printf("Cognome: %s\n", cognome);
            printf("Nome: %s\n", nome);
            printf("Classe: %s\n", classe);
            printf("Specializzazione: %s\n", specializzazione);
            trovato = 1;
        }
    }

    fclose(fp);

    if (trovato == 0)
    {
        printf("\nStudente non trovato.\n");
    }

}

void RicercaClasse(){
    FILE *fp;
    int nm = 0;
    char cogn[20+1], nome[20+1];
    char cl[2+1], spec[3+1];

    char ricClasse[2+1];

    clrscr();
    printf("\nInserisci la classe da ricercare ===> ");
    fflush(stdin);
    gets(ricClasse);

    printf("");
}