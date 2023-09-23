#include <stdio.h>

int main ( )
{
    int vet[10], cont;
    int *p = NULL, *pmin = NULL, *pmax = NULL;

    printf ("digite os valores do vetor:\n");

    for (p = vet, pmin = vet, pmax = vet, cont = 0; p < vet + 10; p++, cont++)
    {
        printf ("vetor[%d] = ", cont);
        scanf ("%d", p);

        if (*p > *pmax)
        {
            pmax = p;
        }

        if (*p < *pmin)
        {
            pmin = p;
        }
    }

    printf ("\nmaior valor: %d", *pmax);
    printf ("\nmenor valor: %d", *pmin);

    return 0;
}