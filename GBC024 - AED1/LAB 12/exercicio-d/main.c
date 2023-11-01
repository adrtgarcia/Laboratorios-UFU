#include "pilha.h"
#include "lista.h"

#include <stdio.h>
#include <stdlib.h>

int main ( )
{
    pilha *p = criar_pilha ( );
    lista *l = criar_lista ( );

    int decimal, retorno;

    printf ("digite um numero em decimal: ");
    scanf ("%d", &decimal);

    retorno = binario (l, decimal);
    if (retorno == -2)
        printf ("\nerro: alocacao da lista");
    if (retorno == -1)
        printf ("\nerro: alocacao da pilha");
    if (retorno == 0)
    {
        printf ("\nem binario:");
        mostrar_lista (l);
    }

    limpar_pilha (p);
    limpar_lista (l);

    return 0;
}
