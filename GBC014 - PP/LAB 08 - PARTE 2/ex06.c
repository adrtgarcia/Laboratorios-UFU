#include <stdio.h>

int main ( )
{
    int vet[5], num;
    int *p = NULL;

    printf ("digite um numero: ");
    scanf ("%d", &num);

    printf ("vet[");

    for (p = vet; p < vet + 5; p++)
    {
        *p = num;
        printf (" %d ", *p);
    }

    printf ("]");

    return 0;
}