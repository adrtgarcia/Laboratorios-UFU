#include <stdio.h>
// leia um valor de massa em QUILOGRAMAS e apresente-o convertido em LIBRAS

int main ( )
{
    float K;
    printf ("insira a massa em Kg: ");
    scanf ("%f", &K);

    float L = K / 0.45; //fórmula de conversão
    printf ("massa em libras: %.2f", L);

    return 0;
}