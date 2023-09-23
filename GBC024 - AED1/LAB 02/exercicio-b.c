#include <stdio.h>
#include <stdlib.h>

int main ( )
{
    int *vet = NULL, i;

    vet = (int *) calloc (5, (sizeof(int)));
    if (vet == NULL)
    {
        printf ("erro na alocacao de memoria");
        return 0;
    }

    printf ("digite os valores do vetor:\n");
    for (i = 0; i < 5; i++)
    {
        printf ("vet[%d] = ", i);
        scanf ("%d", &vet[i]);
    }

    printf ("\nvetor registrado:");
    printf ("\nvet[ ");
    for (i = 0; i < 5; i++)
    {
        printf (" %d ", *(vet + i));
    }
    printf ("]");

    free(vet);

    return 0;
}
