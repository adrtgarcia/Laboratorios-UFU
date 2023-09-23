#include <stdio.h>
// leia um valor de área em METROS QUADRADOS e apresente-o convertido em HECTARES

int main ( )
{
    float M;
    printf ("insira a area em m2: ");
    scanf ("%f", &M);

    float H = M * 0.0001; //fórmula de conversão
    printf ("area em hectares: %.4f", H);

    return 0;
}