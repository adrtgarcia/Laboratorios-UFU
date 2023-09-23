#include <stdio.h>      //printf

int main ( )
{
    double vet[10];
    int i;

    for (i = 0; i < 10; i++)
    {
        printf ("\nvet[%d] = %lf", i, *(vet + i));
    }

    return 0;
}