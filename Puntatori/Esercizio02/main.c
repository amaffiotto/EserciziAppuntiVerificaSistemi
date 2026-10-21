#include <stdio.h>
#include <stdlib.h>

int main(){
    char c;
    int n;

    char *pc;
    int *pn;

    printf("\n ==============================\nEsercizio 2: Gestione puntatori in base al tipo\n==============================\n\n");
    pc = &c;
    pn = &n;

    *pc = 'A';
    *pn = 9;

    for (int i = 0; i < *pn; i++)
    {
        printf("\n- %c", *pc);
    }
    

    printf("\n\n\n");
    return 0;
}