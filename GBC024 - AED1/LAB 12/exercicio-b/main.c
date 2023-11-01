#include "pilha.h"

#include <stdio.h>
#include <stdlib.h>

int main ( )
{
    pilha *a = criar ( ), *b = criar ( );
    int num = 0, retorno;

    printf ("\ndigite os elementos da pilha A (negativo encerra):\n");
    while (num >= 0)
    {
        scanf ("%d", &num);
        if (num >= 0)
            push (a, num);
        else printf ("\nencerrando leitura...");
    }

    num = 0;

    printf ("\ndigite os elementos da pilha B (negativo encerra):\n");
    while (num >= 0)
    {
        scanf ("%d", &num);
        if (num >= 0)
            push (b, num);
        else printf ("\nencerrando leitura...");
    }

    retorno = comparar (a, b);
    if (retorno == -2)
        printf ("\nerro: pilha(s) nao alocada(s)");
    if (retorno == 0)
        printf ("\nas pilhas sao iguais");
    if (retorno == 1)
        printf ("\nas pilhas sao diferentes");

    limpar (a);
    limpar (b);

    return 0;

}
