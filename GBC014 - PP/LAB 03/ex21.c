#include <stdio.h>
#include <math.h>

int main ( )
{
    int a, b, num, div, primo = 0, quantidade = 0;

    printf ("digite o valor de a: ");
    scanf ("%d", &a);
    printf ("digite o valor de b: ");
    scanf ("%d", &b);

    for (num = a; num <= b; num++)
    {
        quantidade = 2;

        if (num <= 1)
        {
            continue;
        }

        for (div = 2; div <= sqrt(num); div++)
        {
            if (num%div == 0)
            {
                quantidade++;
                break;
            }
        }

        if (quantidade == 2)
        {
            primo++;
        }
    }

    printf ("existem %d primos entre %d e %d", primo, a, b);

    return 0;
}