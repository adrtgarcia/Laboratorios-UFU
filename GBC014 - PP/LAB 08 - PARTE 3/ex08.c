#include <stdio.h>
#include <stdlib.h>

int negativos (float *vet, int N);

int main ( )
{
    int tamanho, i;
    int *pt = NULL;

    pt = &tamanho;

    printf ("informe o tamanho do vetor: ");
    scanf ("%d", pt);

    float *vet = (float *)malloc(tamanho * sizeof(float));
    if (vet == NULL) {
        printf("\nmemoria insuficiente");
        exit (1);
    }

    printf ("\ninforme os valores do vetor:\n");
    for (i = 0; i < tamanho; i++)
    {
        printf ("vetor[%d] = ", i);
        scanf ("%f", &vet[i]);
    }

    printf ("\nexistem %d numeros negativos nesse vetor", negativos(vet, *pt));

    free(vet);

    return 0;
}

int negativos (float *vet, int N)
{
    int quant = 0;

    for (int j = 0; j < N; j++)
    {
        if (vet[j] < 0)
        {
            quant++;
        }
    }

    return quant;
}