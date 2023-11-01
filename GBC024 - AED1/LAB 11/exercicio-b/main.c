#include "fila.h"
#include <stdio.h>
#include <stdlib.h>

int main ( )
{
    fila *a = criar ( );
    fila *b = criar ( );
    fila *i = NULL;

    int op_menu, op_fila, retorno, numero;

    while (1)
    {
        printf ("\n\nMENU\n");
        printf ("\n(1) inserir elemento");
        printf ("\n(2) remover elemento");
        printf ("\n(3) mostrar fila");
        printf ("\n(4) intercalar filas");
        printf ("\n(5) sair");

        printf ("\n\nopcao escolhida: ");
        scanf ("%d", &op_menu);

        if (op_menu == 5)
        {
            printf ("\nencerrando o programa...");
            break;
        }

        switch (op_menu)
        {
            case 1:
                printf ("\nescolha a fila:");
                printf ("\n(1) fila A");
                printf ("\n(2) fila B");

                do
                {
                    printf ("\n\nfila escolhida: ");
                    scanf ("%d", &op_fila);

                    if ((op_fila != 1) && (op_fila != 2))
                        printf ("opcao invalida, tente novamente...");

                } while ((op_fila != 1) && (op_fila != 2));

                printf ("\ndigite o numero: ");
                scanf ("%d", &numero);

                if (op_fila == 1)
                {
                    retorno = inserir (a, numero);
                    if (retorno == -2)
                        printf ("\nerro: fila nao alocada");
                    if (retorno == -1)
                        printf ("\nerro: fila cheia");
                    if (retorno == 0)
                        printf ("\nnumero inserido na fila");

                } else {
                    retorno = inserir (b, numero);
                    if (retorno == -2)
                        printf ("\nerro: fila nao alocada");
                    if (retorno == -1)
                        printf ("\nerro: fila cheia");
                    if (retorno == 0)
                        printf ("\nnumero inserido na fila");

                }

                break;

            case 2:
                printf ("\nescolha a fila:");
                printf ("\n(1) fila A");
                printf ("\n(2) fila B");

                do
                {
                    printf ("\n\nfila escolhida: ");
                    scanf ("%d", &op_fila);

                    if ((op_fila != 1) && (op_fila != 2))
                        printf ("opcao invalida, tente novamente...");

                } while ((op_fila != 1) && (op_fila != 2));

                if (op_fila == 1)
                {
                    retorno = remover (a, &numero);
                    if (retorno == -2)
                        printf ("\nerro: fila nao alocada");
                    if (retorno == -1)
                        printf ("\nerro: fila vazia");
                    if (retorno == 0)
                        printf ("\nnumero %d removido na fila", numero);

                } else {
                    retorno = remover (b, &numero);
                    if (retorno == -2)
                        printf ("\nerro: fila nao alocada");
                    if (retorno == -1)
                        printf ("\nerro: fila vazia");
                    if (retorno == 0)
                        printf ("\nnumero %d removido na fila", numero);

                }

                break;

            case 3:
                printf ("\nescolha a fila:");
                printf ("\n(1) fila A");
                printf ("\n(2) fila B");

                do
                {
                    printf ("\n\nfila escolhida: ");
                    scanf ("%d", &op_fila);

                    if ((op_fila != 1) && (op_fila != 2))
                        printf ("opcao invalida, tente novamente...");

                } while ((op_fila != 1) && (op_fila != 2));

                if (op_fila == 1) mostrar (a);
                else mostrar (b);

                break;

            case 4:
                printf ("\nfilas intercaladas:\n");
                i = intercalada (a, b);
                mostrar (i);

                break;

            default:
                printf ("\nopcao invalida, tente novamente...");
        }
    }

    limpar (a);
    limpar (b);
    limpar (i);

    return 0;
}
