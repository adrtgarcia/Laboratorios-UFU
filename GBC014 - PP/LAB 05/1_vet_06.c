#include <stdio.h>

int primo (int num);

int main ( )
{
    int vetor[10], cont, confirma;

    printf ("digite dez valores:\n");
    for (cont = 0; cont < 10; cont++)
    {
        scanf (" %d", &vetor[cont]);
    }

    printf ("\nsao primos:\n");
    for (cont = 0; cont < 10; cont++)
    {
        confirma = primo (vetor[cont]);

        if (confirma == 0 && vetor[cont] > 1)
        {
            printf("\nvetor[%d] = %d", cont, vetor[cont]);
        } else continue;
    }

    return 0;
}

int primo (int num)
{
    int cont, confirma = 0; 

    for (cont = 2; cont <= num / 2; cont++)
    {
        if (num % cont == 0)
        {
            confirma++;
        }
    }

    return confirma;
}