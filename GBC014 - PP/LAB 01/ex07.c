#include <stdio.h>
// leia uma temperatura em graus FAHRENHEIT e apresente-a convertida em graus CELSIUS

int main ( )
{
    float F;
    printf ("insira a temperatura em graus fahrenheit: ");
    scanf ("%f", &F);

    float C = 5.0 * (F - 32) / 9.0; //fórmula de conversão
    printf ("temperatura em graus celsius: %.1f", C);

    return 0;
}