#include "listacirc.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main ( )
{
    lista *l = criar ( );
    aluno a;

    int opcao, resultado, posicao, matricula;

    while (1)
    {
        printf ("\n\nMENU\n");
        printf ("\n 1 - inserir aluno no inicio");
        printf ("\n 2 - inserir aluno no fim");
        printf ("\n 3 - inserir aluno em uma posicao");
        printf ("\n 4 - remover aluno do inicio");
        printf ("\n 5 - remover aluno do fim");
        printf ("\n 6 - remover aluno de uma posicao");
        printf ("\n 7 - remover item");
        printf ("\n 8 - buscar aluno na lista");
        printf ("\n 9 - buscar posicao na lista");
        printf ("\n10 - mostrar lista");
        printf ("\n11 - limpar lista");
        printf ("\n12 - sair");

        printf ("\n\nopcao escolhida: ");
        scanf ("%d", &opcao);

        if (opcao == 12)
        {
            printf ("\nencerrando o programa...");
            free (l);
            break;
        }

        switch (opcao)
        {
            case 1:
                printf ("\n\ndigite a matricula do aluno: ");
                scanf ("%d", &a.mat);

                printf ("digite o nome do aluno: ");
                setbuf (stdin, NULL);
                fgets (a.nome, 30, stdin);
                a.nome[strcspn(a.nome, "\n")] = '\0';

                printf ("digite a nota do aluno: ");
                scanf ("%f", &a.n1);

                resultado = inserir_inicio(l, a);
                if (resultado == 2)
                    printf ("\nerro: lista nao alocada");
                if (resultado == 0)
                    printf ("\naluno inserido");

                break;

            case 2:
                printf ("\n\ndigite a matricula do aluno: ");
                scanf ("%d", &a.mat);

                printf ("digite o nome do aluno: ");
                setbuf (stdin, NULL);
                fgets (a.nome, 30, stdin);
                a.nome[strcspn(a.nome, "\n")] = '\0';

                printf ("digite a nota do aluno: ");
                scanf ("%f", &a.n1);

                resultado = inserir_fim(l, a);
                if (resultado == 2)
                    printf ("\nerro: lista nao alocada");
                if (resultado == 0)
                    printf ("\naluno inserido");

                break;

            case 3:
                printf ("\n\ndigite a matricula do aluno: ");
                scanf ("%d", &a.mat);

                printf ("digite o nome do aluno: ");
                setbuf (stdin, NULL);
                fgets (a.nome, 30, stdin);
                a.nome[strcspn(a.nome, "\n")] = '\0';

                printf ("digite a nota do aluno: ");
                scanf ("%f", &a.n1);

                do
                {
                    printf ("digite a posicao: ");
                    scanf ("%d", &posicao);

                    if (posicao < 0)
                        printf ("posicao invalida\n");

                } while (posicao < 0);

                resultado = inserir_posicao(l, a, posicao);
                if (resultado == 2)
                    printf ("\nerro: lista nao alocada");
                if (resultado == 0)
                    printf ("\naluno inserido");

                break;

            case 4:
                resultado = remover_inicio(l);
                if (resultado == 2)
                    printf ("\nerro: lista nao alocada");
                if (resultado == 1)
                    printf ("\nerro: lista vazia");
                if (resultado == 0)
                    printf ("\naluno removido");

                break;

            case 5:
                resultado = remover_fim(l);
                if (resultado == 2)
                    printf ("\nerro: lista nao alocada");
                if (resultado == 1)
                    printf ("\nerro: lista vazia");
                if (resultado == 0)
                    printf ("\naluno removido");

                break;

            case 6:
                printf ("\n\ndigite a posicao: ");
                scanf ("%d", &posicao);

                resultado = remover_posicao (l, posicao);
                if (resultado == 2)
                    printf ("\nerro: lista nao alocada");
                if (resultado == 1)
                    printf ("\nerro: lista vazia");
                if (resultado == 0)
                    printf ("\naluno removido");

                break;

            case 7:
                printf ("\n\ndigite a matricula do aluno: ");
                scanf ("%d" &matricula);

                resultado = remover_item (l, matricula);
                if (resultado == 2)
                    printf ("\nerro: lista nao alocada");
                if (resultado == 1)
                    printf ("\nerro: lista vazia");
                if (resultado == 0)
                    printf ("\nalunos(s) removido(s)");
                if (resultado == -1)
                    printf ("\nmatricula nao encontrada");

                break;

            case 8:
                printf ("\n\ndigite a matricula do aluno: ");
                scanf ("%d", &matricula);

                resultado = buscar_itemchave (l, matricula, &a);
                if (resultado == 2)
                    printf ("\nerro: lista nao alocada");
                if (resultado == 1)
                    printf ("\nerro: lista vazia");
                if (resultado == 0)
                {
                    printf ("\naluno encontrado: ");
                    printf ("\n[ %d, %s, %.2f ]", a.mat, a.nome, a.n1);
                }
                if (resultado == -1)
                    printf ("\naluno nao encontrado");

                break;

            case 9:
                printf ("\n\ndigite a posicao: ");
                scanf ("%d", &posicao);

                resultado = buscar_posicao (l, posicao, &matricula);
                if (resultado == 2)
                    printf ("\nerro: lista nao alocada");
                if (resultado == 1)
                    printf ("\nerro: lista vazia");
                if (resultado == 0)
                {
                    printf ("\naluno encontrado");
                    printf ("\nmatricula: %d", matricula);
                }
                if (resultado == -1)
                    printf ("\nnao ha aluno nessa posicao");

                break;

            case 10:
                printf ("\n\nLISTA DE ALUNOS:\n");
                mostrar(l);

                break;

            case 11:
                limpar(l);
                printf ("\n\nlista limpa");

                break;

            default:
                printf ("\nopcao invalida, tente novamente");
        }

    }

    return 0;
}
