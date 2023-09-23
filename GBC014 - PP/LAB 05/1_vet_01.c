#include <stdio.h>

int main ( )
{
    int A[6], soma, cont;
    
    A[0] = 1;
    A[1] = 0;
    A[2] = 5;
    A[3] = -2;
    A[4] = -5;
    A[5] = 7;
    
    soma = A[0] + A[1] + A[5];
    printf ("A[0] + A[1] + A[5] = %d", soma);
    
    A[4] = 100;
    
    printf ("\n\nvalores do vetor A:");
    for (cont = 0; cont < 6; cont++)
    {
        printf ("%d\n", A[cont]);
    }
    
    return 0;
}
