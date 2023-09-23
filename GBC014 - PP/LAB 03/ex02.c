#include <stdio.h>

int main ( )
{
    int numf = 1, cont, i;

    printf ("utilizando for:\n\n");
    for (cont = 1; cont <= 100; cont++)
    {
        printf ("%d  ", numf);
        numf++;
    }

    int numw = 1;

    printf ("\n\nutilizando while:\n\n");
    while (numw <= 100)
    {
        printf ("%d  ", numw);
        numw++;
    }

    int numdw = 1;

    printf ("\n\nutilizando do-while:\n\n");
    do
    {
        printf ("%d  ", numdw);
        numdw++;
    } while (numdw <= 100);

    return 0;
}