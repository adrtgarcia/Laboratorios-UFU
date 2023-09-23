#include <stdio.h>
#include <math.h>

int main ( )
{
    float x, y, z, media;
    int op;

    printf ("digite o primeiro numero: ");
    scanf ("%f", &x);
    printf ("digite o segundo numero: ");
    scanf ("%f", &y);
    printf ("digite o terceiro numero: ");
    scanf ("%f", &z);

    do
    {
        printf ("\nescolha um tipo de media: \n");
        printf ("\n(1) geometrica\n");
        printf ("(2) ponderada\n");
        printf ("(3) harmonica\n");
        printf ("(4) aritmetica\n");
        scanf ("%d", &op);

        if ((op < 1) || (op > 4))
        {
            printf ("\nopcao invalida, tente novamente\n");
        }
    } while ((op < 1) || (op > 4));

    switch (op)
    {
    case 1:
        media = cbrt (x*y*z);
        printf ("media geometrica: %.2f", media);
        break;

    case 2:
        media = ((1*x) + (2*y) + (3*z))/6;
        printf ("media ponderada: %.2f", media);
        break;
    
    case 3:
        media = 3 / (1/x + 1/y + 1/z);
        printf ("media harmonica: %.2f", media);
        break;
    
    case 4:
        media = (x + y + z)/3;
        printf ("media aritmetica: %.2f", media);
        break;
    }
    return 0;
}