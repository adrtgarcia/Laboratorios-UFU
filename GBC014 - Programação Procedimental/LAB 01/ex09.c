#include <stdio.h>
// leia uma temperatura em graus CELSIUS e apresente-a convertida em KELVIN

int main ( )
{
    float C;
    printf ("insira a temperatura em graus celsius: ");
    scanf ("%f", &C);

    float K = C + 273.15; //fórmula de conversão
    printf ("temperatura em kelvin: %.1f", K);

    return 0;
}