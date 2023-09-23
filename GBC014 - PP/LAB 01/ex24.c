#include <stdio.h>
// leia um valor de área em METROS QUADRADOS e apresente-o convertido em ACRES

int main ( )
{
    float M;
    printf ("insira a area em m2: ");
    scanf ("%f", &M);

    float A = M * 0.000247; //fórmula de conversão
    printf ("area em acres: %f", A);

    return 0;
}