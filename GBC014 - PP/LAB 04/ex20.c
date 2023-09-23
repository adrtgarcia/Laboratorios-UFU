#include <stdio.h>
#include <math.h>

int quantos_primos (int n);

int main ( )
{
    int num;
    printf ("digite um numero: ");
    scanf ("%d", &num);

    printf ("existem %d primos menores que %d", quantos_primos (num), num);

    return 0;
}

int quantos_primos (int n)
{
    int numero, divisor, primo, cont = 0;

    for (numero = 2; numero < n; numero++)
    {
        for (divisor = 2; divisor < numero; divisor++)
        {
            if (numero%divisor == 0)
            {
                primo = 0;
                break;
            } else primo = 1;
        }

        if (primo)
        {
            cont++;
        }
    }

    return cont;
}