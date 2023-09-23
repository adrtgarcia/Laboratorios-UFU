#include <stdio.h>
#include <stdlib.h>

void multiplicar (int *vetor, int tamanho, int numero);

int main ( )
{
    int *vet, num, tam, i;

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

    printf ("\n\ndigite um valor: ");
    scanf ("%d", &num);

    printf ("\n\nvetor lido:");
    printf ("\nvet[");
    for (i = 0; i < tam; i++)
    {
        printf (" %d ", vet[i]);
    }
    printf ("]");

    multiplicar (vet, tam, num);

    printf ("\n\nvetor final:");
    printf ("\nvet[");
    for (i = 0; i < tam; i++)
    {
        printf (" %d ", vet[i]);
    }
    printf ("]");

    free(vet);

    return 0;
}

void multiplicar (int *vetor, int tamanho, int numero)
{
    int i;

    for (i = 0; i < tamanho; i++)
    {
        vetor[i] *= numero;
    }
}
