#include <stdio.h>
// leia um valor de comprimento em POLEGADAS e apresente-o convertido em CENTÍMETROS

int main ( )
{
    float P;
    printf ("insira o comprimento em polegadas: ");
    scanf ("%f", &P);

    float C = P * 2.54; //fórmula de conversão
    printf ("comprimento em cm: %.2f", C);

    return 0;
}