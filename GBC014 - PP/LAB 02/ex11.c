#include <stdio.h>

int main ( )
{
    int num, alg, soma = 0;

    printf ("digite um numero: ");
    scanf ("%d", &num);

    if (num >= 0)
    {
        while (num > 0)
        {
            alg = num%10;
            soma = soma + alg;
            num = num/10;
        }

        printf ("soma de seus algarismos: %d", soma);
        
    } else {
        printf ("numero invalido");
    }

    return 0;
}