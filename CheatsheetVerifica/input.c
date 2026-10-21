#include <stdio.h>
#include <string.h>
#include "input.h"

void PulisciBufferInput(void)
{
    int carattere;

    /*
        Chiamare questa funzione dopo scanf e prima di fgets, per togliere
        il carattere '\n' rimasto nel buffer. Serve anche dopo uno scanf
        fallito, per eliminare i caratteri non validi.

        Non usare fflush(stdin): nello standard C il suo comportamento
        non e' definito.
    */
    do
    {
        carattere = getchar();
    }
    while (carattere != '\n' && carattere != EOF);
}

int LeggiStringa(char stringa[], int dimensione)
{
    if (fgets(stringa, dimensione, stdin) == NULL)
        return 0;

    if (strchr(stringa, '\n') != NULL)
    {
        stringa[strcspn(stringa, "\n")] = '\0';
    }
    else
    {
        // La riga era troppo lunga: elimina dal buffer i caratteri rimasti.
        PulisciBufferInput();
    }

    return 1;
}
