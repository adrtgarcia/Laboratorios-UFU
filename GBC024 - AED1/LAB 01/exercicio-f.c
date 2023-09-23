#include <stdio.h>

int main ( )
{
    float base, altura, area;

    do
    {
        printf ("digite o valor da base: ");
        scanf ("%f", &base);

        printf ("digite o valor da altura: ");
        scanf ("%f", &altura);

        if ((base <= 0) || (altura <= 0))
        {
            printf ("\ndados invalidos\n\n");
        }
    } while ((base <= 0 ) || (altura <= 0));

    area = (base * altura) / 2;
    printf ("\na area do triangulo eh %.2f", area);

    return 0;
}
