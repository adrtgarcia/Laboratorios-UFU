#include <stdio.h>
// leia um valor de volume em LITROS e apresente-o convertido em METROS CÚBICOS

int main ( )
{
    float L;
    printf ("insira o volume em L: ");
    scanf ("%f", &L);

    float M = L / 1000; //fórmula de conversão
    printf ("volume em m3: %.1f", M);
    
    return 0;
}