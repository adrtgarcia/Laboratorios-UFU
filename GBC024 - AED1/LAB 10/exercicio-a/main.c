#include "listasd.h"

#include <stdio.h>
#include <stdlib.h>

int main ( )
{
    lista *l = criar ( );

    int num, posicao, opcao, retorno;

    while (1)
    {
        printf ("\nMENU:\n");
        printf ("\n 1 - inserir numero no inicio da lista");
        printf ("\n 2 - inserir numero no fim da lista");
        printf ("\n 3 - inserir numero em posicao especifica da lista");
        printf ("\n 4 - remover numero no inicio da lista");
        printf ("\n 5 - remover numero no fim da lista");
        printf ("\n 6 - remover numero em posicao especifica da lista");
        printf ("\n 7 - mostrar ultimo elemento da lista");
        printf ("\n 8 - limpar lista");
        printf ("\n 9 - mostrar lista");
        printf ("\n10 - sair");

        printf ("\n\nopcao escolhida: ");
        scanf ("%d", &opcao);

        if (opcao == 10)
        {
            printf ("\nencerrando o programa...\n");
            free (l);
            l = NULL;
            break;
        }

        switch (opcao)
        {
            case 1:
                printf ("\ndigite o numero: ");
                scanf ("%d", &num);

                retorno = inserir_inicio (l, num);
                if (retorno == 2)
                    printf ("\nerro: lista nao alocada");
                if (retorno == 0)
                    printf ("\nnumero inserido");

                break;

            case 2:
                printf ("\ndigite o numero: ");
                scanf ("%d", &num);

                retorno = inserir_fim (l, num);
                if (retorno == 2)
                    printf ("\nerro: lista nao alocada");
                if (retorno == 0)
                    printf ("\nnumero inserido");

                break;

            case 3:
                printf ("\ndigite o numero: ");
                scanf ("%d", &num);

                printf ("\ndigite a posicao: ");
                scanf ("%d", &posicao);

                retorno = inserir_posicao (l, num, posicao);
                if (retorno == 2)
                    printf ("\nerro: lista nao alocada");
                if (retorno == 3)
                    printf ("\nerro: posicao invalida");
                if (retorno == 0)
                    printf ("\nnumero inserido");

                break;

            case 4:
                retorno = remover_inicio (l);

                if (retorno == 2)
                    printf ("\nerro: lista nao alocada");
                if (retorno == 1)
                    printf ("\nerro: lista vazia");
                if (retorno == 0)
                    printf ("\nnumero removido");

                break;

            case 5:
                retorno = remover_fim (l);

                if (retorno == 2)
                    printf ("\nerro: lista nao alocada");
                if (retorno == 1)
                    printf ("\nerro: lista vazia");
                if (retorno == 0)
                    printf ("\nnumero removido");

                break;

            case 6:
                printf ("\ndigite a posicao: ");
                scanf ("%d", &posicao);

                retorno = remover_posicao (l, posicao);
                if (retorno == 2)
                    printf ("\nerro: lista nao alocada");
                if (retorno == 1)
                    printf ("\nerro: lista vazia");
                if (retorno == 3)
                    printf ("\nerro: posicao invalida");
                if (retorno == 0)
                    printf ("\nnumero removido");

                break;

            case 7:
                retorno = procura_ultimo (l, &num);

                if (retorno == 2)
                    printf ("\nerro: lista nao alocada");
                if (retorno == 1)
                    printf ("\nerro: lista vazia");
                if (retorno == 0)
                    printf ("\n%d eh o ultimo elemento da lista", num);

                break;

            case 8:
                printf ("\nlimpando lista...");
                limpar (l);
                printf ("\nlista limpa");

                break;

            case 9:
                printf ("\ncarregando lista...\n");
                mostrar (l);

                break;

            default:
                printf ("\nopcao invalida, tente novamente\n");
        }
    }

    return 0;
}
