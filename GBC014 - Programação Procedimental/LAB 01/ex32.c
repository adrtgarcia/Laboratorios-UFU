#include <stdio.h>
// leia um NÚMERO INTEIRO e imprima a SOMA do SUCESSOR DE SEU TRIPLO com o ANTECESSOR DE SEU DOBRO

int main ( )
{
    int x;
    printf ("digite um numero: ");
    scanf ("%d", &x);

    int y = (3 * x) + 1, z = (2 * x) - 1;
    int SOMA = y + z;
    printf ("resultado: %d", SOMA);

    return 0;
}