#include <stdio.h>
#include <math.h>
// leia ALTURA e RAIO de um cilindro circular, imprima o VOLUME

int main ( )
{
    #define PI 3.141592

    float A, R;
    printf ("insira o valor da altura: ");
    scanf ("%f", &A);

    printf ("insira o valor do raio: ");
    scanf ("%f", &R);

    float V = PI * (pow (R, 2)) * A; //fórmula do volume
    printf ("volume do cilindro: %.2f", V);

    return 0;
}