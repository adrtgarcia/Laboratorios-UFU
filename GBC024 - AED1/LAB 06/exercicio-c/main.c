#include "lista.h"

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main ( )
{
    lista *l, *r;
    aluno a;

    int MAX, posicao, matricula;
    int op, aux;

    printf ("digite o tamanho maximo da lista: ");
    scanf ("%d", &MAX);

    l = criar (MAX);

    while (1)
    {
        printf ("\nMENU\n");
        printf ("\n 1) inserir aluno no inicio da lista");
        printf ("\n 2) inserir aluno no fim da lista");
        printf ("\n 3) inserir aluno em uma posicao especifica");
        printf ("\n 4) remover aluno do inicio da lista");
        printf ("\n 5) remover aluno do fim da lista");
        printf ("\n 6) remover aluno em uma posicao especifica");
        printf ("\n 7) remover aluno especifico");
        printf ("\n 8) buscar aluno na lista por matricula");
        printf ("\n 9) buscar aluno na lista por posicao");
        printf ("\n10) mostrar conteudo da lista");
        printf ("\n11) verificar o tamanho da lista");
        printf ("\n12) conferir existencia de item na lista");
        printf ("\n13) conferir ocorrencia de um item na lista");
        printf ("\n14) obter lista na ordem reversa");
        printf ("\n15) encerrar o programa");

        printf ("\n\nopcao escolhida: ");
        scanf ("%d", &op);

        if (op == 15)
        {
            printf ("\n\nencerrando...");
            free(l);
            break;
        }

        switch (op)
        {
            case 1:
                printf ("\n\ndigite a matricula: ");
                scanf ("%d", &a.mat);

                setbuf (stdin, NULL);
                printf ("digite o nome: ");
                fgets (a.nome, 30, stdin);
                a.nome[strcspn(a.nome, "\n")] = '\0';

                printf ("digite a nota: ");
                scanf ("%f", &a.n1);

                aux = inseririnicio (l, a);
                if (aux == 1)
                {
                    printf ("\n\nerro: lista cheia\n");
                } else if (aux == 2)
                {
                    printf ("\n\nerro: lista nao alocada\n");
                } else printf ("\n\no aluno foi inserido\n");

                break;

            case 2:
                printf ("\n\ndigite a matricula: ");
                scanf ("%d", &a.mat);

                setbuf (stdin, NULL);
                printf ("digite o nome: ");
                fgets (a.nome, 30, stdin);
                a.nome[strcspn(a.nome, "\n")] = '\0';

                printf ("digite a nota: ");
                scanf ("%f", &a.n1);

                aux = inserirfim (l, a);
                if (aux == 1)
                {
                    printf ("\n\nerro: lista cheia\n");
                } else if (aux == 2)
                {
                    printf ("\n\nerro: lista nao alocada\n");
                } else printf ("\n\no aluno foi inserido\n");

                break;

            case 3:
                printf ("\n\ndigite a matricula: ");
                scanf ("%d", &a.mat);

                setbuf (stdin, NULL);
                printf ("digite o nome: ");
                fgets (a.nome, 30, stdin);
                a.nome[strcspn(a.nome, "\n")] = '\0';

                printf ("digite a nota: ");
                scanf ("%f", &a.n1);

                printf ("digite a posicao: ");
                scanf ("%d", &posicao);

                aux = inserirposicao (l, a, posicao);
                if (aux == -1)
                {
                    printf ("\n\nerro: posicao invalida\n");
                } else if (aux == 1)
                {
                    printf ("\n\nerro: lista cheia\n");
                } else if (aux == 2)
                {
                    printf ("\n\nerro: lista nao alocada\n");
                } else printf ("\n\no aluno foi inserido\n");

                break;

            case 4:
                aux = removerinicio (l);
                if (aux == 1)
                {
                    printf ("\n\nerro: lista vazia\n");
                } else if (aux == 2)
                {
                    printf ("\n\nerro: lista nao alocada\n");
                } else printf ("\n\no aluno foi removido\n");

                break;

            case 5:
                aux = removerfim (l);
                if (aux == 1)
                {
                    printf ("\n\nerro: lista vazia\n");
                } else if (aux == 2)
                {
                    printf ("\n\nerro: lista nao alocada\n");
                } else printf ("\n\no aluno foi removido\n");

                break;

            case 6:
                printf ("\n\ndigite a posicao: ");
                scanf ("%d", &posicao);

                aux = removerposicao (l, posicao);
                if (aux == -1)
                {
                    printf ("\n\nerro: posicao invalida\n");
                } else if (aux == 1)
                {
                    printf ("\n\nerro: lista vazia\n");
                } else if (aux == 2)
                {
                    printf ("\n\nerro: lista nao alocada\n");
                } else printf ("\n\no aluno foi removido\n");

                break;

            case 7:
                printf ("\n\ndigite a matricula do aluno: ");
                scanf ("%d", &a.mat);

                aux = removeritem (l, a);
                if (aux == -1)
                {
                    printf ("\n\naluno nao acontrado\n");
                } else if (aux == 1)
                {
                    printf ("\n\nerro: lista vazia\n");
                } else if (aux == 2)
                {
                    printf ("\n\nerro: lista nao alocada\n");
                } else printf ("\n\no aluno foi removido\n");

                break;

            case 8:
                printf ("\n\ndigite a matricula do aluno: ");
                scanf ("%d", &matricula);

                aux = buscaritemchave (l, matricula, &a);
                if (aux == -1)
                {
                    printf ("\n\naluno nao acontrado\n");
                } else if (aux == 1)
                {
                    printf ("\n\nerro: lista vazia\n");
                } else if (aux == 2)
                {
                    printf ("\n\nerro: lista nao alocada\n");
                } else
                {
                    printf ("\n\no aluno foi encontrado");
                    printf ("\nmatricula: %d", a.mat);
                    printf ("\nnome: %s", a.nome);
                    printf ("\nnota: %.2f\n", a.n1);
                }

                break;

            case 9:
                printf ("\n\ndigite a posicao: ");
                scanf ("%d", &posicao);

                aux = buscarposicao (l, posicao, &a);
                if (aux == -1)
                {
                    printf ("\n\nerro: posicao invalida\n");
                } else if (aux == -2)
                {
                    printf ("\n\naluno nao encontrado\n");
                } else if (aux == 1)
                {
                    printf ("\n\nerro: lista vazia\n");
                } else if (aux == 2)
                {
                    printf ("\n\nerro: lista nao alocada\n");
                } else
                {
                    printf ("\n\no aluno foi encontrado");
                    printf ("\nmatricula: %d", a.mat);
                    printf ("\nnome: %s", a.nome);
                    printf ("\nnota: %.2f\n", a.n1);
                }

                break;

            case 10:
                printf ("\n\nlista:");
                mostrar (l);
                break;

            case 11:
                aux = tamanho (l);
                printf ("\n\ntamanho da lista: %d\n", aux);
                break;

            case 12:
                printf ("\n\ndigite a matricula do aluno: ");
                scanf ("%d", &a.mat);

                aux = contemitem (l, &a);
                if (aux == -2)
                {
                    printf ("\n\nerro: lista vazia\n");
                } else if (aux == 2)
                {
                    printf ("\n\nerro: lista nao alocada\n");
                } else if (aux == 1)
                {
                    printf ("\n\naluno nao encontrado\n");
                } else
                {
                    printf ("\n\no aluno foi encontrado");
                    printf ("\nmatricula: %d", a.mat);
                    printf ("\nnome: %s", a.nome);
                    printf ("\nnota: %.2f\n", a.n1);
                }

                break;

            case 13:
                printf ("\n\ndigite a matricula do aluno: ");
                scanf ("%d", &a.mat);

                aux = contaitem (l, a);
                if (aux == 1)
                {
                    printf ("\n\nerro: lista vazia\n");
                } else if (aux == 2)
                {
                    printf ("\n\nerro: lista nao alocada\n");
                } else
                {
                    printf ("\n\no aluno aparece %dx na lista\n", aux);
                }

                break;

            case 14:
                printf ("\n\nlista na ordem reversa:\n");
                r = reversa (l);
                mostrar(r);
                free(r);

                break;

            default:
                printf ("\n\nopcao invalida\n");
        }
    }

    return 0;
}
