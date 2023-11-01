#include "pilha.h"

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main ( )
{
    pilha *p = criar ( );
    char expressao[100];
    int retorno;

    printf ("\ndigite uma string com delimitadores de expressoes matematicas:\n");
    fgets (expressao, 100, stdin);
    expressao[strcspn(expressao, "\n")] = '\0';

    retorno = delimitadores (p, expressao);
    if (retorno == -3)
        printf ("\nerro: caractere(s) invalido(s)");
    if (retorno == -2)
        printf ("\nerro: pilha nao alocada");
    if (retorno == 0)
        printf ("\na sequencia dos delimitadores esta correta");
    if (retorno == 1)
        printf ("\na sequencia dos delimitadores nao esta correta");

    limpar (p);

    return 0;
}
