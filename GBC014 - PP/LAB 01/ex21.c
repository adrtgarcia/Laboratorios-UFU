#include <stdio.h>
// leia um valor de massa em LIBRAS e apresente-o convertido em QUILOGRAMAS

int main ( )
{
    float L;
    printf ("insira a massa em libras: ");
    scanf ("%f", &L);

    float K = L * 0.45;
    printf ("massa em Kg: %.2f", K);

    return 0;
}