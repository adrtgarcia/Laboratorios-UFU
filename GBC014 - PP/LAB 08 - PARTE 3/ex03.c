#include <stdio.h>

void soma (int *a, int *b);

int main ( )
{
    int x, y;
    int *px = NULL, *py = NULL;

    px = &x;
    py = &y;

    printf ("digite o valor de X: ");
    scanf ("%d", px);

    printf ("digite o valor de Y: ");
    scanf ("%d", py);

    soma (px, py);

    printf ("\nX = %d", *px);
    printf ("\nY = %d", *py);

    return 0;
}

void soma (int *a, int *b)
{
    int soma = *a + *b;
    *a = soma;
}