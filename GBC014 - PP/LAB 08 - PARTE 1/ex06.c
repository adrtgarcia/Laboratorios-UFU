#include <stdio.h>

int main ( )
{
    int a, b;
    int *pa, *pb;

    pa = &a;
    pb = &b;

    printf ("digite o valor de A: ");
    scanf ("%d", &(*pa));
    printf ("digite o valor de B: ");
    scanf ("%d", &(*pb));

    printf ("\nA + B = %d", (*pa + *pb));
    printf ("\nA - B = %d", (*pa - *pb));
    printf ("\nA * B = %d", (*pa * *pb));
    printf ("\nA / B = %d", (*pa / *pb));

    return 0;
}