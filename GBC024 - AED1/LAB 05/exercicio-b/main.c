#include "tad_conjuntos.h"

#include <stdio.h>
#include <stdlib.h>

struct conjunto
{
    int *vet;
    int tamanho;
};
typedef struct conjunto conjunto;

int main ( )
{
    conjunto *a, *b;
    conjunto *u, *i, *d;

    int opcao;
    int aux;

    printf ("criando o conjunto A");

    a = criacao ( );
    membro (a);

    do
    {
        printf ("\ngostaria de inserir algum elemento?");
        printf ("\n0 - nao, 1 - sim\n");
        scanf ("%d", &opcao);

        if ((opcao != 0) && (opcao != 1))
        {
            printf ("\nopcao invalida");
        }

        if (opcao == 1)
        {
            inserir (a);
            break;
        } else break;

    } while ((opcao != 0) && (opcao != 1));

    do
    {
        printf ("\ngostaria de remover algum elemento?");
        printf ("\n0 - nao, 1 - sim\n");
        scanf ("%d", &opcao);

        if ((opcao != 0) && (opcao != 1))
        {
            printf ("\nopcao invalida");
        }

        if (opcao == 1)
        {
            remover (a);
            break;
        } else break;

    } while ((opcao != 0) && (opcao != 1));

    printf ("criando o conjunto B");

    b = criacao ( );
    membro (b);

    do
    {
        printf ("\ngostaria de inserir algum elemento?");
        printf ("\n0 - nao, 1 - sim\n");
        scanf ("%d", &opcao);

        if ((opcao != 0) && (opcao != 1))
        {
            printf ("\nopcao invalida");
        }

        if (opcao == 1)
        {
            inserir (b);
            break;
        } else break;

    } while ((opcao != 0) && (opcao != 1));

    do
    {
        printf ("\ngostaria de remover algum elemento?");
        printf ("\n0 - nao, 1 - sim\n");
        scanf ("%d", &opcao);

        if ((opcao != 0) && (opcao != 1))
        {
            printf ("\nopcao invalida");
        }

        if (opcao == 1)
        {
            remover (b);
            break;
        } else break;

    } while ((opcao != 0) && (opcao != 1));

    u = uniao (a, b);
    printf ("\n\nconjunto uniao:\n[");
    for (aux = 0; aux < u->tamanho; aux++)
    {
        printf (" %d ", u->vet[aux]);
    }
    printf ("]\n");

    i = interseccao (a, b);
    printf ("\n\nconjunto interseccao:\n[");
    for (aux = 0; aux < i->tamanho; aux++)
    {
        printf (" %d ", i->vet[aux]);
    }
    printf ("]\n");

    d = diferenca (a, b);
    printf ("\n\nconjunto diferenca:\n[");
    for (aux = 0; aux < d->tamanho; aux++)
    {
        printf (" %d ", d->vet[aux]);
    }
    printf ("]\n");

    free(a);
    free(b);
    free(u);
    free(i);
    free(d);

    return 0;
}
