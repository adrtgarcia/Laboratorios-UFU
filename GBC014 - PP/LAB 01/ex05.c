#include <stdio.h>
// leia um NÚMERO REAL e imprima a QUINTA PARTE deste número.

int main ( )
{
    float x;
    printf ("digite um numero real: ");
    scanf ("%f", &x);

    float y = x / 5;
    printf ("quinta parte: %.2f", y);

    return 0;
}