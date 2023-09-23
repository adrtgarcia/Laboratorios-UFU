#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main ( )
{
    int a, b, res, cont, acertos = 0;

    for (cont = 0; cont < 5; cont++)
    {
        srand(time(NULL));
        a = rand( ) % 100;
        b = rand ( ) % 100;

        printf ("\nqual eh a soma de %d + %d?", a, b);
        printf ("\ndigite sua resposta: ");
        scanf ("%d", &res);
        printf ("gabarito: %d\n", a+b);

        if (a + b == res)
        {
            acertos++;
        }
    }

    printf ("\nvoce acertou %d vezes!", acertos);
    
    return 0;
}