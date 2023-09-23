#include <stdio.h>

int main ( )
{
    int vetor[6], cont1, cont2;

    printf ("digite seis valores:\n");
    for (cont1 = 0; cont1 < 6; cont1++)
    {
        scanf (" %d", &vetor[cont1]);
    }

    printf ("\nem ordem inversa:\n");
    for (cont2 = 5; cont2 >= 0; cont2--)
    {
        printf ("%d ", vetor[cont2]);
    }

    return 0;
}