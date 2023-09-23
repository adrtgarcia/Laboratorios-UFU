#include <stdio.h>
// leia QUATRO NOTAS, calcule a MÉDIA ARITMÉTICA e imprima o resultado

int main ( )
{
    int w, x, y, z;
    printf ("digite nota 1: ");
    scanf ("%d", &w);

    printf ("digite nota 2: ");
    scanf ("%d", &x);

    printf ("digite nota 3: ");
    scanf ("%d", &y);

    printf ("digite nota 4: ");
    scanf ("%d", &z);

    int MEDIA = (w + x + y + z) / 4;
    printf ("resultado: %d", MEDIA);

    return 0;
}