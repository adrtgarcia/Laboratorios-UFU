#include <stdio.h>
#include <stdlib.h>

void encontramaior (int array[], int N, int *maior);

int main ( )
{
    int tamanho, k, i, maior;
    int *pm = NULL;

    pm = &maior;

    printf ("digite o tamanho do vetor: ");
    scanf ("%d", &tamanho);

    int *vetor = (int *)malloc(tamanho * sizeof(int));
    if (vetor == NULL) {
        printf("\nmemoria insuficiente");
        exit (1);
    }

    printf ("\ndigite os valores do vetor:\n");
    for (i = 0; i < tamanho; i++)
    {
        printf ("vetor[%d] = ", i);
        scanf ("%d", &vetor[i]);
    }

    *pm = vetor[0];

    printf ("\ndigite o numero de elementos por linha: ");
    scanf ("%d", &k);

    for (i = 0; i < tamanho; i++)
    {
        printf ("%d ", vetor[i]);

        if ((i + 1) % k == 0)
        {
            printf ("\n");
        }
    }

    encontramaior (vetor, tamanho, pm);
    printf ("\no maior elemento eh %d", *pm);

    free(vetor);

    return 0;
}

void encontramaior (int array[], int N, int *maior)
{
    int i;

    for (i = 0; i < N; i++)
    {
        if (array[i] > *maior)
        {
            *maior = array[i];
        }
    }
}