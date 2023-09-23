#include <stdio.h>
// leia uma temperatura em graus KELVIN e apresente-a convertida em graus CELSIUS

int main ( )
{
    float K;
    printf ("insira a temperatura em kelvin: ");
    scanf ("%f", &K);

    float C = K - 273.15; //fórmula de conversão
    printf ("temperatura em graus celsius: %.1f", C);

    return 0;
}