#include <stdio.h>
#include <stdlib.h>

void minmax (int *V, int tamanho, int *min, int *max);

int main ( )
{
    int tamanho, min, max, i;
    int *pmin = NULL, *pmax = NULL;

    pmin = &min;
    pmax = &max;

    printf ("digite o tamanho do vetor: ");
    scanf ("%d", &tamanho);

    int *v = (int *)malloc(tamanho * sizeof(int));
    if (v == NULL) {
        printf("\nmemoria insuficiente");
        exit (1);
    }

    printf ("\ndigite os valores do vetor:\n");
    for (i = 0; i < tamanho; i++)
    {
        printf ("vetor[%d] = ", i);
        scanf ("%d", &v[i]);
    }

    minmax (v, tamanho, pmin, pmax);
    printf ("\nvalor minimo: %d", *pmin);
    printf ("\nvalor maximo: %d", *pmax);

    free(v);

    return 0;
}

void minmax (int *V, int tamanho, int *min, int *max)
{
    int i;

    *min = V[0];
    *max = V[0];

    for (i = 0; i < tamanho; i++)
    {
        if (V[i] < *min)
        {
            *min = V[i];
        }

        if (V[i] > *max)
        {
            *max = V[i];
        }
    }
}