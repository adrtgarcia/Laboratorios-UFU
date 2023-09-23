#include "listaenc.h"

#include <stdio.h>
#include <stdlib.h>

struct no
{
    aluno valor;
    struct no *prox;
};
typedef struct no no;

struct lista
{
    no *inicio;
};
typedef struct lista lista;

lista *criar ( )
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

int inserir_inicio (lista *l, aluno it)
{
    if (l == NULL)
        return 2;                           //lista não alocada

    no *n = (no *) malloc (sizeof(no));
    if (n == NULL)
        return -2;                          //nó não alocado

    n->valor = it;
    n->prox = l->inicio;
    l->inicio = n;

    return 0;                               //item inserido
}

int inserir_fim (lista *l, aluno it)
{
    if (l == NULL)
        return 2;                           //lista não alocada

    if (lista_vazia(l) == 0)
        return inserir_inicio (l, it);      //inicia a lista

    no *n_lista = l->inicio;
    while (n_lista->prox != NULL)
        n_lista = n_lista->prox;

    no *n = (no *) malloc (sizeof(no));
    n->valor = it;
    n->prox = n_lista->prox;
    n_lista->prox = n;

    return 0;                               //item inserido
}

int inserir_posicao (lista *l, aluno it, int posicao)
{
    if (l == NULL)
        return 2;                           //lista não alocada

    if (posicao < 0)
        return 3;                           //posicao invalida

    if ((lista_vazia(l) == 0) || (posicao == 0))
        return inserir_inicio (l, it);      //lista criada

    no *n_lista = l->inicio;
    int p = 1;

    while ((n_lista->prox != NULL) && (p != posicao))
    {
        p++;
        n_lista = n_lista->prox;
    }

    no *n = (no *) malloc (sizeof(no));
    n->valor = it;
    n->prox = n_lista->prox;
    n_lista->prox = n;

    return 0;                               //item inserido
}

int remover_inicio (lista *l)
{
    if (l == NULL)
        return 2;                           //lista não alocada

    if (lista_vazia(l) == 0)
        return 1;                           //lista vazia

    no *n_lista = l->inicio;
    l->inicio = n_lista->prox;

    free(n_lista);
    return 0;                               //item removido
}

int remover_fim (lista *l)
{
    if (l == NULL)
        return 2;                           //lista não alocada

    if (lista_vazia(l) == 0)
        return 1;                           //lista vazia

    no *auxiliar = NULL;
    no *n_lista = l->inicio;

    while (n_lista->prox != NULL)
    {
        auxiliar = n_lista;
        n_lista = n_lista->prox;
    }

    if (auxiliar == NULL)
        l->inicio = NULL;
    else auxiliar->prox = NULL;

    free(n_lista);
    return 0;                               //item removido
}

int remover_posicao (lista *l, int posicao)
{
    if (l == NULL)
        return 2;                           //lista não alocada

    if (lista_vazia(l) == 0)
        return 1;                           //lista vazia

    if (posicao == 0)
        return remover_inicio (l);          //posicao removida

    no *n_lista = l->inicio;
    int p = 1;

    while ((n_lista->prox != NULL) && (p != posicao))
    {
        p++;
        n_lista = n_lista->prox;
    }

    free (n_lista);
    return 0;                               //posicao removida
}

int remover_item (lista *l, aluno it)
{
    if (l == NULL)
        return 2;                           //lista não alocada

    if (lista_vazia(l) == 0)
        return 1;                           //lista vazia

    no *n_lista = l->inicio;
    while (n_lista != NULL)
    {
        if (n_lista->valor.mat == it.mat)
        {
            free (n_lista);
            return 0;                       //item encontrado
        }

        n_lista = n_lista->prox;
    }

    return 3;                               //item não encontrado
}

int buscar_itemchave (lista *l, int chave, aluno *retorno)
{
    if (l == NULL)
        return 2;                           //lista não alocada

    no *n_lista = l->inicio;
    while (n_lista != NULL)
    {
        if (n_lista->valor.mat == chave)
        {
            *retorno = n_lista->valor;
            return 0;                       //item encontrado
        }

        n_lista = n_lista->prox;
    }

    return 1;                               //item não encontrado
}

int buscar_posicao(lista *l, int posicao, aluno *retorno)
{
    if (l == NULL)
        return 2;                           //lista não alocada

    no *n_lista = l->inicio;
    int p = 0;

    while ((n_lista->prox != NULL))
    {
        if (p == posicao)
        {
            *retorno = n_lista->valor;
            return 0;                       //posicao encontrada
        }

        p++;
        n_lista = n_lista->prox;
    }

    return 1;                               //posicao não encontrada
}

void limpar (lista *l)
{
    while (lista_vazia(l) != 0)
        remover_inicio(l);
}

void mostrar (lista *l)
{
    if (l != NULL)
    {
        printf ("[");
        no *n_lista = l->inicio;

        while(n_lista != NULL)
        {
            printf (" {%d, ", n_lista->valor.mat);
            printf ("%s, ", n_lista->valor.nome);
            printf ("%.2f} ", n_lista->valor.n1);

            n_lista = n_lista->prox;
        }

        printf ("]");
    }
}
