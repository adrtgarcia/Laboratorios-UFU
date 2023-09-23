#include <stdio.h>

int main ( )
{
    int x, y;
    printf ("digite o primeiro numero: ");
    scanf ("%d", &x);
    printf ("digite o segundo numero: ");
    scanf ("%d", &y);

    if (x > y)
    {
        int d1 = x - y;
        printf ("%d eh o maior numero \n", x);
        printf ("%d eh a diferenca entre os numeros", d1);
    } else {
        if (x < y)
        {
            int d2 = y - x;
            printf ("%d eh o maior numero \n", y);
            printf ("%d eh a diferenca entre os numeros", d2);
        } else {
            printf ("os numeros sao iguais");
        }

        return 0;
    }
}