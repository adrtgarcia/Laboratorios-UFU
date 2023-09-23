#include <stdio.h>

int potenciacao (int base, int expoente);
int fatorial (int num);

int main ( )
{
    int x, n, i;
    float e = 0.0;

    printf ("digite o valor da variavel x: ");
    scanf ("%d", &x);

    printf ("digite o valor do expoente n: ");
    scanf ("%d", &n);

    for (i = 0; i <= n; i++)
    {
        e += ((potenciacao(x, i)) / ((fatorial (i))*1.0));
    }

    printf ("e^%d = %d", x, e);

    return 0;
}

int potenciacao (int base, int expoente)
{
    int resultado, i;

    if (expoente > 0)
    {
        for (i = 1, resultado = base; i < expoente; i++)
        {
            resultado *= base;
        }
        return resultado;
    } else if (expoente == 0)
    {
        return 1;
    }
}

int fatorial (int num)
{
    int fat = 1, i;

    for (i = num; i > 0; i--)
    {
        fat *= i;
    }

    return fat;
}
