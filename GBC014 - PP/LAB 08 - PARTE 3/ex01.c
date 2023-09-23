#include <stdio.h>

void troca (int *a, int *b);

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

    printf ("\nantes da troca: X = %d, Y = %d", *px, *py);
    troca (px, py);
    printf ("\ndepois da troca: X = %d, Y = %d", *px, *py);

    return 0;
}

void troca (int *a, int *b)
{
    int temp = *a;

    *a = *b;
    *b = temp;
}