#include <stdio.h>

int main ( )
{
    int vet[5];
    int *p = NULL;
    int i;

    p = vet;

    printf ("digite os valores do vetor:\n");

    for (i = 0; i < 5; i++)
    {
        printf ("vet[%d] = ", i);
        scanf ("%d", (p + i));
    }

    printf ("\nendereco dos valores pares:");

    for (i = 0; i < 5; i++)
    {
        if (*(p + i) % 2 == 0)
        {
            printf ("\nvet[%d] = %p", i, (p + i));
        }
    }

    return 0;
}