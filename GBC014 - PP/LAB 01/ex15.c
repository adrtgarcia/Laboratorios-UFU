#include <stdio.h>
// leia um ângulo em RADIANOS e apresente-o convertido em GRAUS

int main ( )
{
    #define PI 3.141592 //dado do exercício

    float R;
    printf ("insira o valor em radianos: ");
    scanf ("%f", &R);

    float G = R * 180 / PI; //fórmula de conversão
    printf ("valor em graus: %.2f", G);

    return 0;
}