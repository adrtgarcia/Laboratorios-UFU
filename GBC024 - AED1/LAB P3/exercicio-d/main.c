#include "pilha.h"

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main ( )
{
    pilha *p = criarP ( );

    char expressao[100];
    int resultado;

    printf ("digite uma expressao matematica em notacao polonesa (posfixa): ");
    fgets (expressao, 100, stdin);
    expressao[strcspn(expressao, "\n")] = '\0';

    resultado = polonesa (expressao);
    printf ("resultado: %d", resultado);

    limparP (p);

    return 0;
}
