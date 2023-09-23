#include <stdio.h>

int main ( )
{
    int vet[5] = {0, 1, 2, 3, 4}, i;
    int *p = NULL;

    p = vet;

    printf ("vetor original: vet[");
    for (i = 0; i < 5; i++)
    {
        printf (" %d ", vet[i]);
    }
    printf ("]");

    printf ("\nvetor final: vet[");
    for (i = 0; i < 5; i++)
    {
        (*p)++;
        printf (" %d ", *p);
        p++;
    }
    printf ("]");

    return 0;
}