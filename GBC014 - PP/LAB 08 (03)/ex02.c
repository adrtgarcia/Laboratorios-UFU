#include <stdio.h>

void compara (int *a, int *b);

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

    if ((*px > *py) || (*px < *py))
    {
        compara (px, py);

        printf ("\nX = %d (maior valor)", *px);
        printf ("\nY = %d (menor valor)", *py);

    } else printf ("\nX e Y sao iguais");
    
    return 0;
}

void compara (int *a, int *b)
{
    int temp = *a;

    if (*b > *a)
    {
        *a = *b;
        *b = temp;
    }
}