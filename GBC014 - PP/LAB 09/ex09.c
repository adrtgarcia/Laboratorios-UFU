#include <stdio.h>
#include <stdlib.h>

int main ( )
{
    int i, num, tamanho = 0;
    int *vet = NULL;

    do 
    {
        printf ("digite um numero (digite valor negativo para encerrar): ");
        scanf ("%d", &num);

        if (num >= 0) 
        {
            tamanho++;

            vet = (int *) realloc (vet, tamanho * (sizeof(int)));
            if (vet == NULL)
            {
                printf ("\nerro: memoria invalida");
                exit(1);
            }

            vet[tamanho - 1] = num;
        }

    } while (num >= 0);

    printf ("\nvetor lido:");
    printf ("\nvet[ ");
    for (i = 0; i < tamanho; i++) 
    {
        printf("%d ", vet[i]);
    }
    printf("]");

    free(vet);

    return 0;
}