#ifndef FUNZIONI_H
#define FUNZIONI_H

#include <errno.h>
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

static inline void clrscr(void)
{
    printf("\033[2J\033[H");
    fflush(stdout);
}

static inline int gotoxy(short X, short Y)
{
    if (X < 0 || Y < 0)
        return 1;

    printf("\033[%d;%dH", Y + 1, X + 1);
    fflush(stdout);

    return 0;
}

static inline void randomize(void)
{
    srand((unsigned int)time(NULL));
}

static inline int randomNumber(int NumMax)
{
    if (NumMax <= 0)
        return 0;

    return rand() % NumMax;
}

static inline void textcolor(unsigned short color)
{
    static const int coloriAnsi[8] = {
        30, 34, 32, 36, 31, 35, 33, 37
    };

    int codice = coloriAnsi[color & 7];

    if (color & 8)
        codice += 60;

    printf("\033[%dm", codice);
    fflush(stdout);
}

static inline void delay(int MilliSecondi)
{
    if (MilliSecondi <= 0)
        return;

    struct timespec attesa;
    struct timespec rimanente;

    attesa.tv_sec = MilliSecondi / 1000;
    attesa.tv_nsec = (MilliSecondi % 1000) * 1000000L;

    while (nanosleep(&attesa, &rimanente) == -1 && errno == EINTR)
        attesa = rimanente;
}

static inline void textbackground(unsigned short color)
{
    static const int coloriAnsi[8] = {
        40, 44, 42, 46, 41, 45, 43, 47
    };

    int codice = coloriAnsi[color & 7];

    if (color & 8)
        codice += 60;

    printf("\033[%dm", codice);
    fflush(stdout);
}

static inline void resetcolor(void)
{
    printf("\033[0m");
    fflush(stdout);
}

static inline void bubble(int *vect, int lunghezza)
{
    int n;
    int scambio;
    int i;
    int aus;

    n = lunghezza - 1;

    do
    {
        scambio = 0;

        for (i = 0; i < n; i++)
        {
            if (vect[i] > vect[i + 1])
            {
                aus = vect[i];
                vect[i] = vect[i + 1];
                vect[i + 1] = aus;
                scambio = 1;
            }
        }

        n--;
    }
    while (scambio == 1);
}

#endif