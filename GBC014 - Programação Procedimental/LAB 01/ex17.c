#include <stdio.h>
// leia um valor de comprimento em CENTÍMETROS e apresente-o convertido em POLEGADAS

int main ( )
{
    float C;
    printf ("insira o comprimento em cm: ");
    scanf ("%f", &C);

    float P = C / 2.54; //fórmula de conversão
    printf ("comprimento em polegadas: %.2f", P);

    return 0;
}