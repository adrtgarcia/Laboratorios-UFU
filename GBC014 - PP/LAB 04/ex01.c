#include <stdio.h>

int dobro (int a);

int main ( )
{
    int num1, num2;
    printf ("digite um numero: ");
    scanf ("%d", &num1);

    num2 = dobro (num1);

    printf ("o dobro de %d eh %d", num1, num2);

    return 0;
}

int dobro (int a)
{
    return a*2;
}