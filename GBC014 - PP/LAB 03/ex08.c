#include <stdio.h>

int main ( )
{
    int num, menor, maior, cont;

    for (cont = 0; cont < 10; cont++)
    {
        printf ("digite um valor: ");
        scanf ("%d", &num);

        if (cont == 0)
        {
            maior = num;
            menor = num;
        }

        if (num > maior)
        {
            maior = num;
        } else if (num < menor)
        {
            menor = num;
        } else
        {
            continue;
        }
    }

    printf ("\nmenor valor: %d", menor);
    printf ("\nmaior valor: %d", maior);

    return 0;
}