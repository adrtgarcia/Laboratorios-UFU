#include <stdio.h>
#include <stdlib.h>

void alocarvetor (int tamanho, int valor);

int main ( )
{
    int tam, num;

    do
    {
        printf ("digite o tamanho do vetor: ");
        scanf ("%d", &tam);

        if (tam <= 0)
        {
            printf ("tamanho invalido\n\n");
        }

    } while (tam <= 0);

    printf ("digite o valor para preencher o vetor: ");
    scanf ("%d", &num);

    alocarvetor(tam, num);

    return 0;
}

void alocarvetor (int tamanho, int valor)
{
    int *vetor, i;

    vetor = (int *) calloc (tamanho, (sizeof(int)));
    if (vetor == NULL)
    {
        printf ("\nerro na alocacao de memoria");
        exit(1);
    }

    printf ("\nvetor criado:");
    printf ("\nvet[");
    for (i = 0; i < tamanho; i++)
    {
        vetor[i] = valor;
        printf (" %d ", vetor[i]);
    }
    printf ("]");

    free(vetor);
}
