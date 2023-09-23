#include <stdio.h>

int main ( )
{
    int x, *px = NULL;
    float y, *py = NULL;
    char z, *pz = NULL;

    px = &x;
    py = &y;
    pz = &z;
    
    printf ("inteiro x: ");
    scanf ("%d", &x);

    printf ("real y: ");
    scanf ("%f", &y);

    printf ("caractere z: ");
    scanf (" %c", &z);

    printf ("\nvalores iniciais: %d, %.2f, %c", x, y, z);
    printf ("\n");

    printf ("modifique x: ");
    scanf ("%d", &(*px));

    printf ("modifique y: ");
    scanf ("%f", &(*py));

    printf ("modifique z: ");
    scanf (" %c", &(*pz));

    printf ("\nvalores finais: %d, %.2f, %c", x, y, z);

    return 0;
}