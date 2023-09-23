#include <stdio.h>
#include <math.h>

float volume_cilindro (float h, float r);

int main ( )
{
    float altura, raio;
    printf ("digite o valor da altura: ");
    scanf ("%f", &altura);
    printf ("digite o valor do raio: ");
    scanf ("%f", &raio);

    printf ("volume do cilindro: %.2f", volume_cilindro (altura, raio));

    return 0;
}

float volume_cilindro (float h, float r)
{
    float v = (3.141592) * (pow (r, 2)) * (h);
    return v;
}