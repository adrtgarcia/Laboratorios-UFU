#include <stdio.h>
// leia uma distância em MILHAS e apresente-a convertida em QUILÔMETROS

int main ( )
{
    float M;
    printf ("insira a distancia em milhas: ");
    scanf ("%f", &M);

    float K = 1.61 * M; //fórmula de conversão
    printf ("distancia em Km: %.2f", K);

    return 0;
}