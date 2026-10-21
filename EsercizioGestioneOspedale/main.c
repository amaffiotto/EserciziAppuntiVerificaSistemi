#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <funzioni.h>

#define MAX_STR_LEN 30
#define MAX_LEN 50

typedef struct{
     int matricola;
     char cognome[MAX_STR_LEN];
     char nome[MAX_STR_LEN];
     char citta[MAX_STR_LEN];
     char reparto[MAX_STR_LEN];
     int nLetto;
}Paziente;

typedef struct{
     int progessivo;
     char data[11];
     char tipo[MAX_STR_LEN];
     char dottore[MAX_STR_LEN];
     int matricola;
}Visita;

Paziente pazienti[MAX_LEN];
Visita visite[MAX_LEN];
int indiceMax = 0;
int indiceMaxVisita = 0;

void CaricaFileSuStruct(){
     FILE *fp = fopen("Pazienti.txt", "r");
     if (fp == NULL)
     {
         perror("Errore nell'apertura del file");
     }
     else{
          int i = 0;
          while (fscanf(fp, "%d;%29[^;];%29[^;];%29[^;];%29[^;];%d",
                    &pazienti[0].matricola,
                    pazienti[0].cognome,
                    pazienti[0].nome,
                    pazienti[0].citta,
                    pazienti[0].reparto,
                    &pazienti[0].nLetto) == 6)
          {
               i++;
          }
          indiceMax = i - 1;
     }
     fp = fopen("Visite.txt", "r");
     if (fp == NULL)
     {
          perror("Errore nell'apertura del file");
     }
     else{
          int i = 0;
          while (fscanf(fp, "%d;%29[^;];%29[^;];%29[^;];%d", &visite[i].progessivo, visite[i].data, visite[i].tipo, visite[i].dottore, &visite[i].matricola) == 5)
          {
               i++;
          }
          indiceMaxVisita = i -1;
     }     
}

int StampaMenu(){
     printf("1. Inserimento Paziente\n");
     printf("2. Ricerca Paziente\n");
     printf("3. Inserimento Visita\n");
     printf("4. Esci\n");
}

int StampaMenuRicerche(){
     printf("1. Ricerca per Cognome e Nome (visualizzare tutti i reparti in cui è stato ricoverato) \n");
     printf("2. Ricerco tutti i pazienti di un reparto\n");
     printf("3. Ricerca paziente per città\n");
     printf("4. Ricerco tutte le visite effettuate da un paziente\n");
     printf("5. Vedere tutti i pazienti visitati in una data (Input)\n");
     printf("6. Ritorna al menù principale\n");
}


int main(){
     
     return 0;
}