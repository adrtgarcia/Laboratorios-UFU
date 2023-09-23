#include <stdio.h>

int ordena (int *a, int *b, int *c);

int main ( )
{
    int x, y, z;
    int *px = NULL, *py = NULL, *pz = NULL;

    px = &x;
    py = &y;
    pz = &z;

    printf ("digite o valor de X: ");
    scanf ("%d", px);
    printf ("digite o valor de Y: ");
    scanf ("%d", py);
    printf ("digite o valor de Z: ");
    scanf ("%d", pz);

    if (ordena (px, py, pz) == 1)
    {
        printf ("\nos valor sao iguais, %d - %d - %d", *px, *py, *pz);
    } else {
        printf ("\nvalores ordenados: %d - %d - %d", *px, *py, *pz);
    }

    return 0;
}

int ordena (int *a, int *b, int *c)
{
    int temp;

    if ((*a == *b) && (*a == *c))
    {
        return 1;
    } else {
        if ((*a < *b) && (*b < *c))
        {
            *a = *a;
            *b = *b;
            *c = *c;
        } else if ((*a < *c) && (*c < *b))
        {
            temp = *b;
            *a = *a;
            *b = *c;
            *c = temp;
        } else if ((*b < *a) && (*a < *c))
        {
            temp = *a;
            *a = *b;
            *b = temp;
            *c = *c;
        } else if ((*b < *c) && (*c < *a))
        {
            temp = *a;
            *a = *b;
            *b = *c;
            *c = temp;
        } else if ((*c < *a) && (*a < *b))
        {
            temp = *a;
            *a = *c;
            *c = *b;
            *b = temp;
        } else if ((*c < *b) && (*b < *a))
        {
            temp = *a;
            *a = *c;
            *b = *b;
            *c = temp;
        }

        return 0;
    }
}