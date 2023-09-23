#include <stdio.h>
#include <stdlib.h>

int main ( )
{
    int *p = NULL, i, j;

    printf ("digite o tamanho do vetor: ");
    scanf ("%d", &i);

    p = (int *) calloc (i, (sizeof(int)));

    if (p == NULL)
    {
        printf ("\nerro: memoria insuficiente");
        exit(1);
    }

    printf ("\ndigite os valores do vetor:\n");
    for (j = 0; j < i; j++)
    {
        printf ("vet[%d] = ", j);
        scanf ("%d", &p[j]);
    }

    printf ("\nvetor lido:");
    printf ("\nvet[");
    for (j = 0; j < i; j++)
    {
        printf (" %d ", *(p + j));
    }
    printf ("]");

    free(p);

    return 0;
}