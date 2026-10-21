#include <stdio.h>
#include <string.h>

#define MAX_ELEMENTI 100
#define DIM_STRINGA 50

typedef struct
{
    int matricola;
    char cognome[DIM_STRINGA];
    char nome[DIM_STRINGA];
} Studente;

void PulisciBufferInput(void);
void LeggiStringa(char stringa[], int dimensione);

void LeggiFilePerRighe(const char nomeFile[]);
int CaricaInteriDaFile(const char nomeFile[], int vettore[], int dimensione);
int CaricaStudentiDaFile(const char nomeFile[], Studente studenti[], int dimensione);

void ScambiaInteri(int *primo, int *secondo);
void BubbleSortInteri(int vettore[], int dimensione);
int RicercaBinariaInteri(const int vettore[], int dimensione, int valoreCercato);

void ScambiaStringhe(char prima[], char seconda[]);
void BubbleSortStringhe(char vettore[][DIM_STRINGA], int dimensione);
int RicercaBinariaStringhe(char vettore[][DIM_STRINGA], int dimensione,
                           const char stringaCercata[]);

void ScambiaStudenti(Studente *primo, Studente *secondo);
void BubbleSortStudentiPerCognome(Studente studenti[], int dimensione);
int RicercaBinariaStudentePerCognome(const Studente studenti[], int dimensione,
                                     const char cognomeCercato[]);

int main(void)
{
    /*
        Questo main contiene esempi da copiare o togliere dai commenti.
        Per la ricerca binaria, il vettore DEVE essere gia' ordinato
        usando lo stesso criterio della ricerca.
    */

    /* INPUT DI UN INTERO E DI UNA STRINGA

    int numero;
    char nome[DIM_STRINGA];

    printf("Inserisci un numero: ");
    if (scanf("%d", &numero) != 1)
    {
        printf("Valore non valido\n");
        PulisciBufferInput();
        return 1;
    }

    // scanf lascia '\n' nel buffer: pulirlo prima di usare fgets.
    PulisciBufferInput();

    printf("Inserisci un nome: ");
    LeggiStringa(nome, DIM_STRINGA);
    */

    /* LETTURA DI UN FILE UNA RIGA ALLA VOLTA

    LeggiFilePerRighe("testo.txt");
    */

    /* BUBBLE SORT E RICERCA BINARIA SU INTERI

    int numeri[] = {32, 7, 18, 4, 25};
    int dimensioneNumeri = sizeof(numeri) / sizeof(numeri[0]);
    int posizione;

    BubbleSortInteri(numeri, dimensioneNumeri);
    posizione = RicercaBinariaInteri(numeri, dimensioneNumeri, 18);

    if (posizione != -1)
        printf("Numero trovato in posizione %d\n", posizione);
    else
        printf("Numero non trovato\n");
    */

    /* BUBBLE SORT E RICERCA BINARIA SU STRINGHE

    char nomi[][DIM_STRINGA] = {"Luca", "Anna", "Marco", "Giulia"};
    int dimensioneNomi = sizeof(nomi) / sizeof(nomi[0]);
    int posizione;

    BubbleSortStringhe(nomi, dimensioneNomi);
    posizione = RicercaBinariaStringhe(nomi, dimensioneNomi, "Marco");

    if (posizione != -1)
        printf("Stringa trovata in posizione %d\n", posizione);
    else
        printf("Stringa non trovata\n");
    */

    /* LETTURA, BUBBLE SORT E RICERCA SU STRUTTURE

    Formato di Studenti.txt, una struttura per riga:
    101 Rossi Mario
    102 Bianchi Anna
    103 Verdi Luca

    Studente studenti[MAX_ELEMENTI];
    int numeroStudenti;
    int posizione;

    numeroStudenti = CaricaStudentiDaFile("Studenti.txt", studenti, MAX_ELEMENTI);

    // Ordina per cognome prima della ricerca binaria per cognome.
    BubbleSortStudentiPerCognome(studenti, numeroStudenti);
    posizione = RicercaBinariaStudentePerCognome(studenti, numeroStudenti, "Rossi");

    if (posizione != -1)
    {
        printf("Matricola: %d\n", studenti[posizione].matricola);
        printf("Cognome: %s\n", studenti[posizione].cognome);
        printf("Nome: %s\n", studenti[posizione].nome);
    }
    else
    {
        printf("Studente non trovato\n");
    }
    */

    return 0;
}

void PulisciBufferInput(void)
{
    int carattere;

    /*
        Usare questa funzione dopo scanf e prima di fgets, per eliminare
        il carattere '\n' rimasto nel buffer. Serve anche dopo uno scanf
        fallito, per eliminare i caratteri non validi.

        Non usare fflush(stdin): sullo standard C ha comportamento indefinito.
    */
    do
    {
        carattere = getchar();
    }
    while (carattere != '\n' && carattere != EOF);
}

void LeggiStringa(char stringa[], int dimensione)
{
    if (fgets(stringa, dimensione, stdin) != NULL)
    {
        if (strchr(stringa, '\n') != NULL)
        {
            stringa[strcspn(stringa, "\n")] = '\0';
        }
        else
        {
            // La stringa era troppo lunga: elimina dal buffer i caratteri rimasti.
            PulisciBufferInput();
        }
    }
}

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

    // Non usare while (!feof(fp)): feof diventa vero solo dopo una lettura fallita.
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

    /*
        Formato del file: un intero dopo l'altro, separato da spazi o a capo.
        Il ciclo termina se il file finisce, se trova un dato non intero
        oppure se il vettore e' pieno.
    */
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
        %49s impedisce di scrivere oltre i 50 caratteri disponibili.
        Con %s cognome e nome non possono contenere spazi.
    */
    while (numeroStudenti < dimensione &&
           fscanf(fp, "%d %49s %49s",
                  &studenti[numeroStudenti].matricola,
                  studenti[numeroStudenti].cognome,
                  studenti[numeroStudenti].nome) == 3)
    {
        numeroStudenti++;
    }

    fclose(fp);
    return numeroStudenti;
}

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

int RicercaBinariaInteri(const int vettore[], int dimensione, int valoreCercato)
{
    int sinistra;
    int destra;
    int centro;

    sinistra = 0;
    destra = dimensione - 1;

    while (sinistra <= destra)
    {
        centro = sinistra + (destra - sinistra) / 2;

        if (vettore[centro] == valoreCercato)
            return centro;

        if (vettore[centro] < valoreCercato)
            sinistra = centro + 1;
        else
            destra = centro - 1;
    }

    return -1;
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
            // strcmp restituisce un valore maggiore di 0 se la prima viene dopo.
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

int RicercaBinariaStringhe(char vettore[][DIM_STRINGA], int dimensione,
                           const char stringaCercata[])
{
    int sinistra;
    int destra;
    int centro;
    int confronto;

    sinistra = 0;
    destra = dimensione - 1;

    while (sinistra <= destra)
    {
        centro = sinistra + (destra - sinistra) / 2;
        confronto = strcmp(vettore[centro], stringaCercata);

        if (confronto == 0)
            return centro;

        if (confronto < 0)
            sinistra = centro + 1;
        else
            destra = centro - 1;
    }

    return -1;
}

void ScambiaStudenti(Studente *primo, Studente *secondo)
{
    Studente temporaneo;

    // Copiando la struttura vengono copiati insieme tutti i suoi campi.
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
                // Lo swap scambia l'intero elemento della struttura.
                ScambiaStudenti(&studenti[i], &studenti[i + 1]);
                scambio = 1;
            }
        }

        ultimo--;
    }
    while (scambio == 1 && ultimo > 0);
}

int RicercaBinariaStudentePerCognome(const Studente studenti[], int dimensione,
                                     const char cognomeCercato[])
{
    int sinistra;
    int destra;
    int centro;
    int confronto;

    sinistra = 0;
    destra = dimensione - 1;

    while (sinistra <= destra)
    {
        centro = sinistra + (destra - sinistra) / 2;
        confronto = strcmp(studenti[centro].cognome, cognomeCercato);

        if (confronto == 0)
            return centro;

        if (confronto < 0)
            sinistra = centro + 1;
        else
            destra = centro - 1;
    }

    return -1;
}
