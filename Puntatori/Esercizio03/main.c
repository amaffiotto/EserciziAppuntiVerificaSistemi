#include <stdio.h>
#include <stdlib.h>

int main(){
    printf("\n===================\nEsercizio 3: Gestione di vettori con puntatori\n===================\n");
    
    int vet[5] = {10,20,30,40,50};
    int *p;

    p = vet;

    for(int i = 0; i < 5; i++){
        printf("\n elemento %d: %d", i, *p);
        p++;
    }

    printf("\n\n");
    return 0;
}