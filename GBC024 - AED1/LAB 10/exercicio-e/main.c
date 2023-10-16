#include "listasd.h"

#include <stdio.h>
#include <stdlib.h>

int main ( )
{
    lista *l = criar ( );

    int num, posicao, soma, opcao, retorno, i;

    while (1)
    {
        printf ("\nMENU:\n");
        printf ("\n 1 - inserir numero no inicio da lista");
        printf ("\n 2 - inserir numero no fim da lista");
        printf ("\n 3 - inserir numero em posicao especifica da lista");
        printf ("\n 4 - remover numero no inicio da lista");
        printf ("\n 5 - remover numero no fim da lista");
        printf ("\n 6 - remover numero em posicao especifica da lista");
        printf ("\n 7 - remover numero especifico da lista");
        printf ("\n 8 - mostrar ultimo elemento da lista");
        printf ("\n 9 - soma dos elementos da lista");
        printf ("\n10 - limpar lista");
        printf ("\n11 - mostrar lista");
        printf ("\n12 - mostrar lista reversa");
        printf ("\n13 - representacao em binario");
        printf ("\n14 - sair");

        printf ("\n\nopcao escolhida: ");
        scanf ("%d", &opcao);

        if (opcao == 14)
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
                printf ("\ndigite o numero: ");
                scanf ("%d", &num);

                retorno = remover_numero (l, num);
                if (retorno == 2)
                    printf ("\nerro: lista nao alocada");
                else
                    printf ("\nocorrencias apagadas");

                break;

            case 8:
                retorno = procura_ultimo (l, &num);

                if (retorno == 2)
                    printf ("\nerro: lista nao alocada");
                if (retorno == 1)
                    printf ("\nerro: lista vazia");
                if (retorno == 0)
                    printf ("\n%d eh o ultimo elemento da lista", num);

                break;

            case 9:
                soma = soma_elementos (l);
                printf ("\n%d eh a soma de todos os elementos da lista", soma);

                break;

            case 10:
                printf ("\nlimpando lista...");
                limpar (l);
                printf ("\nlista limpa");

                break;

            case 11:
                printf ("\ncarregando lista...\n");
                mostrar (l);

                break;

            case 12:
                printf ("\ncarregando lista...\n");
                printf ("[");
                mostrar_reversa (l);
                printf ("]");

                break;

            case 13:
                printf("\ndigite o binario (8 bits): ");

                for(i = 0; i < 8; i++)
                {
                    printf("bit %d: ", i);
                    scanf("%d", &num);
                    inserir_inicio(l, num);
                }

                printf("\ndigite o inteiro: ");
                scanf("%d", &num);

                for(i = 0; i < num; i++)
                    incrementar(l);

                break;

            default:
                printf ("\nopcao invalida, tente novamente\n");
        }
    }

    return 0;
}
