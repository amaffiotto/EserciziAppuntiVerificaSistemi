# Cheatsheet C: file, ordinamenti e ricerche

## Struttura del progetto

- `main.c`: esempi di utilizzo già pronti;
- `input.c` / `input.h`: lettura sicura da tastiera e pulizia del buffer;
- `gestione_file.c` / `gestione_file.h`: apertura, lettura e scrittura dei file;
- `ordinamenti.c` / `ordinamenti.h`: Bubble Sort e funzioni di scambio;
- `ricerche.c` / `ricerche.h`: ricerca binaria;
- `tipi.h`: costanti e struttura `Studente`;
- `numeri.txt` e `Studenti.txt`: dati di esempio per provare la lettura da file;
- `esercizi`: copia dei sorgenti già presenti nelle cartelle `Ripasso` e `Puntatori`.

Per compilare la parte principale:

```sh
cc -std=c11 -Wall -Wextra -Wpedantic \
  main.c input.c gestione_file.c ordinamenti.c ricerche.c \
  -o cheatsheet
./cheatsheet
```

## Apertura dei file: `r`, `w`, `a` e varianti

| Modalità | Significato | Se il file non esiste | Se il file esiste | Posizione iniziale |
|---|---|---|---|---|
| `"r"` | sola lettura | `fopen` fallisce | contenuto conservato | inizio |
| `"w"` | sola scrittura | viene creato | contenuto cancellato | inizio |
| `"a"` | aggiunta | viene creato | contenuto conservato | fine per ogni scrittura |
| `"r+"` | lettura e scrittura | `fopen` fallisce | contenuto conservato | inizio |
| `"w+"` | lettura e scrittura | viene creato | contenuto cancellato | inizio |
| `"a+"` | lettura e aggiunta | viene creato | contenuto conservato | lettura all'inizio, scrittura in fondo |

La lettera `b` indica la modalità binaria: `"rb"`, `"wb"`, `"ab"`. Su sistemi Unix non cambia il trattamento del file, mentre su Windows evita la conversione dei caratteri di fine riga. Serve soprattutto con `fread` e `fwrite`.

Controllare sempre il risultato di `fopen` e chiudere il file quando non serve più:

```c
FILE *fp;

fp = fopen("dati.txt", "r");
if (fp == NULL)
{
    printf("Errore nell'apertura del file\n");
    return 1;
}

/* letture */

fclose(fp);
```

## Funzioni per leggere

### `scanf` e `fscanf`

`scanf` legge dalla tastiera, `fscanf` da un file. Sono comode quando i dati hanno campi separati da spazi:

```c
fscanf(fp, "%d %49s", &numero, parola);
```

Bisogna controllare quanti campi sono stati letti. Il ciclo corretto è:

```c
while (fscanf(fp, "%d", &numero) == 1)
{
    printf("%d\n", numero);
}
```

Non usare `while (!feof(fp))`: `feof` diventa vero soltanto dopo che una lettura ha già fallito e può far elaborare due volte l'ultimo dato.

Con `%s` la lettura termina al primo spazio. In `%49s`, `49` lascia un carattere libero per `\0` dentro un array da 50 caratteri.

### `gets` e `fgets`

`gets(stringa)` non conosce la dimensione dell'array: se l'utente scrive troppo, supera il buffer. È stata rimossa dallo standard C11 e non va usata.

`fgets` riceve la dimensione massima e quindi evita questo problema:

```c
char nome[50];

fgets(nome, sizeof(nome), stdin);
nome[strcspn(nome, "\n")] = '\0';
```

`fgets` conserva il carattere `\n` se trova spazio nell'array. La funzione `LeggiStringa` presente in `input.c` lo elimina e svuota anche il resto della riga se l'utente ha scritto troppo.

Per leggere un file riga per riga:

```c
while (fgets(riga, sizeof(riga), fp) != NULL)
{
    printf("%s", riga);
}
```

### `fgetc`

Legge un solo carattere e restituisce un `int`, perché deve poter restituire anche `EOF`:

```c
int carattere;

while ((carattere = fgetc(fp)) != EOF)
{
    putchar(carattere);
}
```

### `fread`

Legge blocchi di byte e si usa normalmente con file binari:

```c
fread(vettore, sizeof(int), dimensione, fp);
```

Il valore restituito è il numero di elementi letti, non il numero di byte.

## Funzioni per scrivere

- `printf`: output formattato sul terminale;
- `fprintf`: output formattato su un file;
- `puts`: scrive una stringa sul terminale e aggiunge `\n`;
- `fputs`: scrive una stringa su un file e non aggiunge automaticamente `\n`;
- `fputc`: scrive un carattere;
- `fwrite`: scrive blocchi di dati binari.

Esempio in aggiunta:

```c
fp = fopen("Studenti.txt", "a");
fprintf(fp, "%d %s %s\n", studente.matricola,
        studente.cognome, studente.nome);
fclose(fp);
```

## Buffer di input

Dopo `scanf`, il carattere Invio rimane normalmente nel buffer. Se subito dopo si usa `fgets`, questo legge l'Invio e sembra restituire una stringa vuota:

```c
scanf("%d", &numero);
PulisciBufferInput();
LeggiStringa(nome, DIM_STRINGA);
```

La pulizia serve anche dopo uno `scanf` fallito. Non chiamarla automaticamente dopo ogni `fgets`: `fgets` consuma già `\n` quando la riga entra completamente nell'array. Non usare `fflush(stdin)`, perché lo standard C definisce `fflush` per i flussi di output, non per pulire l'input.

## Bubble Sort

Il Bubble Sort confronta elementi adiacenti e li scambia quando sono nell'ordine sbagliato. A ogni passaggio l'elemento più grande arriva verso la fine. Nel codice, `ultimo` diminuisce perché la parte finale è già ordinata e `scambio` permette di terminare prima se non è cambiato nulla.

Con gli interi si usa `>`; con stringhe e campi testuali si usa `strcmp`:

```c
if (strcmp(prima, seconda) > 0)
{
    /* prima viene alfabeticamente dopo seconda */
}
```

Per una struttura bisogna scambiare l'intero record. Scambiare soltanto il cognome separerebbe il cognome dagli altri dati dello studente:

```c
void ScambiaStudenti(Studente *primo, Studente *secondo)
{
    Studente temporaneo;

    temporaneo = *primo;
    *primo = *secondo;
    *secondo = temporaneo;
}
```

## Ricerca binaria

La ricerca binaria controlla l'elemento centrale e scarta metà vettore a ogni passaggio. Restituisce l'indice trovato oppure `-1`.

Il requisito fondamentale è che il vettore sia già ordinato con lo stesso criterio usato nella ricerca:

```c
BubbleSortStudentiPerCognome(studenti, numeroStudenti);
posizione = RicercaBinariaStudentePerCognome(studenti,
                                              numeroStudenti,
                                              "Rossi");
```

Se si ordina per cognome ma si cerca per matricola, la ricerca binaria non funziona. Bisogna prima ordinare per matricola oppure usare una ricerca sequenziale.

La ricerca sequenziale non richiede ordinamento, ma nel caso peggiore controlla tutti gli elementi. La ricerca binaria è più veloce su vettori grandi, ma richiede l'ordinamento.

## Puntatori e strutture

L'operatore `&` ottiene l'indirizzo di una variabile, mentre `*` accede al valore presente a quell'indirizzo:

```c
int numero = 10;
int *p = &numero;

*p = 20;  /* modifica anche numero */
```

Con un puntatore a struttura, `studente->nome` equivale a `(*studente).nome`. Le funzioni di scambio ricevono puntatori perché devono modificare gli elementi originali del vettore.

## Nota sugli esercizi copiati

Gli esercizi nella sottocartella sono copie dei sorgenti esistenti e non sono stati riscritti. Alcuni contengono costrutti vecchi come `gets`, `fflush(stdin)` e `while (!feof(...))`: sono conservati come materiale originale, ma per nuovo codice vanno preferiti gli esempi sicuri della parte principale e le regole spiegate sopra.
