#include <stdio.h>

int main ( )
{
    int mult = 1, cont;

    for (cont = 0; cont < 5; cont++)
    {
        printf ("3 x %d = %d\n", mult, mult*3);
        mult++;
    }

    return 0;
}