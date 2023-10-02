#include "listadup.h"

#include <stdio.h>
#include <stdlib.h>

struct no
{
    aluno info;
    struct no *ant;
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
    else
        return 1;                           //lista não vazia
}

int inserir_aluno (lista *l, aluno a)
{
    if (l == NULL) return 2;                //lista não alocada

    no *n = (no *) malloc (sizeof(no));
    n->info = a;
    n->prox = NULL;
    n->ant = NULL;

    //lista vazia
    if (l->inicio == NULL)
    {
        l->inicio = n;
        return 0;                           //aluno inserido
    }

    no *nolista = l->inicio;

    //inicio da lista
    if (a.mat < nolista->info.mat)
    {
        n->prox = nolista;
        nolista->ant = n;
        l->inicio = n;
        return 0;                           //aluno inserido
    }

    //meio da lista
    while (nolista->prox != NULL)
    {
        if (a.mat > nolista->prox->info.mat)
        {
            nolista = nolista->prox;
        } else {
            n->prox = nolista->prox;
            n->ant = nolista;
            nolista->prox->ant = n;
            nolista->prox = n;
            return 0;                       //aluno inserido
        }
    }

    //final da lista
    nolista->prox = n;
    n->ant = nolista;
    return 0;                               //aluno inserido
}

int remover_aluno (lista *l, int mat)
{
    if (l == NULL) return 2;                //lista não alocada
    if (lista_vazia (l) == 0) return 1;     //lista vazia

    no *nolista = l->inicio;

    while (nolista->prox != NULL)
    {
        if (mat == nolista->info.mat)
        {
            nolista->prox->ant = nolista->ant;
            nolista->ant->prox = nolista->prox;

            free(nolista);
            return 0;                       //aluno removido
        }

        nolista = nolista->prox;
    }

    return -2;                              //aluno não encontrado
}

void mostrar (lista *l)
{
    if (l != NULL)
    {
        no *nolista = l->inicio;

        while (nolista != NULL)
        {
            printf("\nnome: %s", nolista->info.nome);
            printf("\nmatricula: %d", nolista->info.mat);
            printf("\nnota: %.2f\n", nolista->info.nota);

            nolista = nolista->prox;
        }
    }
}

int maior_nota (lista *l, aluno *retorno)
{
    if (l == NULL) return 2;                //lista não alocada
    if (lista_vazia (l) == 0) return 1;     //lista vazia

    no *nolista = l->inicio;
    aluno maior = nolista->info;

    while (nolista != NULL)
    {
        if (nolista->info.nota > maior.nota)
            maior = nolista->info;

        nolista = nolista->prox;
    }

    *retorno = maior;
    return 0;                               //aluno encontrado
}

void limpar (lista *l)
{
    while (lista_vazia (l) != 0)
    {
        no *nolista = l->inicio;
        l->inicio = nolista->prox;

        if (l->inicio != NULL)
            l->inicio->ant = NULL;
        free(nolista);
    }
}
