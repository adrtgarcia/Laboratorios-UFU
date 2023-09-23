#include <stdio.h>

int main ( )
{
    int A, *B, **C, ***D;

    printf ("digite o valor de A: ");
    scanf ("%d", &A);

    B = &A;
    C = &B;
    D = &C;

    printf ("\nA x 2 = %d", (*B * 2));
    printf ("\nA x 3 = %d", (**C * 3));
    printf ("\nA x 4 = %d", (***D * 4));

    return 0;
}