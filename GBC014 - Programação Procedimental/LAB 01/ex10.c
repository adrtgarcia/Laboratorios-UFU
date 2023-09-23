#include <stdio.h>
// leia uma velocidade em KM/H e apresente-a convertida em M/S

int main ( )
{
    float K;
    printf ("insira a velocidade em Km/h: ");
    scanf ("%f", &K);

    float M = K/3.6; //fórmula de conversão
    printf ("velocidade em m/s: %.1f", M);

    return 0;
}