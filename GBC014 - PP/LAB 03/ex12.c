#include <stdio.h>

int main ( )
{
    int num, div = 1, soma = 0, cont;
    printf ("digite um numero: ");
    scanf ("%d", &num);

    while (div < num)
    {
        if (num/1 == 1)
        {
            soma = 0;
            break;
        }

        if (num%div == 0)
        {
            soma = soma + div;
            div++;
        }

        if (num%div != 0)
        {
            div++;
        }
    }

    printf ("soma dos divisores: %d", soma);

    return 0;
}