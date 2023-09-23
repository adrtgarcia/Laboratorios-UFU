#include <stdio.h>

int main ( )
{
    int num = 0, cont;
    for (cont = 0; cont < 101; cont++)
    {
        printf ("%d\n", num);
        num = num + 1000;
    }

    return 0;
}