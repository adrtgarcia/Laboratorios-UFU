#include <stdio.h>
// leia um valor de volume em METROS CÚBICOS e apresente-o convertido em LITROS

int main ( )
{
    float M;
    printf ("insira o volume em m3: ");
    scanf ("%f", &M);

    float L = 1000 * M; //fórmula de conversão
    printf ("volume em L: %.1f", L);
    
    return 0;
}