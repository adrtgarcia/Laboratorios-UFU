#include <stdio.h>

int main ( )
{
    int num = 0, soma = 0, cont;

    for (cont = 0; cont <= 50; cont++)
    {
        soma = soma + num;
        num = num + 2;
    }

    printf ("a soma dos 50 primeiros numeros pares eh: %d", soma);

    return 0;
}