#include <stdio.h>
// leia o VALOR de um produto e imprima o valor com DESCONTO

int main ( )
{
    float V;
    printf ("insira o valor do produto: ");
    scanf ("%f", &V);

    float D = V * 0.88; //se o desconto é de 12%, paga-se 88% do valor
    printf ("valor com desconto: %.2f", D);

    return 0;
}