#include <stdio.h>
// leia um valor de área em HECTARES e apresente-o convertido em METROS QUADRADOS

int main ( )
{
    float H;
    printf ("insira a area em hectares: ");
    scanf ("%f", &H);
    
    float M = H * 10000; //fórmula de conversão
    printf ("area em m2: %.2f", M);

    return 0;
}