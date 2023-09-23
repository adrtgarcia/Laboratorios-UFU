#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main ( ) 
{
    int i, tamanho;
    double *vet = NULL;

    do
    {
        printf ("digite o tamanho do vetor: ");
        scanf ("%d", &tamanho);

        if (tamanho < 10)
        {
            printf ("o tamanho deve ser maior ou igual a 10\n");
        }
    } while (tamanho < 10);

    vet = (double *) malloc (tamanho * (sizeof(double)));
    if (vet == NULL)
    {
        printf ("\nerro: memoria insuficiente");
        exit(1);
    }

    srand(time(NULL));
    for (i = 0; i < 10; i++) 
    {
        vet[i] = (double) (rand( ) % 101);
    }

    printf("\nvalores dos 10 primeiros elementos: ");
    for (i = 0; i < 10; i++) 
    {
        printf("%.2f ", vet[i]);
    }
    
    free(vet);

    return 0;
}