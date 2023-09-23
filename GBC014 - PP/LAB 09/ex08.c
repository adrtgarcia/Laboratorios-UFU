#include <stdio.h>
#include <stdlib.h>

int main ( )
{
    int i, zeros = 0;
    int *vet = NULL;

    vet = (int *) calloc (1500, sizeof(int));
    if (vet == NULL) 
    {
        printf ("\nerro: memoria insuficiente");
        exit(1);
    }

    for (i = 0; i < 1500; i++) 
    {
        if (*(vet + i) == 0) 
        {
            zeros++;
        }
    }
    printf ("\nquantidade de zeros no vetor: %d", zeros);

    for (i = 0; i < 1500; i++) 
    {
        *(vet + i) = i;
    }

    printf ("\nlista dos primeiros 10 elementos:\n");
    for (i = 0; i < 10; i++) 
    {
        printf ("%d ", (*vet + i));
    }

    printf ("\nlista dos ultimos 10 elementos:\n");
    for (i = 1490; i < 1500; i++) 
    {
        printf ("%d ", *(vet + i));
    }

    free(vet);

    return 0;
}