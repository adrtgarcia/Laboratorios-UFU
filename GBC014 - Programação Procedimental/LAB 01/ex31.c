#include <stdio.h>
// leia um NÚMERO INTEIRO e imprima seu ANTECESSOR e seu SUCESSOR

int main ( )
{
    int x;
    printf ("digite um numero: ");
    scanf ("%d", &x);

    int A = x - 1, S = x + 1;
    printf ("antecessor: %d \n", A);
    printf ("sucessor: %d", S);

    return 0;
}