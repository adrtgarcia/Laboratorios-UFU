#include <stdio.h>      //printf, scanf
#include <stdlib.h>     //exit, srand, rand
#include <time.h>       //time

int main ( )
{
    int linha, i, coluna, j, **p = NULL;

    printf ("digite o numero de linhas: ");
    scanf ("%d", &linha);
    printf ("digite o numero de colunas: ");
    scanf ("%d", &coluna);

    p = (int **) calloc (linha, (sizeof(int *)));
    if (p == NULL)
    {
        printf ("\nerro: memoria insuficiente");
        exit(1);
    }

    srand (time(NULL));

    for (i = 0; i < linha; i++)
    {
        p[i] = (int *) calloc (coluna, (sizeof(int)));
        if (p[i] == NULL)
        {
            printf ("\nerro: memoria insuficiente");
            exit(1);
        }

        for (j = 0; j < coluna; j++)
        {
            p[i][j] = rand ( ) % 100;
        }
    }

    for (i = 0; i < linha; i++)
    {
        for (j = 0; j < coluna; j++)
        {
            printf (" %d ", p[i][j]);
        }

        printf ("\n");
    }

    for (j = 0; j < coluna; j++)
    {
        free(p[j]);
    }

    free(p);

    return 0;
}