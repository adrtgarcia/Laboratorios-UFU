#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main ( )
{
    int d1, d2, n, cont;
    printf ("insira o numero de lancamentos: ");
    scanf ("%d", &n);

    srand (time(NULL));

    for (cont = 1; cont <= n; cont++)
    {
        d1 = rand ( ) % 6 + 1;
        d2 = rand ( ) % 6 + 1;
        
        if (d1 > d2)
        {
            printf ("\nlancamento %d: %d > %d", cont, d1, d2);
        } else if (d1 < d2)
        {
            printf ("\nlancamento %d: %d < %d", cont, d1, d2);
        } else if (d1 == d2)
        {
            printf ("\nlancamento %d: %d = %d", cont, d1, d2);
        }
    }

    return 0;
}