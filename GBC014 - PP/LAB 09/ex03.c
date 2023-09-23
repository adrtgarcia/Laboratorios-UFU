#include <stdio.h>
#include <stdlib.h>

int main ( )
{
    int *p = NULL, i, j, par, impar;

    printf ("digite o tamanho do vetor: ");
    scanf ("%d", &i);

    p = (int *) calloc (i, (sizeof(int)));

    if (p == NULL)
    {
        printf ("\nerro: memoria insuficiente");
        exit(1);
    }

    printf ("\ndigite os valores do vetor:\n");
    for (j = 0, par = 0, impar = 0; j < i; j++)
    {
        printf ("vet[%d] = ", j);
        scanf ("%d", &p[j]);

        if (p[j] % 2 == 0)
        {
            par++;
        } else impar++;
    }

    printf ("\nforam lidos %d numeros pares", par);
    printf ("\nforam lidos %d numeros impares", impar);

    free(p);

    return 0;
}