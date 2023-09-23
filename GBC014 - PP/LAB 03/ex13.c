#include <stdio.h>

int main ( )
{
    int num = 0, soma = 0, cont;

    for (cont = 0; num < 1000; cont++)
    {
        if (num%3 == 0)
        {
            soma = soma + num;
            num++;
        } else if (num%5 == 0)
        {
            soma = soma + num;
            num++;
        } else
        {
            num++;
        }
    }

    printf ("a soma dos numeros naturais menores que 1000 e multiplos de 3 ou 5 eh: %d", soma);

    return 0;
}