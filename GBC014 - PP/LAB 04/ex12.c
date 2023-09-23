#include <stdio.h>

int soma_algarismos (int x);

int main ( )
{
    int num;
    printf ("digite um numero: ");
    scanf ("%d", &num);

    if (num <= 0)
    {
        printf ("numero invalido");
    } else
    {
        printf ("a soma dos algarismos eh %d", soma_algarismos (num));
    }

    return 0;
}

int soma_algarismos (int x)
{
    int soma = 0, algarismo;
    
    while (x != 0) 
    {
        algarismo = x % 10;
        soma += algarismo;
        x /= 10;
    }

    return soma;
}