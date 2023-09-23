#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct clientes
{
    char cpf[20];
    char est_civil[20];
    int num_filhos;
    char **filhos;
};
typedef struct clientes clientes;

int main ( )
{
    clientes *c;
    int n, op, i, j;

    printf ("digite o numero de clientes: ");
    scanf ("%d", &n);

    c = (clientes *) calloc (n, (sizeof(clientes)));
    if (c == NULL)
    {
        printf ("erro na alocacao de memoria");
        return 0;
    }

    while (1)
    {
        printf ("\nescolha uma das opcoes:");
        printf ("\n(1) inserir cliente no vetor");
        printf ("\n(2) remover cliente do vetor");
        printf ("\n(3) mostrar os CPFs dos clientes");
        printf ("\n(4) encerrar o programa");

        do
        {
            printf ("\n\nopcao escolhida: ");
            scanf ("%d", &op);

            if ((op < 1) || (op > 4))
            {
                printf ("\nopcao invalida");
            }
        } while ((op < 1) || (op > 4));

        if (op == 1)
        {
            do
            {
                printf ("\ndigite a posicao desejada do vetor: ");
                scanf ("%d", &i);

                if ((i < 0) || (i >= n))
                {
                    printf ("posicao invalida, escolha novamente\n");
                }
            } while ((i < 0) || (i >= n));

            printf ("\ndigite o CPF do cliente (formato XXX.XXX.XXX-XX): ");
            setbuf (stdin, NULL);
            fgets (c[i].cpf, 20, stdin);
            c[i].cpf[strcspn(c[i].cpf, "\n")] = '\0';

            printf ("\ndigite o estado civil do cliente: ");
            fgets (c[i].est_civil, 20, stdin);
            c[i].est_civil[strcspn(c[i].est_civil, "\n")] = '\0';

            printf ("\ndigite o numero de filhos do cliente: ");
            scanf ("%d", &c[i].num_filhos);

            if (c[i].num_filhos != 0)
            {
                c[i].filhos = (char **) calloc (c[i].num_filhos, (sizeof(char *)));
                for (j = 0; j < c[i].num_filhos; j++)
                {
                    c[i].filhos[j] = (char *) calloc (100, (sizeof(char)));
                }

                if (c[i].filhos == NULL)
                {
                    printf ("\nerro na alocacao de memoria");
                    return 0;
                }

                printf ("\ndigite o nome do(s) filho(s) do cliente: ");
                for (j = 0; j < c[i].num_filhos; j++)
                {
                    setbuf (stdin, NULL);
                    fgets (c[i].filhos[j], 100, stdin);
                    c[i].filhos[j][strcspn(c[i].filhos[j], "\n")] = '\0';
                }
            }
        } else if (op == 2)
        {
            do
            {
                printf ("\ndigite a posicao desejada do vetor: ");
                scanf ("%d", &i);

                if ((i < 0) || (i >= n))
                {
                    printf ("posicao invalida, escolha novamente\n");
                }
            } while ((i < 0) || (i >= n));

            free(c[i].filhos);
            n--;

            for (j = i; j < n; j++)
            {
                c[j] = c[(j + 1)];
            }

            c = (clientes *) realloc (c, n * (sizeof(clientes)));
            if (c == NULL)
            {
                printf ("\nerro na alocacao de memoria");
                return 0;
            }

        } else if (op == 3)
        {
            printf ("\nCPFs ja cadastrados:\n");
            for (i = 0; i < n; i++)
            {
                printf ("\ncliente %d: %s", i, c[i].cpf);
            }
            printf ("\n");
        } else if (op == 4) break;
    }

    for (i = 0; i < n; i++)
    {
        free(c[i].filhos);
    }

    free(c);

    return 0;
}
