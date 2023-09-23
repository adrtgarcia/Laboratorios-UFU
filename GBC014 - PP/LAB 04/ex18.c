#include <stdio.h>

int expoente (int x, int z);

int main ( )
{
    int base, exp;
    printf ("digite o valor da base: ");
    scanf ("%d", &base);
    printf ("digite o valor do expoente: ");
    scanf ("%d", &exp);

    printf ("resultado: %d", expoente (base, exp));

    return 0;
}

int expoente (int x, int z)
{
    int cont, resultado = x;

    for (cont = 1; cont < z; cont++)
    {
        resultado *= x;
    }

    return resultado;
}