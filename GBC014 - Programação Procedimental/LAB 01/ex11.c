#include <stdio.h>
// leia uma velocidade em M/S e apresente-a convertida em KM/H

int main ( )
{
    float M;
    printf ("insira a velocidade em m/s: ");
    scanf ("%f", &M);

    float K = M * 3.6; //fórmula de conversão
    printf ("velocidade em Km/h: %.1f", K);

    return 0;
}