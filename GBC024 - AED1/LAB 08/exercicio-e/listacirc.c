#include "listacirc.h"
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
    no *fim;
};
typedef struct lista lista;

lista *criar ( )
{
    lista *l = (lista *) malloc (sizeof(lista));
    l->fim = NULL;
    return l;
}

void limpar (lista *l)
{
    while (lista_vazia(l) != 0)
        remover_inicio(l);
    free(l);
    l = NULL;
}

lista *intersecao (lista *la, lista *lb)
{
    lista *l = criar ( );
    no *nola = la->fim->prox;
    no *nolb = lb->fim->prox;

    while (nola != la->fim)
    {
        while (nolb != lb->fim)
        {
            if ((nola->valor.mat == nolb->valor.mat) && (nola->valor.nome == nolb->valor.nome) && (nola->valor.n1 == nolb->valor.n1))
            {
                inserir_inicio (l, nola->valor);
                break;
            }

            nolb = nolb->prox;
        }

        nola = nola->prox;
    }

    return l;
}

int inserir_inicio (lista *l, aluno it)
{
    if (l == NULL) return 2;
    no *n = (no *) malloc (sizeof(no));

    n->valor = it;

    if (lista_vazia(l) == 0)
    {
        l->fim = n;
        n->prox = n;
    } else {
        n->prox = l->fim->prox;
        l->fim->prox = n;
    }

    return 0;
}

int inserir_fim (lista *l, aluno it)
{
    if (l == NULL) return 2;

    no *n = (no *) malloc (sizeof(no));
    n->valor = it;

    int flag = conta_ocorrencias (l, it);
    if (flag == 0)
    {
        if (lista_vazia(l) == 0)
        {
            l->fim = n;
            n->prox = n;
        } else {
            n->prox = l->fim->prox;
            l->fim->prox = n;
        }

        return 0;

    } else return 1;
}

int inserir_posicao (lista *l, aluno it, int pos)
{
    if (l == NULL) return 2;

    int p = 1, tam = tamanho(l);
    no *n = (no *) malloc (sizeof(no));

    n->valor = it;

    no *nolista = l->fim->prox;
    no *auxiliar = l->fim->prox;

    if (lista_vazia(l) == 0)
    {
        l->fim = n;
        n->prox = n;
        return 0;
    }

    if (pos == 1)
    {
        inserir_inicio(l, it);
        return 0;
    }

    if (pos == tam)
    {
        inserir_fim(l, it);
        return 0;
    }

    while ((nolista != l->fim) || (p != pos))
    {
        auxiliar = nolista;
        nolista = nolista->prox;
        p++;
    }

    n->prox = nolista;
    auxiliar->prox = n;
    return 0;
}

int remover_inicio (lista *l)
{
    if (l == NULL) return 2;
    if (lista_vazia(l) == 0) return 1;

    if (l->fim->prox == l->fim)
    {
        free (l->fim);
        l->fim = NULL;
        return 0;
    }

    no *n = l->fim;
    no *auxiliar = l->fim->prox;

    free (n);
    l->fim = auxiliar;

    return 0;
}

int remover_fim (lista *l)
{
    if (l == NULL) return 2;
    if (lista_vazia(l) == 0) return 1;

    if (l->fim->prox == l->fim)
    {
        free(l->fim);
        l->fim = NULL;
        return 0;
    }

    no *proximo = l->fim->prox;
    no *n = proximo->prox;
    l->fim->prox = n;

    free (proximo);
    return 0;
}

int remover_posicao (lista *l, int pos)
{
    if (l == NULL) return 2;
    if (lista_vazia(l) == 0) return 1;

    int tam = tamanho(l);

    if (pos == 1)
    {
        remover_inicio(l);
        return 0;
    }

    if (pos == tam)
    {
        remover_fim(l);
        return 0;
    }

    no *n = l->fim;
    no *auxiliar = l->fim->prox;
    int p = 1;

    while (p < pos)
    {
        auxiliar = n;
        n = n->prox;
        p++;
    }

    auxiliar->prox = n->prox;
    free (n);

    return 0;
}

int remover_item (lista *l, int it)
{
    if (l == NULL) return 2;
    if (lista_vazia(l) == 0) return 1;

    int p = 1, flag = 0;
    no *n = l->fim->prox;

    while (n != l->fim)
    {
        if (n->valor.mat == it)
        {
            remover_posicao(l, p);
            flag++;
        }

        n = n->prox;
        p++;
    }

    if (flag == 0) return -1;
    else return 0;
}

int remover_1oitem(lista *l, int it)
{
    if (l == NULL) return 2;
    if (lista_vazia(l) == 0) return 1;

    int p = 1;
    no *n = l->fim->prox;

    while (n != l->fim)
    {
        if (n->valor.mat == it)
        {
            remover_posicao(l, p);
            return 0;
        }

        n = n->prox;
        p++;
    }

    return -1;
}

int remover_centro (lista *l)
{
    if (l == NULL) return 2;
    if (lista_vazia(l) == 0) return 1;

    int tam, meio;
    tam = tamanho(l);
    meio = tam/2;

    if (tam == 1)
    {
        remover_inicio(l);
        return 0;
    }

    remover_posicao (l, meio);
    return 0;
}

int buscar_itemchave (lista *l, int chave, aluno *retorno)
{
    if (l == NULL) return 2;
    if (lista_vazia(l) == 0) return 1;

    no *n = l->fim->prox;

    while (n != l->fim)
    {
        if (n->valor.mat == chave)
        {
            *retorno = n->valor;
            return 0;
        }

        n = n->prox;
    }

    return -1;
}

int buscar_posicao (lista *l, int posicao, int *retorno)
{
    if (l == NULL) return 2;
    if (lista_vazia(l) == 0) return 1;

    no *n = l->fim->prox;
    int p = 1;

    while (n != l->fim)
    {
        if (p == posicao)
        {
            *retorno = n->valor.mat;
            return 0;
        }

        n = n->prox;
        p++;
    }

    return -1;
}

int lista_vazia (lista *l)
{
    if (l == NULL) return 2;
    if (l->fim == NULL) return 0;
    else return 1;
}

int lista_cheia (lista *l)
{
    return 1;
}

int conta_ocorrencias (lista *l, aluno it)
{
    if (l == NULL) return 2;
    if (lista_vazia(l) == 0) return 1;

    int cont = 0;
    no *nolista = l->fim->prox;

    while (nolista != l->fim)
    {
        if ((nolista->valor.mat == it.mat) && (nolista->valor.nome == it.nome) && (nolista->valor.n1 == it.n1))
            cont++;

        nolista = nolista->prox;
    }

    return cont;
}

int tamanho (lista *l)
{
    if (l == NULL) return -1;
    if (lista_vazia(l) == 0) return 0;

    no *nolista = l->fim;
    int cont = 0;

    do
    {
        cont++;
        nolista = nolista->prox;
    } while (nolista != l->fim);

    return cont;
}

void mostrar (lista *l)
{
    if (l != NULL)
    {
        printf ("[");

        if (lista_vazia(l) != 0)
        {
            no *nolista = l->fim;

            do
            {
                printf (" {%d, %s, %.2f} ", nolista->valor.mat, nolista->valor.nome, nolista->valor.n1);
                nolista = nolista->prox;
            } while (nolista != l->fim);
        }

        printf ("]\n");
    }
}
