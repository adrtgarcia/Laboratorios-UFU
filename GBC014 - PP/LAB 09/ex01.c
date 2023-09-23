#include <stdio.h>
#include <stdlib.h>

int main ( )
{
    int *p = NULL, i;
    p = (int *) calloc (5, (sizeof(int)));

    if (p == NULL)
    {
        printf ("\nerro: memoria insuficiente");
        exit(1);
    }

    printf ("digite os valores do vetor:\n");
    for (i = 0; i < 5; i++)
    {
        printf ("vet[%d] = ", i);
        scanf ("%d", &p[i]);
    }

    printf ("\nvalores armazenados no vetor:");
    printf ("\nvet[");
    for (i = 0; i < 5; i++)
    {
        printf (" %d ", *(p + i));
    }
    printf ("]");

    free(p);

    return 0;
}