#include <stdio.h>

int main ( )
{
    int num, soma = 0, quant = 0;

    do
    {
        printf ("digite um numero: ");
        scanf ("%d", &num);

        if (num > 10)
        {
            soma += num;
        } else if (num < 10)
        {
            quant++;
        }
    } while (num != 10);

    printf ("\n%d eh a soma de todos os numeros digitados maiores que 10", soma);
    printf ("\nforam digitados %d numeros menores que 10", quant);

    return 0;
}
