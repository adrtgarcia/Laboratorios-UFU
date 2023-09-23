#include <stdio.h>
// leia uma distância em QUILÔMETROS e apresente-a convertida em MILHAS

int main ( )
{
    float K;
    printf ("insira a distancia em Km: ");
    scanf ("%f", &K);

    float M = K / 1.61; //fórmula de conversão
    printf ("distancia em milhas: %.2f", M);

    return 0;
}