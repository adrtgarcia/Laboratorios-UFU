#include <stdio.h>

int main ( )
{
    float km, litros;
    printf ("digite a distancia, em km: ");
    scanf ("%f", &km);
    printf ("digite a quantidade de gasolina consumida, em litros: ");
    scanf ("%f", &litros);

    float consumo = km/litros;

    if (consumo < 8)
    {
        printf ("venda o carro!");
    } else {
        if ((consumo >= 8) && (consumo <= 14))
        {
            printf ("economico!");
        } else {
            printf ("super economico!");
        }
    }

    return 0;
}