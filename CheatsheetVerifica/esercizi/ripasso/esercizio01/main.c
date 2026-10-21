#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(){
    FILE *fp; 
    char nome[30+1];

    fp = fopen("prova.txt", "w");
/*
    if(fp == NULL)
    {
        fclose(fp);
        fp = fopen("prova.txt", "w");
        printf("File creato con successo\n");
    }
    else
    {
        printf("il file esiste già\n");
    }
*/

    // INSERT
    printf("Inserisci il tuo nome ==> ");

    gets(nome);
    printf("\n");

    fprintf(fp, "%s", nome);

    fclose(fp);

    // READ - 1

    fp = fopen("prova.txt", "r");
    fscanf(fp, "%s", nome);
    fclose(fp);
    printf(" (Read 1) Nome: \"%s\" \n", nome);
    printf("\n\n");

    // READ - 2
    fp = fopen("prova.txt", "r");
    
    while (fgets(nome, 30, fp) != NULL)
    {
        printf(" (Read 2) Nome: \"%s\" \n", nome);
    }
    
    fclose(fp);
    printf("\n\n");


    // READ - 3
    fp = fopen("prova.txt", "r");
    while (!feof(fp))
    {
        fscanf(fp, "%s", nome);
        printf(" (Read 3) Nome: \"%s\" \n", nome);
    }
    fclose(fp);
    printf("\n\n");

    // Controllo file Elenco.txt
    char materia[30];

    fp = fopen("Elenco.txt", "r");
    if (fp == NULL)
    {
        fclose(fp);
        fp = fopen("Elenco.txt", "w");
    }
    fclose(fp);

    // Visualizzo eventuali materie
    printf("ELENCO MATERIE\n");
    fp = fopen("Elenco.txt", "r");
    while(!feof(fp)){
        fscanf(fp, "%s", materia);
        printf("- %s\n", materia);
    }
    fclose(fp);

    // Append

    fp = fopen("Elenco.txt", "a");
    
    do
    {
        printf("Inserisci una materia [FINE per concludere]\n");
        fflush(stdin);
        gets(materia);
        if(strcmp(materia, "FINE") != 0)
        {
            fputs(materia, fp);
            fputs("\n", fp);
        }
    } while (strcmp(materia, "FINE") != 0);
    fclose(fp);
    
    
    printf("\n\n");
    return 0;
}