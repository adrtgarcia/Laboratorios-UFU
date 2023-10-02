#include "listadup.h"

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main ( )
{
    lista *l = criar ( );
    aluno a;

    int opcao, retorno;

    while (1)
    {
        printf ("\n\nMENU\n");
        printf ("\n(1) cadastrar aluno");
        printf ("\n(2) remover aluno");
        printf ("\n(3) listar alunos cadastrados");
        printf ("\n(4) mostrar dados do aluno com maior nota");
        printf ("\n(5) remover todos os alunos");
        printf ("\n(6) sair");

        printf ("\n\nopcao escolhida: ");
        scanf ("%d", &opcao);

        if (opcao == 6)
        {
            printf ("\n\nencerrando o programa...");
            free (l);
            break;
        }

        switch (opcao)
        {
            case 1:
                printf ("\n\ndigite o nome do aluno: ");
                setbuf (stdin, NULL);
                fgets (a.nome, 30, stdin);
                a.nome[strcspn(a.nome, "\n")] = '\0';

                printf ("digite a matricula do aluno: ");
                scanf ("%d", &a.mat);

                printf ("digite a nota do aluno: ");
                scanf ("%f", &a.nota);

                retorno = inserir_aluno (l, a);
                if (retorno == 2)
                    printf ("\nerro: lista nao alocada");
                if (retorno == 0)
                    printf ("\naluno cadastrado");

                break;

            case 2:
                printf ("\n\ndigite a matricula do aluno: ");
                scanf ("%d", &a.mat);

                retorno = remover_aluno (l, a.mat);
                if (retorno == 2)
                    printf ("\nerro: lista nao alocada");
                if (retorno == 1)
                    printf ("\nerro: lista vazia");
                if (retorno == 0)
                    printf ("\naluno removido");
                if (retorno == -2)
                    printf ("\naluno nao encontrado");

                break;

            case 3:
                printf ("\n\nLISTA DE ALUNOS CADASTRADOS:\n");
                mostrar (l);

                break;

            case 4:
                printf ("\n\nALUNO COM MAIOR NOTA:\n");

                retorno = maior_nota (l, &a);
                if (retorno == 2)
                    printf ("\nerro: lista nao alocada");
                if (retorno == 1)
                    printf ("\nerro: lista vazia");
                if (retorno == 0)
                {
                    printf ("\nnome: %s", a.nome);
                    printf ("\nmatricula: %d", a.mat);
                    printf ("\nnota: %.2f", a.nota);
                }

                break;

            case 5:
                printf ("\n\nremovendo alunos...");
                limpar (l);
                printf ("\nalunos removidos");

                break;

            default:
                printf ("\n\nopcao invalida, tente novamente");
                break;
        }
    }

    return 0;
}
