#include <stdio.h>
// receba a ALTURA DO DEGRAU e a ALTURA DESEJADA, mostre o NÚMERO DE DEGRAUS necessários

int main ( )
{
    float deg, h;
    printf ("insira a altura do degrau (em cm): ");
    scanf ("%f", &deg);

    printf ("insira a altura desejada (em cm): ");
    scanf ("%f", &h);

    int n = h / deg;
    printf ("eh necessario subir %d degrau(s)", n);

    return 0;
}