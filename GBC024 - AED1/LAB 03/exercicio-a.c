#include <stdio.h>

int soma (int num);

int main ( )
{
    int n, resultado;

    do
    {
        printf ("digite um numero: ");
        scanf ("%d", &n);

        if (n <= 0)
        {
            printf ("digite um numero positivo\n\n");
        }
    } while (n <= 0);

    if (n == 1)
    {
        printf ("a soma eh 1", n);
    } else if (n > 1)
    {
        resultado = (soma (n));
        printf ("a soma de todos os numeros de 1 ate %d eh %d", n, resultado);
    }

    return 0;
}

int soma (int num)
{
    int i, resultado;

    for (i = 1, resultado = 0; i <= num; i++)
    {
        resultado += i;
    }

    return resultado;
}
