#include <stdio.h>
#include <math.h>
// receba os valores dos catetos A e B, calcule a HIPOTENUSA e imprima

int main ( )
{
    int a, b;
    printf ("digite o valor do cateto a: ");
    scanf ("%d", &a);

    printf ("digite o valor do cateto b: ");
    scanf ("%d", &b);

    int h = sqrt (pow (a, 2) + pow (b, 2)); //fórmula da hipotenusa
    printf ("valor da hipotenusa: %d", h);

    return 0;
}