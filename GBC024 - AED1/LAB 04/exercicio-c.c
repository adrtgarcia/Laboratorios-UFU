#include <stdio.h>
#include <stdlib.h>

void swap (int *a, int *b);
void invertevetor (int *vetor, int tamanho);

int main ( )
{
    int *vet, tam, num, i;

    vet = (int *) calloc (1, (sizeof(int)));
    if (vet == NULL)
    {
        printf ("erro de alocacao de memoria");
        return 0;
    }

    printf ("digite os elementos do vetor (negativo encerra):\n");
    tam = 0;

    while (1)
    {
        printf ("numero %d: ", (tam + 1));
        scanf ("%d", &num);

        if (num < 0)
        {
            printf ("\nencerrando leitura...");
            break;
        }

        vet[tam] = num;
        tam++;

        vet = (int *) realloc (vet, (tam * (sizeof(int))));
        if (vet == NULL)
        {
            printf ("\nerro na alocacao de memoria");
            return 0;
        }
    }

    printf ("\n\nvetor lido:");
    printf ("\nvet[");
    for (i = 0; i < tam; i++)
    {
        printf (" %d ", vet[i]);
    }
    printf ("]");

    invertevetor (vet, tam);

    printf ("\n\nnovo vetor:");
    printf ("\nvet[");
    for (i = 0; i < tam; i++)
    {
        printf (" %d ", vet[i]);
    }
    printf ("]");

    free(vet);

    return 0;
}

void swap (int *a, int *b)
{
    int temp;

    temp = *b;
    *b = *a;
    *a = temp;
}

void invertevetor (int *vetor, int tamanho)
{
    int i, j;

    for (i = 0; i < tamanho; i++)
    {
        for (j = (i + 1); j < tamanho; j++)
        {
            swap (&vetor[i], &vetor[j]);
        }
    }
}
