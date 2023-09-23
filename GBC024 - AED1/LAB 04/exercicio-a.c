#include <stdio.h>
#include <stdlib.h>

void analisavetor (int *vet, int tamanho, float *media, int *maior);

int main ( )
{
    int *vet = NULL, tam, num, maior, i;
    float media;

    vet = (int *) calloc (1, (sizeof(int)));
    if (vet == NULL)
    {
        printf ("erro na alocacao de memoria");
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

    analisavetor (vet, tam, &media, &maior);

    printf ("\n\na media dos valores do vetor eh %.2f", media);
    printf ("\no maior valor do vetor eh %d", maior);

    free(vet);

    return 0;
}

void analisavetor (int *vet, int tamanho, float *media, int *maior)
{
    int i;
    *media = 0.0;

    for (i = 0; i < tamanho; i++)
    {
        *media += vet[i];
    }

    *media /= (tamanho * 1.0);
    *maior = vet[0];

    for (i = 0; i < tamanho; i++)
    {
        if (vet[i] > *maior)
        {
            *maior = vet[i];
        }
    }
}
