#include <stdio.h>

int existe_triangulo (float a, float b, float c);
int tipo_triangulo (float a, float b, float c);

int main ( )
{
    float lado1, lado2, lado3;

    do
    {
        printf ("digite o valor do lado 1: ");
        scanf ("%f", &lado1);
        printf ("digite o valor do lado 2: ");
        scanf ("%f", &lado2);
        printf ("digite o valor do lado 3: ");
        scanf ("%f", &lado3);

        if ((lado1 == 0) || (lado2 == 0) || (lado3 == 0))
        {
            printf ("\nos lados precisam ser maiores que zero\n\n");
        }

    } while ((lado1 == 0) || (lado2 == 0) || (lado3 == 0));

    if (existe_triangulo (lado1, lado2, lado3))
    {
        if ((tipo_triangulo (lado1, lado2, lado3)) == 1)
        {
            printf ("o triangulo existe e eh equilatero");
        } else if ((tipo_triangulo (lado1, lado2, lado3)) == 2)
        {
            printf ("o triangulo existe e eh isosceles");
        } else printf ("o triangulo existe e eh escaleno");
    } else printf ("o triangulo nao existe");

    return 0;
}

int existe_triangulo (float a, float b, float c)
{
    if ((a + b > c) && (b + c > a) && (a + c > b))
    {
        return 1;
    } else return 0;
}

int tipo_triangulo (float a, float b, float c)
{
    if ((a == b) && (b == c))
    {
        return 1;
    } else if ((a == b) || (a != c))
    {
        return 2;
    } else if ((a == c) || (a != b))
    {
        return 2;  
    } else if ((b == c) || (b != a))
    {
        return 2;
    } else return 3;
}