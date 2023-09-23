#include <stdio.h>
#include <math.h>
// faça uma leitura de TRÊS VALORES e apresente o resultado da SOMA DOS QUADRADOS

int main ( )
{
    int x, y, z;
    printf ("digite o primeiro valor: ");
    scanf ("%d", &x);

    printf ("digite o segundo valor: ");
    scanf ("%d", &y);

    printf ("digite o terceiro valor: ");
    scanf ("%d", &z);

    int x2 = pow (x, 2), y2 = pow (y, 2), z2 = pow (z, 2);
    int SOMA = x2 + y2 + z2;
    printf ("resultado: %d", SOMA);

    return 0;
}