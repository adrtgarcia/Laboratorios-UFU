#include "pilhaF.h"

#include <stdio.h>
#include <stdlib.h>

int main ( )
{
    fila *f = criar ( );

    int opcao, retorno;
    int num;

    while (1)
    {
        printf ("\nMENU:\n");
        printf ("\n(1) inserir elemento");
        printf ("\n(2) remover elemento");
        printf ("\n(3) consultar elemento");
        printf ("\n(4) mostrar fila");
        printf ("\n(5) mostrar tamanho");
        printf ("\n(6) sair");

        printf ("\n\nopcao escolhida: ");
        scanf ("%d", &opcao);

        if (opcao == 6)
        {
            printf ("\nencerrando o programa...\n");
            limpar (f);
            break;
        }

        switch (opcao)
        {
            case 1:
                printf ("\ndigite o numero a ser inserido: ");
                scanf ("%d", &num);

                retorno = inserir (f, num);
                if (retorno == -2)
                    printf ("\nerro: fila nao alocada");
                if (retorno == 0)
                    printf ("\nnumero inserido");

                break;

            case 2:
                printf ("\nremovendo numero...");
                retorno = remover (f, &num);

                if (retorno == -2)
                    printf ("\nerro: fila nao alocada");
                if (retorno == -1)
                    printf ("\nerro: fila vazia");
                if (retorno == 0)
                    printf ("\nnumero removido: %d", num);

                break;

            case 3:
                printf ("\nconsultando primeiro da fila...");
                retorno = consultar (f, &num);

                if (retorno == -2)
                    printf ("\nerro: fila nao alocada");
                if (retorno == -1)
                    printf ("\nerro: fila vazia");
                if (retorno == 0)
                    printf ("\nprimeiro da fila: %d", num);

                break;

            case 4:
                printf ("\nfila:");
                mostrar (f);
                break;

            case 5:
                printf ("\ncalculando o tamanho da fila...");
                retorno = tamanho (f);

                if (retorno == -2)
                    printf ("\nerro: fila nao alocada");
                else
                    printf ("\ntamanho: %d", retorno);

                break;

            default:
                printf ("\nopcao invalida... retornando ao menu\n");
        }
    }

    return 0;
}
