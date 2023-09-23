#include <stdio.h>
#include <math.h>

float hipotenusa (int cat1, int cat2);

int main ( )
{
    int a, b;
    printf ("digite o valor do cateto a: ");
    scanf ("%d", &a);
    printf ("digite o valor do cateto b: ");
    scanf ("%d", &b);

    printf ("o valor da hipotenusa eh: %.2f", hipotenusa (a, b));

    return 0;
}

float hipotenusa (int cat1, int cat2)
{
    float h = sqrt ((pow (cat1, 2) + (pow (cat2, 2))));
    return h;
}