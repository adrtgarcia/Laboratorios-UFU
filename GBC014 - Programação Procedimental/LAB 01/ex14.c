#include <stdio.h>
// leia um ângulo em GRAUS e apresente-o convertido em RADIANOS

int main ( )
{
    #define PI 3.141592 //dado do exercício

    float G;
    printf ("insira o valor em graus: ");
    scanf ("%f", &G);

    float R = G * PI / 180; //fórmula de conversão
    printf ("valor em radianos: %.2f", R);

    return 0;
}