#include <stdio.h>

float consumo (float d, float g);

int main ( )
{
    float dist, gas;
    printf ("digite a distancia, em quilometros (Km): ");
    scanf ("%f", &dist);
    printf ("digite a quantidade de gasolina, em litros (L): ");
    scanf ("%f", &gas);

    if (consumo (dist, gas) < 8)
    {
        printf ("venda o carro!");
    } else if (consumo (dist, gas) <= 14)
    {
        printf ("economico!");
    } else
    {
        printf ("super economico!");
    }

    return 0;
}

float consumo (float d, float g)
{
    float consumo = d/g;
    return consumo;
}