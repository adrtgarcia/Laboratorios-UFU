#include <stdio.h>
#include <math.h>

int main ( )
{
    int num;
    printf ("digite um numero: ");
    scanf ("%d", &num);

    if (num < 0)
    {
        printf ("numero invalido");
    } else {
        float l = log10 (num);
        printf ("%f eh o logaritmo desse numero", l);
    }

    return 0;
}