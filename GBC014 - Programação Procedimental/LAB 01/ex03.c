#include <stdio.h>
// peça ao usuário para digitar TRÊS VALORES INTEIROS e imprima a SOMA deles

int main ( )
{
    int x, y, z; 
    printf ("digite o primeiro valor: ");
    scanf ("%d", &x);

    printf ("digite o segundo valor: ");
    scanf ("%d", &y);

    printf ("digite o terceiro valor: ");
    scanf ("%d", &z);

    int SOMA = x + y + z;
    printf ("soma: %d", SOMA);

    return 0;
}