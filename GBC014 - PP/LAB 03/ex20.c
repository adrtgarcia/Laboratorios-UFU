#include <stdio.h>
#include <math.h>

int main ( )
{
    int num, div, quantidade = 0;
    double soma = 2;
    for (num = 3; num < 2000000; num += 2)
    {
        quantidade = 2;
        
        for (div = 3; div <= sqrt(num); div += 2)
        {
            if (num%div == 0)
            {
                quantidade += 2;
                break;
            }
        }
        
        if (quantidade == 2)
        {
            soma += num;
        }
    }

    printf ("a soma dos primos abaixo de 2.000.000 eh: %.0lf", soma);

    return 0;
}