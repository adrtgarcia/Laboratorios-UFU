#include <stdio.h>      //printf

int main ( )
{
    int vet[10], i;

    for (i = 9; i >= 0; i--)
    {
        printf ("\nvet[%d] = %d", i, *(vet + i));
    }

    return 0;
}