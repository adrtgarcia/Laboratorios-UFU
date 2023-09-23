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

    printf ("\nvetor final:\n");
    printf ("[");

    for (i = 0; i < 5; i++)
    {
        *(p + i) *= 2;
        printf (" %d ", *(p + i));
    }

    printf ("]");

    return 0;
}