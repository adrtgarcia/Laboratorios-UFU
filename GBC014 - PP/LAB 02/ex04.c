#include <stdio.h>
#include <math.h>

int main ( )
{
    float num;
    printf ("digite um numero: ");
    scanf ("%f", &num);

    if (num > 0)
    {
        float x, y;
        
        x = pow (num, 2);
        y = sqrt (num);

        printf ("quadrado do numero: %.2f \n", x);
        printf ("raiz quadrada do numero: %.2f", y);
    } else {
        printf ("numero invalido");
    }

    return 0;
}