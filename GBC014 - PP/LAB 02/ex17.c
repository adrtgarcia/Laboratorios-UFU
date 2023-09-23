#include <stdio.h>

int main ( )
{
    float bma, bme, h;
    printf ("insira o valor da base maior: ");
    scanf ("%f", &bma);
    printf ("insira o valor da base menor: ");
    scanf ("%f", &bme);
    printf ("insira o valor da altura: ");
    scanf ("%f", &h);

    if ((bma > 0) && (bme > 0))
    {
        float area = ((bma + bme) * h)/2;
        printf ("area do trapezio: %.2f", area);
    } else {
        printf ("dados invalidos");
    }

    return 0;
}