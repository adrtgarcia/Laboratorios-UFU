#include <stdio.h>
// leia uma temperatura em graus CELSIUS e apresente-a convertida em graus FAHRENHEIT

int main ( )
{
    float C;
    printf ("insira a temperatura em graus celsius: ");
    scanf ("%f", &C);

    float F = C * (9.0/5.0) + 32.0; //fórmula de conversão
    printf ("temperatura em graus fahrenheit: %.1f", F);

    return 0;
}