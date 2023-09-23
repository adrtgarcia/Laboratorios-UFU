#include <stdio.h>
#include <math.h>
// leia o RAIO de um círculo e imprima a ÁREA

int main ( )
{
    #define PI 3.141592 //dado do exercício

    float R;
    printf ("insira o raio do circulo: ");
    scanf ("%f", &R);

    float AREA = PI * pow (R, 2); //fórmula da área
    printf ("area do circulo: %.2f", AREA);

    return 0;
}