#include <stdio.h>
#include <math.h>

void calculaHexagono (float l, float* area, float* perimetro);

int main ( )
{
    float lado, area, perimetro;

    printf ("digite o lado do hexagono: ");
    scanf ("%f", &lado);

    calculaHexagono (lado, &area, &perimetro);
    printf ("\narea: %.2f", area);
    printf ("\nperimetro: %.2f", perimetro);

    return 0;
}

void calculaHexagono (float l, float* area, float* perimetro)
{
    *area = (6 * (((pow (l, 2)) * (sqrt(3))) / 4));
    *perimetro = (6 * l);
}
