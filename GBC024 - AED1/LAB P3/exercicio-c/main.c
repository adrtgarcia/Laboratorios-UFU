#include "fila.h"

#include <stdio.h>
#include <stdlib.h>

int main ( )
{
    fila *f = criarF ( );

    int num = 0, fura, retorno;

    printf ("digite os elementos da fila (negativo encerra):\n");
    while (num >= 0)
    {
        scanf ("%d", &num);
        if (num < 0)
        {
            printf ("\nencerrando leitura...\n");
            break;
        }
        inserir (f, num);
    }

    printf ("\nfila criada:");
    mostrar_fila (f);

    printf ("\ndigite um numero para furar a fila: ");
    scanf ("%d", &fura);

    printf ("\nfurando fila...\n");
    retorno = fura_fila (f, fura);
    if (retorno == -2)
        printf ("\nerro: fila nao alocada\n");
    if (retorno == 0)
        printf ("\nfila furada\n");

    printf ("\nnova fila:");
    mostrar_fila (f);

    limparF (f);

    return 0;
}
