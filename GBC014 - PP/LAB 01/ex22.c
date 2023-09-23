#include <stdio.h>
// leia um valor de comprimento em JARDAS e apresente-o convertido em METROS

int main ( )
{
    float J;
    printf ("insira o comprimento em jardas: ");
    scanf ("%f", &J);

    float M = 0.91 * J; //fórmula de conversão
    printf ("comprimento em m: %.2f", M);

    return 0;
}