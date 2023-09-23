#include <stdio.h>
// calcule e imprima o VALOR do novo SALÁRIO, sabendo que ele aumentou 25%

int main ( )
{
    float S;
    printf ("digite o salario original: ");
    scanf ("%f", &S);

    float A = S * 1.25; //se aumentou 25%, então o novo valor é 125% do original
    printf ("novo salario: %.2f", A);

    return 0;
}