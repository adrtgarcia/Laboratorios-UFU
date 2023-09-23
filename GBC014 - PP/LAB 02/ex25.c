#include <stdio.h>
#include <math.h>

int main ( )
{
    int a, b, c;
    printf ("digite o valor de a: ");
    scanf ("%d", &a);
    printf ("digite o valor de b: ");
    scanf ("%d", &b);
    printf ("digite o valor de c: ");
    scanf ("%d", &c);

    float x, x1, x2, delta = (pow (b, 2)) - (4*a*c);

    if (a == 0)
    {
        printf ("\nnao eh equacao de segundo grau");
    } else {
        if (delta < 0)
        {
            printf ("\nnao existe raiz");
        } else {
            if (delta == 0)
            {
                x = (-b)/(2*a);
                printf ("\nraiz unica: %.2f", x);
            } else {
                x1 = (-b + (sqrt (delta)))/(2*a);
                printf ("\nx1: %.2f", x1);
                x2 = (-b - (sqrt (delta)))/(2*a);
                printf ("\nx2: %.2f", x2);
            }
        }
    }

    return 0;
}