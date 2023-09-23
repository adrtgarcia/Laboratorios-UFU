#include "listaenc.h"

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main ( )
{
    lista *l1, *l2, *concatenada;
    aluno a;
    int opcao, op_lista, retorno, posicao, chave;

    l1 = criar ( );
    l2 = criar ( );

    while (1)
    {
        printf ("\n\nMENU\n");
        printf ("\n 1 - inserir aluno no inicio da lista");
        printf ("\n 2 - inserir aluno no fim da lista");
        printf ("\n 3 - inserir aluno em posicao especifica da lista");
        printf ("\n 4 - remover aluno no inicio da lista");
        printf ("\n 5 - remover aluno no fim da lista");
        printf ("\n 6 - remover aluno em posicao especifica da lista");
        printf ("\n 7 - remover aluno especifico da lista");
        printf ("\n 8 - buscar aluno chave na lista");
        printf ("\n 9 - buscar posicao na lista");
        printf ("\n10 - buscar item na lista");
        printf ("\n11 - concatenar listas");
        printf ("\n12 - procurar aluno com maior nota");
        printf ("\n13 - limpar a lista");
        printf ("\n14 - mostrar a lista");
        printf ("\n15 - encerrar o programa");

        printf ("\n\nopcao escolhida: ");
        scanf ("%d", &opcao);

        if (opcao == 15)
        {
            printf ("\n\nencerrando o programa...");
            free (l1);
            free (l2);
            break;
        }

        switch (opcao)
        {
            case 1:
                printf ("\ndigite a matricula do aluno: ");
                scanf ("%d", &a.mat);

                setbuf (stdin, NULL);
                printf ("\ndigite o nome do aluno: ");
                fgets (a.nome, 30, stdin);
                a.nome[strcspn("\n", a.nome)] = '\0';

                printf ("\ndigite a nota do aluno: ");
                scanf ("%f", &a.n1);

                op_lista = 0;

                do
                {
                    printf ("\nem qual lista deseja adicionar o aluno?");
                    printf ("\n1 - lista A, 2 - lista B\n");
                    scanf ("%d", &op_lista);

                    if ((op_lista != 1) && (op_lista != 2))
                        printf ("opcao invalida\n");

                } while ((op_lista != 1) && (op_lista != 2));

                if (op_lista == 1)
                {
                    retorno = inserir_inicio (l1, a);

                    if (retorno == 2)
                        printf ("\nerro: lista nao alocada");
                    if (retorno == -2)
                        printf ("\nerro: no nao alocado");
                    if (retorno == 0)
                        printf ("\naluno inserido");

                    break;
                } else
                {
                   retorno = inserir_inicio (l2, a);

                    if (retorno == 2)
                        printf ("\nerro: lista nao alocada");
                    if (retorno == -2)
                        printf ("\nerro: no nao alocado");
                    if (retorno == 0)
                        printf ("\naluno inserido");

                    break;
                }

            case 2:
                printf ("\ndigite a matricula do aluno: ");
                scanf ("%d", &a.mat);

                setbuf (stdin, NULL);
                printf ("\ndigite o nome do aluno: ");
                fgets (a.nome, 30, stdin);
                a.nome[strcspn("\n", a.nome)] = '\0';

                printf ("\ndigite a nota do aluno: ");
                scanf ("%f", &a.n1);

                op_lista = 0;

                do
                {
                    printf ("\nem qual lista deseja adicionar o aluno?");
                    printf ("\n1 - lista A, 2 - lista B\n");
                    scanf ("%d", &op_lista);

                    if ((op_lista != 1) && (op_lista != 2))
                        printf ("opcao invalida\n");

                } while ((op_lista != 1) && (op_lista != 2));

                if (op_lista == 1)
                {
                    retorno = inserir_fim (l1, a);

                    if (retorno == 2)
                        printf ("\nerro: lista nao alocada");
                    if (retorno == -2)
                        printf ("\nerro: no nao alocado");
                    if (retorno == 0)
                        printf ("\naluno inserido");

                    break;
                } else
                {
                    retorno = inserir_fim (l2, a);

                    if (retorno == 2)
                        printf ("\nerro: lista nao alocada");
                    if (retorno == -2)
                        printf ("\nerro: no nao alocado");
                    if (retorno == 0)
                        printf ("\naluno inserido");

                    break;
                }

            case 3:
                printf ("\ndigite a matricula do aluno: ");
                scanf ("%d", &a.mat);

                setbuf (stdin, NULL);
                printf ("\ndigite o nome do aluno: ");
                fgets (a.nome, 30, stdin);
                a.nome[strcspn("\n", a.nome)] = '\0';

                printf ("\ndigite a nota do aluno: ");
                scanf ("%f", &a.n1);

                printf ("\ndigite a posicao: ");
                scanf ("%d", &posicao);

                op_lista = 0;

                do
                {
                    printf ("\nem qual lista deseja adicionar o aluno?");
                    printf ("\n1 - lista A, 2 - lista B\n");
                    scanf ("%d", &op_lista);

                    if ((op_lista != 1) && (op_lista != 2))
                        printf ("opcao invalida\n");

                } while ((op_lista != 1) && (op_lista != 2));

                if (op_lista == 1)
                {
                    retorno = inserir_posicao (l1, a, posicao);

                    if (retorno == 2)
                        printf ("\nerro: lista nao alocada");
                    if (retorno == 3)
                        printf ("\nerro: posicao invalida");
                    if (retorno == -2)
                        printf ("\nerro: no nao alocado");
                    if (retorno == 0)
                        printf ("\naluno inserido");

                    break;
                } else
                {
                    retorno = inserir_posicao (l2, a, posicao);

                    if (retorno == 2)
                        printf ("\nerro: lista nao alocada");
                    if (retorno == 3)
                        printf ("\nerro: posicao invalida");
                    if (retorno == -2)
                        printf ("\nerro: no nao alocado");
                    if (retorno == 0)
                        printf ("\naluno inserido");

                    break;
                }

            case 4:
                op_lista = 0;

                do
                {
                    printf ("\nde qual lista deseja remover o aluno?");
                    printf ("\n1 - lista A, 2 - lista B\n");
                    scanf ("%d", &op_lista);

                    if ((op_lista != 1) && (op_lista != 2))
                        printf ("opcao invalida\n");

                } while ((op_lista != 1) && (op_lista != 2));

                printf ("\nremovendo aluno...");

                if (op_lista == 1)
                {
                    retorno = remover_inicio (l1);

                    if (retorno == 2)
                        printf ("\nerro: lista nao alocada");
                    if (retorno == 1)
                        printf ("\nerro: lista vazia");
                    if (retorno == 0)
                        printf ("\naluno removido");

                    break;
                } else
                {
                    retorno = remover_inicio (l2);

                    if (retorno == 2)
                        printf ("\nerro: lista nao alocada");
                    if (retorno == 1)
                        printf ("\nerro: lista vazia");
                    if (retorno == 0)
                        printf ("\naluno removido");

                    break;
                }

            case 5:
                op_lista = 0;

                do
                {
                    printf ("\nde qual lista deseja remover o aluno?");
                    printf ("\n1 - lista A, 2 - lista B\n");
                    scanf ("%d", &op_lista);

                    if ((op_lista != 1) && (op_lista != 2))
                        printf ("opcao invalida\n");

                } while ((op_lista != 1) && (op_lista != 2));

                printf ("\nremovendo aluno...");

                if (op_lista == 1)
                {
                    retorno = remover_fim (l1);

                    if (retorno == 2)
                        printf ("\nerro: lista nao alocada");
                    if (retorno == 1)
                        printf ("\nerro: lista vazia");
                    if (retorno == 0)
                        printf ("\naluno removido");

                    break;
                } else
                {
                    retorno = remover_fim (l2);

                    if (retorno == 2)
                        printf ("\nerro: lista nao alocada");
                    if (retorno == 1)
                        printf ("\nerro: lista vazia");
                    if (retorno == 0)
                        printf ("\naluno removido");

                    break;
                }

            case 6:
                printf ("\ndigite a posicao: ");
                scanf ("%d", &posicao);

                op_lista = 0;

                do
                {
                    printf ("\nde qual lista deseja remover o aluno?");
                    printf ("\n1 - lista A, 2 - lista B\n");
                    scanf ("%d", &op_lista);

                    if ((op_lista != 1) && (op_lista != 2))
                        printf ("opcao invalida\n");

                } while ((op_lista != 1) && (op_lista != 2));

                printf ("\nbuscando posicao...");

                if (op_lista == 1)
                {
                    retorno = remover_posicao (l1, posicao);

                    if (retorno == 2)
                        printf ("\nerro: lista nao alocada");
                    if (retorno == 1)
                        printf ("\nerro: lista vazia");
                    if (retorno == 0)
                        printf ("\nposicao removida");

                    break;
                } else
                {
                    retorno = remover_posicao (l2, posicao);

                    if (retorno == 2)
                        printf ("\nerro: lista nao alocada");
                    if (retorno == 1)
                        printf ("\nerro: lista vazia");
                    if (retorno == 0)
                        printf ("\nposicao removida");

                    break;
                }

            case 7:
                printf ("\ndigite a matricula do aluno: ");
                scanf ("%d", &a.mat);

                op_lista = 0;

                do
                {
                    printf ("\nde qual lista deseja remover o aluno?");
                    printf ("\n1 - lista A, 2 - lista B\n");
                    scanf ("%d", &op_lista);

                    if ((op_lista != 1) && (op_lista != 2))
                        printf ("opcao invalida\n");

                } while ((op_lista != 1) && (op_lista != 2));

                printf ("\nbuscando aluno...");

                if (op_lista == 1)
                {
                    retorno = remover_item (l1, a);

                    if (retorno == 2)
                        printf ("\nerro: lista nao alocada");
                    if (retorno == 1)
                        printf ("\nerro: lista vazia");
                    if (retorno == 0)
                        printf ("\naluno removido");
                    if (retorno == 3)
                        printf ("\naluno nao encontrado");

                    break;
                } else
                {
                    retorno = remover_item (l2, a);

                    if (retorno == 2)
                        printf ("\nerro: lista nao alocada");
                    if (retorno == 1)
                        printf ("\nerro: lista vazia");
                    if (retorno == 0)
                        printf ("\naluno removido");
                    if (retorno == 3)
                        printf ("\naluno nao encontrado");

                    break;
                }

            case 8:
                printf ("\ndigite a matricula do aluno: ");
                scanf ("%d", &chave);

                op_lista = 0;

                do
                {
                    printf ("\nem qual lista deseja buscar o aluno?");
                    printf ("\n1 - lista A, 2 - lista B\n");
                    scanf ("%d", &op_lista);

                    if ((op_lista != 1) && (op_lista != 2))
                        printf ("opcao invalida\n");

                } while ((op_lista != 1) && (op_lista != 2));

                printf ("\nbuscando aluno...");

                if (op_lista == 1)
                {
                    retorno = buscar_itemchave (l1, chave, &a);

                    if (retorno == 2)
                        printf ("\nerro: lista nao alocada");
                    if (retorno == 0)
                    {
                        printf ("\naluno encontrado:");
                        printf ("\nmatricula: %d", a.mat);
                        printf ("\nnome: %s", a.nome);
                        printf ("\nnota: %.2f", a.n1);
                    }
                    if (retorno == 1)
                        printf ("\naluno nao encontrado");

                    break;
                } else
                {
                    retorno = buscar_itemchave (l2, chave, &a);

                    if (retorno == 2)
                        printf ("\nerro: lista nao alocada");
                    if (retorno == 0)
                    {
                        printf ("\naluno encontrado:");
                        printf ("\nmatricula: %d", a.mat);
                        printf ("\nnome: %s", a.nome);
                        printf ("\nnota: %.2f", a.n1);
                    }
                    if (retorno == 1)
                        printf ("\naluno nao encontrado");

                    break;
                }

            case 9:
                printf ("\ndigite a posicao: ");
                scanf ("%d", &posicao);

                op_lista = 0;

                do
                {
                    printf ("\nem qual lista deseja buscar o aluno?");
                    printf ("\n1 - lista A, 2 - lista B\n");
                    scanf ("%d", &op_lista);

                    if ((op_lista != 1) && (op_lista != 2))
                        printf ("opcao invalida\n");

                } while ((op_lista != 1) && (op_lista != 2));

                printf ("\nbuscando posicao...");

                if (op_lista == 1)
                {
                    retorno = buscar_posicao (l1, posicao, &a);

                    if (retorno == 2)
                        printf ("\nerro: lista nao alocada");
                    if (retorno == 0)
                    {
                        printf ("\nposicao encontrada:");
                        printf ("\nmatricula: %d", a.mat);
                        printf ("\nnome: %s", a.nome);
                        printf ("\nnota: %.2f", a.n1);
                    }
                    if (retorno == 1)
                        printf ("\nposicao nao encontrada");

                    break;
                } else
                {
                    retorno = buscar_posicao (l2, posicao, &a);

                    if (retorno == 2)
                        printf ("\nerro: lista nao alocada");
                    if (retorno == 0)
                    {
                        printf ("\nposicao encontrada:");
                        printf ("\nmatricula: %d", a.mat);
                        printf ("\nnome: %s", a.nome);
                        printf ("\nnota: %.2f", a.n1);
                    }
                    if (retorno == 1)
                        printf ("\nposicao nao encontrada");

                    break;
                }

            case 10:
                printf ("\ndigite a matricula do aluno: ");
                scanf ("%d", &chave);

                op_lista = 0;

                do
                {
                    printf ("\nem qual lista deseja buscar o aluno?");
                    printf ("\n1 - lista A, 2 - lista B\n");
                    scanf ("%d", &op_lista);

                    if ((op_lista != 1) && (op_lista != 2))
                        printf ("opcao invalida\n");

                } while ((op_lista != 1) && (op_lista != 2));

                printf ("\nbuscando aluno...");

                if (op_lista == 1)
                {
                    retorno = contem_item (l1, chave);

                    if (retorno == 2)
                        printf ("\nerro: lista nao alocada");
                    if (retorno == 0)
                        printf ("\no aluno esta na lista");
                    if (retorno == 1)
                        printf ("\no aluno nao esta na lista");

                    break;

                } else
                {
                    retorno = contem_item (l1, chave);

                    if (retorno == 2)
                        printf ("\nerro: lista nao alocada");
                    if (retorno == 0)
                        printf ("\no aluno esta na lista");
                    if (retorno == 1)
                        printf ("\no aluno nao esta na lista");

                    break;

                }

            case 11:
                printf ("\nconcatenando listas...");
                concatenada = concatena (l1, l2);

                if (concatenada == NULL)
                    printf ("\nerro: listas nao concatenadas");
                else
                {
                    printf ("\nlistas concatenadas:\n");
                    mostrar (concatenada);
                }
                free (concatenada);

                break;

            case 12:
                op_lista = 0;

                do
                {
                    printf ("\nem qual lista deseja procurar?");
                    printf ("\n1 - lista A, 2 - lista B\n");
                    scanf ("%d", &op_lista);

                    if ((op_lista != 1) && (op_lista != 2))
                        printf ("opcao invalida\n");

                } while ((op_lista != 1) && (op_lista != 2));

                if (op_lista == 1)
                {
                    printf ("\nbuscando aluno...");
                    maior_nota (l1);
                    break;
                } else
                {
                    printf ("\nbuscando aluno...");
                    maior_nota (l2);
                    break;
                }

            case 13:
                op_lista = 0;

                do
                {
                    printf ("\nqual lista deseja limpar?");
                    printf ("\n1 - lista A, 2 - lista B\n");
                    scanf ("%d", &op_lista);

                    if ((op_lista != 1) && (op_lista != 2))
                        printf ("opcao invalida\n");

                } while ((op_lista != 1) && (op_lista != 2));

                if (op_lista == 1)
                {
                    printf ("\nlimpando a lista...");
                    limpar (l1);
                    printf ("\nlista A apagada");
                    break;
                } else
                {
                    printf ("\nlimpando a lista...");
                    limpar (l2);
                    printf ("\nlista B apagada");
                    break;
                }

            case 14:
                op_lista = 0;

                do
                {
                    printf ("\nqual lista deseja mostrar?");
                    printf ("\n1 - lista A, 2 - lista B\n");
                    scanf ("%d", &op_lista);

                    if ((op_lista != 1) && (op_lista != 2))
                        printf ("opcao invalida\n");

                } while ((op_lista != 1) && (op_lista != 2));

                if (op_lista == 1)
                {
                    printf ("\nlista de alunos:\n");
                    mostrar (l1);
                    break;
                } else
                {
                    printf ("\nlista de alunos:\n");
                    mostrar (l2);
                    break;
                }

            default:
                printf ("\nopcao invalida, tente novamente");
                break;
        }
    }

    return 0;
}
