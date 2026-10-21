#include <stdio.h>
#include <stdlib.h>
#include "funzioni.h"

int main(){
    int N;
    int *p;

    printf("\n===================================");
    printf("\nEsercizio 1: Utilizzo dei puntatori");
    printf("\n===================================\n\n");

    N = 10;
    p = &N;

    printf("\n Valore di N: %d", N);
    printf("\n Valore di &N: %p", &N);
    printf("\n Valore di P: %p", p);
    printf("\n Valore di N puntato da P: %d", *p);

    printf("\n\n Cambio del contenuto di un puntatore");
    *p *= 2;
    printf("\n Valore di N puntato da P: %d", *p);
    
    
    printf("\n\n");
    return 0;
}