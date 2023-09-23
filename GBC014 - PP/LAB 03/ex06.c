#include <stdio.h>

int main ( )
{
    int num, soma = 0, cont;
    float media;

    for (cont = 0; cont < 10; cont++)
    {
        printf ("digite um valor: ");
        scanf ("%d", &num);
        soma += num;
    }

    media = (float) soma/10;
    printf ("\nmedia: %.2f", media);

    return 0;
}