#include "listacirc.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main ( )
{
    lista *la = criar ( );
    lista *lb = criar ( );
    lista *lc;

    aluno a;

    int opcao, opcao2, resultado, posicao, matricula;

    while (1)
    {
        printf ("\n\nMENU\n");
        printf ("\n 1 - inserir aluno no inicio");
        printf ("\n 2 - inserir aluno no fim");
        printf ("\n 3 - inserir aluno em uma posicao");
        printf ("\n 4 - remover aluno do inicio");
        printf ("\n 5 - remover aluno do fim");
        printf ("\n 6 - remover aluno de uma posicao");
        printf ("\n 7 - remover aluno do meio");
        printf ("\n 8 - remover item");
        printf ("\n 9 - buscar aluno na lista");
        printf ("\n10 - buscar posicao na lista");
        printf ("\n11 - intersecao de duas listas");
        printf ("\n12 - mostrar lista");
        printf ("\n13 - limpar lista");
        printf ("\n14 - sair");

        printf ("\n\nopcao escolhida: ");
        scanf ("%d", &opcao);

        if (opcao == 14)
        {
            printf ("\nencerrando o programa...");
            free (la);
            free (lb);
            break;
        }

        switch (opcao)
        {
            case 1:
                printf ("\n\nescolha a lista:");
                printf ("\n1 - lista A, 2 - lista B");

                do
                {
                    printf ("\nlista escolhida: ");
                    scanf ("%d", &opcao);
                    if ((opcao != 1) && (opcao != 2))
                        printf ("\nopcao invalida");
                } while ((opcao != 1) && (opcao != 2));

                printf ("\n\ndigite a matricula do aluno: ");
                scanf ("%d", &a.mat);

                printf ("digite o nome do aluno: ");
                setbuf (stdin, NULL);
                fgets (a.nome, 30, stdin);
                a.nome[strcspn(a.nome, "\n")] = '\0';

                printf ("digite a nota do aluno: ");
                scanf ("%f", &a.n1);

                if (opcao == 1)
                {
                    resultado = inserir_inicio(la, a);
                    if (resultado == 2)
                        printf ("\nerro: lista nao alocada");
                    if (resultado == 0)
                        printf ("\naluno inserido");
                    break;
                } else {
                    resultado = inserir_inicio(lb, a);
                    if (resultado == 2)
                        printf ("\nerro: lista nao alocada");
                    if (resultado == 0)
                        printf ("\naluno inserido");
                    break;
                }

            case 2:
                printf ("\n\nescolha a lista:");
                printf ("\n1 - lista A, 2 - lista B");

                do
                {
                    printf ("\nlista escolhida: ");
                    scanf ("%d", &opcao);
                    if ((opcao != 1) && (opcao != 2))
                        printf ("\nopcao invalida");
                } while ((opcao != 1) && (opcao != 2));

                printf ("\n\ndigite a matricula do aluno: ");
                scanf ("%d", &a.mat);

                printf ("digite o nome do aluno: ");
                setbuf (stdin, NULL);
                fgets (a.nome, 30, stdin);
                a.nome[strcspn(a.nome, "\n")] = '\0';

                printf ("digite a nota do aluno: ");
                scanf ("%f", &a.n1);

                if (opcao == 1)
                {
                    resultado = inserir_fim(la, a);
                    if (resultado == 2)
                        printf ("\nerro: lista nao alocada");
                    if (resultado == 1)
                        printf ("\nerro: aluno ja esta na lista");
                    if (resultado == 0)
                        printf ("\naluno inserido");
                    break;
                } else {
                    resultado = inserir_fim(lb, a);
                    if (resultado == 2)
                        printf ("\nerro: lista nao alocada");
                    if (resultado == 1)
                        printf ("\nerro: aluno ja esta na lista");
                    if (resultado == 0)
                        printf ("\naluno inserido");
                    break;
                }

            case 3:
                printf ("\n\nescolha a lista:");
                printf ("\n1 - lista A, 2 - lista B");

                do
                {
                    printf ("\nlista escolhida: ");
                    scanf ("%d", &opcao);
                    if ((opcao != 1) && (opcao != 2))
                        printf ("\nopcao invalida");
                } while ((opcao != 1) && (opcao != 2));

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

                if (opcao == 1)
                {
                    resultado = inserir_posicao(la, a, posicao);
                    if (resultado == 2)
                        printf ("\nerro: lista nao alocada");
                    if (resultado == 0)
                        printf ("\naluno inserido");
                    break;
                } else {
                    resultado = inserir_posicao(lb, a, posicao);
                    if (resultado == 2)
                        printf ("\nerro: lista nao alocada");
                    if (resultado == 0)
                        printf ("\naluno inserido");
                    break;
                }

            case 4:
                printf ("\n\nescolha a lista:");
                printf ("\n1 - lista A, 2 - lista B");

                do
                {
                    printf ("\nlista escolhida: ");
                    scanf ("%d", &opcao);
                    if ((opcao != 1) && (opcao != 2))
                        printf ("\nopcao invalida");
                } while ((opcao != 1) && (opcao != 2));

                if (opcao == 1)
                {
                    resultado = remover_inicio(la);
                    if (resultado == 2)
                        printf ("\nerro: lista nao alocada");
                    if (resultado == 1)
                        printf ("\nerro: lista vazia");
                    if (resultado == 0)
                        printf ("\naluno removido");
                    break;
                } else {
                    resultado = remover_inicio(lb);
                    if (resultado == 2)
                        printf ("\nerro: lista nao alocada");
                    if (resultado == 1)
                        printf ("\nerro: lista vazia");
                    if (resultado == 0)
                        printf ("\naluno removido");
                    break;
                }

            case 5:
                printf ("\n\nescolha a lista:");
                printf ("\n1 - lista A, 2 - lista B");

                do
                {
                    printf ("\nlista escolhida: ");
                    scanf ("%d", &opcao);
                    if ((opcao != 1) && (opcao != 2))
                        printf ("\nopcao invalida");
                } while ((opcao != 1) && (opcao != 2));

                if (opcao == 1)
                {
                    resultado = remover_fim(la);
                    if (resultado == 2)
                        printf ("\nerro: lista nao alocada");
                    if (resultado == 1)
                        printf ("\nerro: lista vazia");
                    if (resultado == 0)
                        printf ("\naluno removido");
                    break;
                } else {
                    resultado = remover_fim(lb);
                    if (resultado == 2)
                        printf ("\nerro: lista nao alocada");
                    if (resultado == 1)
                        printf ("\nerro: lista vazia");
                    if (resultado == 0)
                        printf ("\naluno removido");
                    break;
                }

            case 6:
                printf ("\n\nescolha a lista:");
                printf ("\n1 - lista A, 2 - lista B");

                do
                {
                    printf ("\nlista escolhida: ");
                    scanf ("%d", &opcao);
                    if ((opcao != 1) && (opcao != 2))
                        printf ("\nopcao invalida");
                } while ((opcao != 1) && (opcao != 2));

                printf ("\n\ndigite a posicao: ");
                scanf ("%d", &posicao);

                if (opcao == 1)
                {
                    resultado = remover_posicao (la, posicao);
                    if (resultado == 2)
                        printf ("\nerro: lista nao alocada");
                    if (resultado == 1)
                        printf ("\nerro: lista vazia");
                    if (resultado == 0)
                        printf ("\naluno removido");
                    break;
                } else {
                    resultado = remover_posicao (lb, posicao);
                    if (resultado == 2)
                        printf ("\nerro: lista nao alocada");
                    if (resultado == 1)
                        printf ("\nerro: lista vazia");
                    if (resultado == 0)
                        printf ("\naluno removido");
                    break;
                }

            case 7:
                printf ("\n\nescolha a lista:");
                printf ("\n1 - lista A, 2 - lista B");

                do
                {
                    printf ("\nlista escolhida: ");
                    scanf ("%d", &opcao);
                    if ((opcao != 1) && (opcao != 2))
                        printf ("\nopcao invalida");
                } while ((opcao != 1) && (opcao != 2));

                if (opcao == 1)
                {
                    resultado = remover_centro (la);
                    if (resultado == 2)
                        printf ("\n\nerro: lista nao alocada");
                    if (resultado == 1)
                        printf ("\n\nerro: lista vazia");
                    if (resultado == 0)
                        printf ("\n\naluno removido");
                    break;
                } else {
                    resultado = remover_centro (lb);
                    if (resultado == 2)
                        printf ("\n\nerro: lista nao alocada");
                    if (resultado == 1)
                        printf ("\n\nerro: lista vazia");
                    if (resultado == 0)
                        printf ("\n\naluno removido");
                    break;
                }

            case 8:
                printf ("\n\nescolha a lista:");
                printf ("\n1 - lista A, 2 - lista B");

                do
                {
                    printf ("\nlista escolhida: ");
                    scanf ("%d", &opcao);
                    if ((opcao != 1) && (opcao != 2))
                        printf ("\nopcao invalida");
                } while ((opcao != 1) && (opcao != 2));

                printf ("\n\ndigite a matricula do aluno: ");
                scanf ("%d", &matricula);

                printf ("\no que deseja fazer?");
                printf ("\n1 - remover primeira ocorrencia");
                printf ("\n2 - remover todas as ocorrencias");

                do
                {
                    printf ("\nopcao escolhia: ");
                    scanf ("%d", &opcao2);

                    if ((opcao2 != 1) && (opcao2 != 2))
                        printf ("opcao invalida");
                } while ((opcao2 != 1) && (opcao2 != 2));

                if (opcao2 == 1)
                {
                    if (opcao == 1)
                    {
                        resultado = remover_1oitem (la, matricula);
                        if (resultado == 2)
                            printf ("\nerro: lista nao alocada");
                        if (resultado == 1)
                            printf ("\nerro: lista vazia");
                        if (resultado == 0)
                            printf ("\nalunos(s) removido(s)");
                        if (resultado == -1)
                            printf ("\nmatricula nao encontrada");
                    } else {
                        resultado = remover_1oitem (lb, matricula);
                        if (resultado == 2)
                            printf ("\nerro: lista nao alocada");
                        if (resultado == 1)
                            printf ("\nerro: lista vazia");
                        if (resultado == 0)
                            printf ("\nalunos(s) removido(s)");
                        if (resultado == -1)
                            printf ("\nmatricula nao encontrada");
                    }
                } else {
                    if (opcao == 1)
                    {
                        resultado = remover_item (la, matricula);
                        if (resultado == 2)
                            printf ("\nerro: lista nao alocada");
                        if (resultado == 1)
                            printf ("\nerro: lista vazia");
                        if (resultado == 0)
                            printf ("\nalunos(s) removido(s)");
                        if (resultado == -1)
                            printf ("\nmatricula nao encontrada");
                    } else {
                        resultado = remover_item (lb, matricula);
                        if (resultado == 2)
                            printf ("\nerro: lista nao alocada");
                        if (resultado == 1)
                            printf ("\nerro: lista vazia");
                        if (resultado == 0)
                            printf ("\nalunos(s) removido(s)");
                        if (resultado == -1)
                            printf ("\nmatricula nao encontrada");
                    }
                }

                break;

            case 9:
                printf ("\n\nescolha a lista:");
                printf ("\n1 - lista A, 2 - lista B");

                do
                {
                    printf ("\nlista escolhida: ");
                    scanf ("%d", &opcao);
                    if ((opcao != 1) && (opcao != 2))
                        printf ("\nopcao invalida");
                } while ((opcao != 1) && (opcao != 2));

                printf ("\n\ndigite a matricula do aluno: ");
                scanf ("%d", &matricula);

                if (opcao == 1)
                {
                    resultado = buscar_itemchave (la, matricula, &a);
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
                } else {
                    resultado = buscar_itemchave (lb, matricula, &a);
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
                }

            case 10:
                printf ("\n\nescolha a lista:");
                printf ("\n1 - lista A, 2 - lista B");

                do
                {
                    printf ("\nlista escolhida: ");
                    scanf ("%d", &opcao);
                    if ((opcao != 1) && (opcao != 2))
                        printf ("\nopcao invalida");
                } while ((opcao != 1) && (opcao != 2));

                printf ("\n\ndigite a posicao: ");
                scanf ("%d", &posicao);

                if (opcao == 1)
                {
                    resultado = buscar_posicao (la, posicao, &matricula);
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
                } else {
                    resultado = buscar_posicao (lb, posicao, &matricula);
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
                }

            case 11:
                lc = intersecao (la, lb);
                printf ("\n\nLISTA DE ALUNOS:\n");
                mostrar (lc);
                free (lc);
                break;

            case 12:
                printf ("\n\nescolha a lista:");
                printf ("\n1 - lista A, 2 - lista B");

                do
                {
                    printf ("\nlista escolhida: ");
                    scanf ("%d", &opcao);
                    if ((opcao != 1) && (opcao != 2))
                        printf ("\nopcao invalida");
                } while ((opcao != 1) && (opcao != 2));

                if (opcao == 1)
                {
                    printf ("\n\nLISTA DE ALUNOS:\n");
                    mostrar (la);
                    break;
                } else {
                    printf ("\n\nLISTA DE ALUNOS:\n");
                    mostrar (lb);
                    break;
                }

            case 13:
                printf ("\n\nescolha a lista:");
                printf ("\n1 - lista A, 2 - lista B");

                do
                {
                    printf ("\nlista escolhida: ");
                    scanf ("%d", &opcao);
                    if ((opcao != 1) && (opcao != 2))
                        printf ("\nopcao invalida");
                } while ((opcao != 1) && (opcao != 2));

                if (opcao == 1)
                {
                    limpar(la);
                    printf ("\n\nlista limpa");
                    break;
                } else {
                    limpar(lb);
                    printf ("\n\nlista limpa");
                    break;
                }

            default:
                printf ("\nopcao invalida, tente novamente");
        }

    }

    return 0;
}
