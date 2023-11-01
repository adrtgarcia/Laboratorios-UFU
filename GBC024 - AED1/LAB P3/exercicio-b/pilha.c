#include "pilha.h"

#include <stdio.h>
#include <stdlib.h>

typedef struct noP
{
    int valor;
    struct noP *prox;
} noP;

typedef struct pilha
{
    noP *topo;
} pilha;

pilha *criarP ( )
{
    pilha *p = (pilha *) malloc (sizeof(pilha));
    p->topo = NULL;
    return p;
}

void limparP (pilha *p)
{
    if (p != NULL)
    {
        while (pilha_vazia(p) != 0)
            pop (p, NULL);

        free (p);
        p = NULL;
    } else return;
}

int push (pilha *p, int num)
{
    if (p == NULL) return -2;

    noP *n = (noP *) malloc (sizeof(noP));
    n->valor = num;
    n->prox = p->topo;
    p->topo = n;

    return 0;
}

int pop (pilha *p, int *num)
{
    if (p == NULL) return -2;
    if (pilha_vazia(p) == 0) return -1;

    noP *n = p->topo;
    *num = n->valor;

    return 0;
}

int tamanhoP (pilha *p)
{
    if (p == NULL) return -2;

    int cont = 0;
    noP *n = p->topo;

    while (n != NULL)
    {
        cont++;
        n = n->prox;
    }

    return cont;
}

int pilha_vazia (pilha *p)
{
    if (p == NULL) return -2;
    if (p->topo == NULL) return 0;
    else return 1;
}

//função extra
void mostrarP (pilha *p)
{
    if (p != NULL)
    {
        noP *n = p->topo;
        printf ("\n[");

        while (n != NULL)
        {
            printf (" %d ", n->valor);
            n = n->prox;
        }

        printf ("]\n");
    } else return;
}
