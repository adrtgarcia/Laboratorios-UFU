#include <stdio.h>

int main ( )
{
    float vet[10];
    float *p = NULL;
    int i;

    p = vet;

    printf ("enderecos de memoria:\n");

    for (i = 0; i < 10; i++)
    {
        printf ("\nvet[%d] = %p", i, (p + i));
    }

    return 0;
}