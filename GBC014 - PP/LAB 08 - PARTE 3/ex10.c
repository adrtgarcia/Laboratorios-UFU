#include <stdio.h>
#include <stdlib.h>

int soma (int *array1, int tam1, int *array2, int tam2, int *arraysoma);

int main ( )
{
    int n1, n2, i;

    printf ("informe o tamanho do primeiro vetor: ");
    scanf ("%d", &n1);
    int *vet1 = (int *)malloc(n1 * sizeof(int));
    if (vet1 == NULL) {
        printf("\nmemoria insuficiente");
        exit (1);
    }

    printf ("\ndigite os valores do primeiro vetor:\n");
    for (i = 0; i < n1; i++)
    {
        printf ("vet1[%d] = ", i);
        scanf ("%d", &vet1[i]);
    }

    printf ("\ninforme o tamanho do segundo vetor: ");
    scanf ("%d", &n2);
    int *vet2 = (int *)malloc(n2 * sizeof(int));
    if (vet2 == NULL) {
        printf("\nmemoria insuficiente");
        exit (1);
    }

    printf ("\ndigite os valores do segundo vetor:\n");
    for (i = 0; i < n2; i++)
    {
        printf ("vet2[%d] = ", i);
        scanf ("%d", &vet2[i]);
    }

    int *resultado = (int *)malloc(n1 * sizeof(int));
    if (resultado == NULL) {
        printf("\nmemoria insuficiente");
        exit (1);
    }

    if (soma (vet1, n1, vet2, n2, resultado) == 0)
    {
        printf ("\nos tamanhos dos vetores sao diferentes, nao eh possivel soma-los");
    } else if (soma (vet1, n1, vet2, n2, resultado) == 1)
    {
        printf ("\nsoma dos vetores:");
        printf ("\nvet[");
        for (i = 0; i < n1; i++)
        {
            printf (" %d ", resultado[i]);
        }
        printf ("]");
    }

    free(vet1);
    free(vet2);
    free(resultado);

    return 0;
}

int soma (int *array1, int tam1, int *array2, int tam2, int *arraysoma)
{
    int i;

    if (tam1 == tam2)
    {
        for (i = 0; i < tam1; i++)
        {
            arraysoma[i] = array1[i] + array2[i];
        }

        return 1;
    } else return 0;
}