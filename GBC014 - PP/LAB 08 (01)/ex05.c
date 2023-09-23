#include <stdio.h>

int main ( )
{
    int A, B;
    int *pa, *pb;

    pa = &A;
    pb = &B;

    printf ("digite o valor de A: ");
    scanf ("%d", &A);
    printf ("digite o valor de B: ");
    scanf ("%d", &B);

    *pa = 2 * A;
    *pb = 2 * B;

    printf ("2A + 2B = %d", (*pa + *pb));

    return 0;
}