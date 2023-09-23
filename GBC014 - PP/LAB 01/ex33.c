#include <stdio.h>
#include <math.h>
// leia o tamanho do LADO de um QUADRADO, imprima sua ÁREA

int main ( )
{
    float L;
    printf ("insira o valor do lado do quadrado: ");
    scanf ("%f", &L);

    float AREA = pow (L, 2); //fórmula da área
    printf ("area do quadrado: %.2f", AREA);

    return 0;
}