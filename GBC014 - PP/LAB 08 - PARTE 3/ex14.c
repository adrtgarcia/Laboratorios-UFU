#include <stdio.h>
#include <math.h>

int raizes(float A, float B, float C, float *X1, float *X2);

int main ( )
{
    float a, b, c, x1, x2;
    float *p1 = NULL, *p2 = NULL;

    p1 = &x1;
    p2 = &x2;

    printf ("digite o valor de A: ");
    scanf ("%f", &a);
    printf ("digite o valor de B: ");
    scanf ("%f", &b);
    printf ("digite o valor de C: ");
    scanf ("%f", &c);

    if (raizes (a, b, c, p1, p2) == 0)
    {
        printf ("\na equacao %.1fx^2 + (%.1f)x + (%.1f) nao possui raiz real", a, b, c);
    } else if (raizes (a, b, c, p1, p2) == 1)
    {
        printf ("\na equacao %.1fx^2 + (%.1f)x + (%.1f) possui uma raiz real, sendo X = %.1f", a, b, c, *p1);
    } else if (raizes (a, b, c, p1, p2) == 2)
    {
        printf ("\na equacao %.1fx^2 + (%.1f)x + (%.1f) possui duas raizes reais, sendo X1 = %.1f e X2 = %.1f", a, b, c, *p1, *p2);
    }

    return 0;
}

int raizes(float A, float B, float C, float *X1, float *X2)
{
    float delta = (B * B) - (4 * A * C);

    if (delta < 0)
    {
        return 0;
    } else if (delta == 0)
    {
        *X1 = (-B + delta) / (2 * A); 
        return 1;
    } else if (delta > 0)
    {
        *X1 = (-B + sqrt(delta)) / (2 * A);
        *X2 = (-B - sqrt(delta)) / (2 * A);
        return 2;
    }
}