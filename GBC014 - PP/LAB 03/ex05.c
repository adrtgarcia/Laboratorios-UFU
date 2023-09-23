#include <stdio.h>

int main ( )
{
    int num, soma = 0, cont;
    for (cont = 0; cont < 10; cont++)
    {
        printf ("digite um valor: ");
        scanf ("%d", &num);
        soma += num;
    }

    printf ("\ntotal: %d", soma);

    return 0;
}