#include "pilha.h"

#include <stdio.h>
#include <stdlib.h>

struct pilha
{
    int topo;
    int valor[MAX];
};

typedef struct pilha pilha;

pilha *criar ( )
{
    pilha *p = (pilha *) malloc (sizeof(pilha));
    p->topo = 0;
    return p;
}

void limpar (pilha *p)
{
    free (p);
    p = NULL;
}

int push (pilha *p, int i)
{
    if (p == NULL) return -2;               //pilha não alocada
    if (pilha_cheia(p) == 0) return -1;     //pilha cheia

    p->valor[p->topo] = i;
    p->topo++;

    return 0;                               //número inserido
}

int pop (pilha *p)
{
    if (p == NULL) return -2;               //pilha não alocada
    if (pilha_vazia(p) == 0) return -1;     //pilha vazia

    p->topo--;

    return 0;                               //número removido
}

int tamanho (pilha *p)
{
    if (p == NULL) return -2;               //pilha não alocada
    return p->topo;
}

int pilha_vazia (pilha *p)
{
    if (p == NULL) return -2;               //pilha não alocada
    if (p->topo == 0) return 0;             //pilha vazia
    else return 1;                          //pilha não vazia
}

int pilha_cheia (pilha *p)
{
    if (p == NULL) return -2;               //pilha não alocada
    if (p->topo == MAX) return 0;           //pilha cheia
    else return 1;                          //pilha não cheia
}

//função extra

void mostrar (pilha *p)
{
    if (p != NULL)
    {
        int i;

        printf ("[");

        for (i = 0; i < p->topo; i++)
            printf (" %d ", p->valor[i]);

        printf ("]\n");
    }
}
