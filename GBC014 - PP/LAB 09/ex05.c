#include <stdio.h>
#include <stdlib.h>

int main ( )
{
    int *p = NULL, n, x, i, quant;

    printf ("digite o tamanho do vetor: ");
    scanf ("%d", &n);
    p = (int *) calloc (n, (sizeof(int)));

    if (p == NULL)
    {
        printf ("\nerro: memoria insuficiente");
        exit(1);
    }

    printf ("\ndigite os valores do vetor:");
    for (i = 0; i < n; i++)
    {
        printf ("vet[%d] = ", i);
        scanf ("%d", &p[i]);
    }

    printf ("\ndigite um numero: ");
    scanf ("%d", &x);

    for (i = 0, quant = 0; i < n; i++)
    {
        if (p[i] % x == 0)
        {
            quant++;
        }
    }

    printf ("\nexistem %d multiplos de %d nesse vetor:\n", quant, x);
    for (i = 0; i < n; i++)
    {
        if (p[i] % x == 0)
        {
            printf ("%d ", p[i]);
        }
    }

    free(p);

    return 0;
}