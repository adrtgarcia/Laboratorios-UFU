#include "lista.h"

#include <stdio.h>
#include <stdlib.h>

struct lista
{
    int total;
    aluno valores[MAX];
};
typedef struct lista lista;

lista *criar ( )
{
    lista *l = (lista *) malloc (sizeof(lista));
    if (l != NULL) l->total = 0;
    return l;
}

void limpar (lista *l)
{
    if (l != NULL) l->total = 0;
}

int inseririnicio (lista *l, aluno it)
{
    int i;

    if (l == NULL) return 2;
    if (listacheia(l) == 0) return 1;

    for (i = l->total; i > 0; i--)
    {
        l->valores[i] = l->valores[i + 1];
    }

    l->valores[0] = it;
    l->total++;

    return 0;
}

int inserirfim (lista *l, aluno it)
{
    if (l == NULL) return 2;
    if (listacheia(l) == 0) return 1;

    l->valores[l->total] = it;
    l->total++;

    return 0;
}

int inserirposicao (lista *l, aluno it, int pos)
{
    int i;

    if (l == NULL) return 2;
    if (listacheia(l) == 0) return 1;
    if ((pos < 0) || (pos > l->total)) return -1;

    for (i = l->total - 1; i >= pos; i--)
    {
        l->valores[i + 1] = l->valores[i];
    }

    l->valores[pos] = it;
    l->total++;

    return 0;
}

int buscaritemchave (lista *l, int chave, aluno *retorno)
{
    int i;

    if (l == NULL) return 2;
    if (listavazia(l) == 0) return 1;

    for (i = 0; i < l->total; i++)
    {
        if (l->valores[i].mat == chave)
        {
            *retorno = l->valores[i];
            return 0;
        }
    }

    return -1;
}

int buscarposicao (lista *l, int posicao, aluno *it)
{
    int i;

    if (l == NULL) return 2;
    if (listavazia(l) == 0) return 1;
    if ((posicao < 0) || (posicao >= l->total)) return -1;

    for (i = 0; i < l->total; i++)
    {
        if (i == posicao)
        {
            *it = l->valores[i];
            return 0;
        }
    }

    return -2;
}

int listavazia (lista *l)
{
    if (l == NULL) return 2;
    if (l->total == 0) return 0;
    else return 1;
}

int removerinicio (lista *l)
{
    int i;

    if (l == NULL) return 2;
    if (listavazia(l) == 0) return 1;

    for (i = 0; i < l->total-1; i++)
        l->valores[i] = l->valores[i + 1];

    l->total--;

    return 0;
}

int removerfim (lista *l)
{
    if (l == NULL) return 2;
    if (listavazia(l) == 0) return 1;

    l->total--;

    return 0;
}

int removerposicao (lista *l, int pos)
{
    int i;

    if (l == NULL) return 2;
    if (listavazia(l) == 0) return 1;
    if ((pos < 0) || (pos > l->total)) return -1;

    for (i = pos; i < l->total - 1; i++)
    {
        l->valores[i] = l->valores[i + 1];
    }

    l->total--;

    return 0;
}

int removeritem (lista *l, aluno it)
{
    int i, j;

    if (l == NULL) return 2;
    if (listavazia(l) == 0) return 1;

    for (i = 0; i < l->total; i++)
    {
        if (l->valores[i].mat == it.mat)
        {
            for (j = i; j < l->total; j++)
            {
                l->valores[j] = l->valores[j + 1];
            }

            l->total--;
            return 0;
        }
    }

    return -1;
}

int listacheia (lista *l)
{
    if (l == NULL) return 2;
    if (l->total == MAX) return 0;
    else return 1;
}

int tamanho (lista *l)
{
    return l->total;
}

void mostrar (lista *l)
{
    int i;

    if (l != NULL)
    {
        printf ("[ ");
        for (i = 0; i < l->total; i++)
        {
            printf ("{%d, ", l->valores[i].mat);
            printf ("%s, ", l->valores[i].nome);
            printf ("%.2f}", l->valores[i].n1);
        }
        printf (" ]\n");
    }
}

int contemitem (lista *l, aluno *it)
{
    int i;

    if (l == NULL) return 2;
    if (listavazia(l) == 0) return -2;

    for (i = 0; i < l->total; i++)
    {
        if (l->valores[i].mat == it->mat)
        {
            return 0;
        }
    }

    return 1;
}

int contaitem (lista *l, aluno it)
{
    int i, cont;

    if (l == NULL) return 2;
    if (listavazia(l) == 0) return 1;

    for (i = 0, cont = 0; i < l->total; i++)
    {
        if (l->valores[i].mat == it.mat)
        {
            cont++;
        }
    }

    return cont;
}

lista *reversa (lista *l)
{
    lista *r;
    int i, j;

    r = criar ( );

    for (i = l->total-1, j = 0; i>=0; i--, j++)
    {
        r->valores[j] = l->valores[i];
        r->total++;
    }

    return r;
}
