#include "lista.h"

#include <stdio.h>
#include <stdlib.h>

struct no
{
    int valor;
    struct no *prox;
};
typedef struct no no;

struct lista
{
    no *inicio;
};
typedef struct lista lista;

lista *criar_lista ( )
{
    lista *l = (lista *) malloc (sizeof(lista));
    l->inicio = NULL;

    return l;                               //lista criada
}

int lista_vazia (lista *l)
{
    if (l == NULL)
        return 2;                           //lista não alocada

    if (l->inicio == NULL)
        return 0;                           //lista vazia

    return 1;                               //lista não vazia
}

int inserir_inicio (lista *l, int i)
{
    if (l == NULL)
        return 2;                           //lista não alocada

    no *n = (no *) malloc (sizeof(no));
    if (n == NULL)
        return -2;                          //nó não alocado

    n->valor = i;
    n->prox = l->inicio;
    l->inicio = n;

    return 0;                               //item inserido
}

int inserir_fim (lista *l, int i)
{
    if (l == NULL)
        return 2;                           //lista não alocada

    if (lista_vazia(l) == 0)
        return inserir_inicio (l, i);      //inicia a lista

    no *n_lista = l->inicio;
    while (n_lista->prox != NULL)
        n_lista = n_lista->prox;

    no *n = (no *) malloc (sizeof(no));
    n->valor = i;
    n->prox = n_lista->prox;
    n_lista->prox = n;

    return 0;                               //item inserido
}

int remover (lista *l)
{
    if (l == NULL)
        return 2;                           //lista não alocada

    no *n_lista = l->inicio;
    l->inicio = n_lista->prox;

    free (n_lista);
    return 0;                               //item removido
}

void limpar_lista (lista *l)
{
    if (l != NULL)
    {
        while (lista_vazia(l) != 0)
            remover (l);

    }
}

void mostrar_lista (lista *l)
{
    if (l != NULL)
    {
        printf ("[");
        no *n_lista = l->inicio;

        while(n_lista != NULL)
        {
            printf (" %d ", n_lista->valor);
            n_lista = n_lista->prox;
        }

        printf ("]");
    }
}
