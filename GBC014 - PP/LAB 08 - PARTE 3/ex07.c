#include <stdio.h>
#include <stdlib.h>

void procuramaior (int n, int array[], int *maior, int *vezes);

int main ( )
{
    int N, i, maior, vezes;
    int *pn = NULL, *pm = NULL, *pv = NULL;

    pn = &N;
    pm = &maior;
    pv = &vezes;

    printf ("informe o tamanho do vetor: ");
    scanf ("%d", pn);

    int *vet = (int *)malloc(N * sizeof(int));
    if (vet == NULL) {
        printf("\nmemoria insuficiente");
        exit (1);
    }

    printf ("\ninforme os elementos do vetor:\n");
    for (i = 0; i < N; i++)
    {
        printf ("vet[%d] = ", i);
        scanf ("%d", &vet[i]);
    }

    maior = vet[0];
    vezes = 0;

    procuramaior (N, vet, pm, pv);
    printf ("%d eh o maior numero e aparece %d vezes", *pm, *pv);

    free(vet);

    return 0;
}

void procuramaior (int n, int array[], int *maior, int *vezes)
{
    for (int j = 0; j < n; j++)
    {
        if (array[j] > *maior)
        {
            *maior = array[j];
            *vezes = 1;
        } else if (array[j] == *maior) 
        {
            (*vezes)++;
        }
    }
}