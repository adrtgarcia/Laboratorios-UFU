#include <stdio.h>

int main ( )
{
    int a, b;
    int *pa = NULL, *pb = NULL;

    pa = &a; 
    pb = &b;

    printf ("digite o valor de a: ");
    scanf ("%d", &a);
    printf ("digite o valor de b: ");
    scanf ("%d", &b);

    if (pa > pb)
    {
        printf ("conteudo do maior endereco (%p) eh %d", pa, a);
    } else if (pa < pb)
    {
        printf ("conteudo do maior endereco (%p) eh %d", pb, b);
    }

    return 0;
}