#include "fila.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main ( )
{
    fila *f = criar ( );
    paciente p;

    int opcao, retorno;

    while (1)
    {
        printf ("\n\nMENU\n");
        printf ("\n(1) inserir paciente");
        printf ("\n(2) remover paciente");
        printf ("\n(3) mostrar fila");
        printf ("\n(4) sair");

        printf ("\n\nopcao escolhida: ");
        scanf ("%d", &opcao);

        if (opcao == 4)
        {
            printf ("\nencerrando o programa...");
            break;
        }

        switch (opcao)
        {
            case 1:
                printf ("\ndigite o nome do paciente: ");
                setbuf (stdin, NULL);
                fgets (p.nome, 50, stdin);
                p.nome[strcspn(p.nome, "\n")] = '\0';

                retorno = inserir (f, p);
                if (retorno == -2)
                    printf ("\nerro: fila nao alocada");
                if (retorno == -1)
                    printf ("\nerro: fila cheia");
                if (retorno == 0)
                    printf ("\npaciente inserido na fila");

                break;

            case 2:
                printf ("\nproximo paciente:");
                retorno = remover (f, &p);
                if (retorno == -2)
                    printf ("\nerro: fila nao alocada");
                if (retorno == -1)
                    printf ("\nerro: fila vazia");
                if (retorno == 0)
                {
                    printf ("\nnome: %s", p.nome);
                    printf ("\nsenha: %d", p.senha);
                }

                break;

            case 3:
                printf ("\nlista de espera:\n");
                mostrar (f);

                break;

            default:
                printf ("\nopcao invalida, tente novamente...");
        }
    }

    limpar (f);

    return 0;
}
