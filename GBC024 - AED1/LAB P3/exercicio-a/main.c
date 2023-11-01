#include "fila.h"
#include "pilha.h"

#include <stdio.h>
#include <stdlib.h>

int main ( )
{
    fila *f = criar_fila ( );

    int num = 0;

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

    printf ("\nfila invertida:");
    inverte_fila (f);

    limpar_fila (f);

    return 0;
}
