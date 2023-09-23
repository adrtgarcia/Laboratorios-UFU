#include "tad_aeroporto.h"

#include <stdio.h>
#include <stdlib.h>

struct no_cidade
{
    cidade info;
    struct no_cidade *prox;
};
typedef struct no_cidade no_cidade;

struct lista_cidade
{
    no_cidade *inicio;
};
typedef struct lista_cidade lista_cidade;

struct no_rota
{
    rota info;
    struct no_rota *prox;
};
typedef struct no_rota no_rota;

struct lista_rota
{
    no_rota *inicio;
};
typedef struct lista_rota lista_rota;

lista_cidade *criar_lc ( )
{
    lista_cidade *lc = (lista_cidade *) malloc (sizeof(lista_cidade));
    lc->inicio = NULL;

    return lc;                              //lista criada
}

lista_rota *criar_lr ( )
{
    lista_rota *lr = (lista_rota *) malloc (sizeof(lista_rota));
    lr->inicio = NULL;

    return lr;                              //lista criada
}

int lr_vazia (lista_rota *lr)
{
    if (lr == NULL)
        return 2;                           //lista não alocada

    if (lr->inicio == NULL)
        return 0;                           //lista vazia

    return 1;                               //lista não vazia
}

int adicionar_cidade (lista_cidade *lc, cidade c)
{
    if (lc == NULL)
        return 2;                           //lista não alocada

    no_cidade *nc = (no_cidade *) malloc (sizeof(no_cidade));
    if (nc == NULL)
        return -2;                          //nó não alocado

    nc->info = c;
    nc->prox = lc->inicio;
    lc->inicio = nc;

    return 0;                               //item inserido
}

int adicionar_rota (lista_rota *lr, rota r)
{
    if (lr == NULL)
        return 2;                           //lista não alocada

    no_rota *nr = (no_rota *) malloc (sizeof(no_rota));
    if (nr == NULL)
        return -2;                          //nó não alocado

    nr->info = r;
    nr->prox = lr->inicio;
    lr->inicio = nr;

    return 0;                               //item inserido
}

int analisar_preco (lista_rota *lr, rota *r_cara, rota *r_barata)
{
    if (lr == NULL)
        return 2;                           //lista não alocada

    if (lr_vazia(lr) == 0)
        return 1;                           //lista vazia

    no_rota *nr = lr->inicio;
    if (nr == NULL)
        return -2;                          //nó não alocado

    float cara, barata;
    cara = nr->info.preco;
    barata = nr->info.preco;

    while (nr != NULL)
    {
        if (nr->info.preco > cara)
            cara = nr->info.preco;
        if (nr->info.preco < barata)
            barata = nr->info.preco;

        nr = nr->prox;
    }

    *r_cara = nr->info;
    *r_barata = nr->info;

    return 0;                               //precos analisados
}

int preco_trecho (lista_rota *lr, rota *r)
{
    if (lr == NULL)
        return 2;                           //lista não alocada

    if (lr_vazia(lr) == 0)
        return 1;                           //lista vazia

    no_rota *nr = lr->inicio;
    if (nr == NULL)
        return -2;                          //nó não alocado

    while (nr != NULL)
    {
        if ((nr->info.origem == r->origem) && (nr->info.destino == r->destino))
        {
            r->preco = nr->info.preco;
            return 0;                   //rota encontrada
        }

        nr = nr->prox;
    }

    return -1;                              //rota não encontrada
}
