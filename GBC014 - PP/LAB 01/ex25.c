#include <stdio.h>
// leia um valor de área em ACRES e apresente-o convertido em METROS QUADRADOS

int main ( )
{
    float A;
    printf ("insira a area em acres: ");
    scanf ("%f", &A);

    float M = A * 4048.58; //fórmula de conversão
    printf ("area em m2: %.2f", M);

    return 0;
}