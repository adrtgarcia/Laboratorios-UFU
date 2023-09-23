#include <stdio.h>
#include <math.h>

int main ( )
{
    float num;
    printf ("digite um numero: ");
    scanf ("%f", &num);

    if (num > 0)
    {
        float x = sqrt (num);
        printf ("raiz quadrada: %.2f", x);
    } else {
        float y = pow (num, 2);
        printf ("quadrado do numero: %.2f", y);
    }

    return 0;
}