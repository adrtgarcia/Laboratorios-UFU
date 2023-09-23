#include "listaenc.h"

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main ( )
{
    lista *l;
    aluno a;
    int opcao, retorno, posicao, chave;

    l = criar ( );

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
        printf ("\n10 - limpar a lista");
        printf ("\n11 - mostrar a lista");
        printf ("\n12 - encerrar o programa");

        printf ("\n\nopcao escolhida: ");
        scanf ("%d", &opcao);

        if (opcao == 12)
        {
            printf ("\n\nencerrando o programa...");
            free (l);
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

                retorno = inserir_inicio (l, a);
                if (retorno == 2)
                    printf ("\nerro: lista nao alocada");
                if (retorno == -2)
                    printf ("\nerro: no nao alocado");
                if (retorno == 0)
                    printf ("\naluno inserido");

                break;

            case 2:
                printf ("\ndigite a matricula do aluno: ");
                scanf ("%d", &a.mat);

                setbuf (stdin, NULL);
                printf ("\ndigite o nome do aluno: ");
                fgets (a.nome, 30, stdin);
                a.nome[strcspn("\n", a.nome)] = '\0';

                printf ("\ndigite a nota do aluno: ");
                scanf ("%f", &a.n1);

                retorno = inserir_fim (l, a);
                if (retorno == 2)
                    printf ("\nerro: lista nao alocada");
                if (retorno == -2)
                    printf ("\nerro: no nao alocado");
                if (retorno == 0)
                    printf ("\naluno inserido");

                break;

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

                retorno = inserir_posicao (l, a, posicao);
                if (retorno == 2)
                    printf ("\nerro: lista nao alocada");
                if (retorno == 3)
                    printf ("\nerro: posicao invalida");
                if (retorno == -2)
                    printf ("\nerro: no nao alocado");
                if (retorno == 0)
                    printf ("\naluno inserido");

                break;

            case 4:
                printf ("\nremovendo aluno...");
                retorno = remover_inicio (l);

                if (retorno == 2)
                    printf ("\nerro: lista nao alocada");
                if (retorno == 1)
                    printf ("\nerro: lista vazia");
                if (retorno == 0)
                    printf ("\naluno removido");

                break;

            case 5:
                printf ("\nremovendo aluno...");
                retorno = remover_fim (l);

                if (retorno == 2)
                    printf ("\nerro: lista nao alocada");
                if (retorno == 1)
                    printf ("\nerro: lista vazia");
                if (retorno == 0)
                    printf ("\naluno removido");

                break;

            case 6:
                printf ("\ndigite a posicao: ");
                scanf ("%d", &posicao);

                printf ("\nbuscando posicao...");
                retorno = remover_posicao (l, posicao);

                if (retorno == 2)
                    printf ("\nerro: lista nao alocada");
                if (retorno == 1)
                    printf ("\nerro: lista vazia");
                if (retorno == 0)
                    printf ("\nposicao removida");

                break;

            case 7:
                printf ("\ndigite a matricula do aluno: ");
                scanf ("%d", &a.mat);

                printf ("\nbuscando aluno...");
                retorno = remover_item (l, a);

                if (retorno == 2)
                    printf ("\nerro: lista nao alocada");
                if (retorno == 1)
                    printf ("\nerro: lista vazia");
                if (retorno == 0)
                    printf ("\naluno removido");
                if (retorno == 3)
                    printf ("\naluno nao encontrado");

                break;

            case 8:
                printf ("\ndigite a matricula do aluno: ");
                scanf ("%d", &chave);

                printf ("\nbuscando aluno...");
                retorno = buscar_itemchave (l, chave, &a);

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

            case 9:
                printf ("\ndigite a posicao: ");
                scanf ("%d", &posicao);

                printf ("\nbuscando posicao...");
                retorno = buscar_posicao (l, posicao, &a);

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

            case 10:
                printf ("\nlimpando a lista...");
                limpar (l);
                printf ("\nlista apagada");
                break;

            case 11:
                printf ("\nlista de alunos:\n");
                mostrar (l);
                break;

            default:
                printf ("\nopcao invalida, tente novamente");
                break;
        }
    }

    return 0;
}
