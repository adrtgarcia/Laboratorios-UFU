#include <stdio.h>
#include <math.h>
// leia um NÚMERO REAL e imprima o resultado do QUADRADO desse número

int main ( )
{
    float x;
    printf ("digite um numero real: ");
    scanf ("%f", &x);

    float y = pow (x, 2);
    printf ("quadrado: %.0f", y);

    return 0;
}