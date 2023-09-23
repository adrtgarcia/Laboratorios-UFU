#include <stdio.h>
// leia um valor de comprimento em METROS e apresente-o convertido em JARDAS

int main ( )
{
    float M;
    printf ("insira o comprimento em m: ");
    scanf ("%f", &M);

    float J = M / 0.91; //fórmula de conversão
    printf ("comprimento em jardas: %.2f", J);

    return 0;
}