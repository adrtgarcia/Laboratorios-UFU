#include <stdio.h>
#include <stdlib.h>

int main ( )
{
    int n, *vet = NULL;
    int i, j, k;

    printf ("informe o tamanho do vetor: ");
    scanf ("%d", &n);

    vet = (int *) calloc (5, (sizeof(int)));
    if (vet == NULL)
    {
        printf ("erro na alocacao de memoria");
        return 0;
    }

    printf ("\ninforme os valores do vetor:\n");
    for (i = 0; i < n; i++)
    {
        printf ("vet[%d] = ", i);
        scanf ("%d", &vet[i]);
    }

    for (i = 0, k = 0; i < n; i++)
    {
        if (vet[i] % 2 != 0)
        {
            for (j = i; j < n; j++)
            {
                vet[j] = vet[(j + 1)];
            }

            k++;
        }
    }

    vet = (int *) realloc (vet, (n - k) * (sizeof(int)));

    printf ("\nvetor final:");
    printf ("\nvet[");
    for (i = 0; i < (n - k); i++)
    {
        printf (" %d ", vet[i]);
    }
    printf ("]");

    free(vet);

    return 0;
}
