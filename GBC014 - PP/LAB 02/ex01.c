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
        printf ("maior numero: %d", x);
    } else {
        if (y > x)
        {
            printf ("maior numero: %d", y);
        } else {
            printf ("os numeros sao iguais");
        }
    }

    return 0;
}