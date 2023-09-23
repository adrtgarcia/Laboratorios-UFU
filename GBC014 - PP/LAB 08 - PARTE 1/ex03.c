#include <stdio.h>

int main ( )
{
    int a = 1, b = 2;
    int *pa = NULL, *pb = NULL;

    pa = &a; 
    pb = &b;

    if (pa > pb)
    {
        printf ("maior endereco eh %p, da variável A", pa, a);
    } else if (pa < pb)
    {
        printf ("maior endereco eh %p, da variável B", pb, b);
    }

    return 0;
}