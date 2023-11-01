#include "pilha.h"

#include <stdio.h>
#include <stdlib.h>

typedef struct no
{
    int valor;
    struct no *prox;
} no;

typedef struct pilha
{
    no *topo;
} pilha;

pilha *criar ( )
{
    pilha *p = (pilha *) malloc (sizeof(pilha));
    p->topo = NULL;
    return p;
}

void limpar (pilha *p)
{
    if (p != NULL)
    {
        while (pilha_vazia(p) != 0)
            pop_aux (p);

        free (p);
        p = NULL;
    }
}

int push (pilha *p, int i)
{
    if (p == NULL) return -2;               //pilha não alocada

    no *n = (no *) malloc (sizeof(no));
    n->valor = i;
    n->prox = p->topo;
    p->topo = n;

    return 0;                               //número inserido
}

int pop (pilha *p, int *i)
{
    if (p == NULL) return -2;               //pilha não alocada
    if (pilha_vazia(p) == 0) return -1;     //pilha vazia

    no *temp = p->topo;
    *i = temp->valor;
    p->topo = temp->prox;

    free (temp);

    return 0;                               //número removido
}

int pop_aux (pilha *p)
{
    if (p == NULL) return -2;               //pilha não alocada
    if (pilha_vazia(p) == 0) return -1;     //pilha vazia

    no *temp = p->topo;
    p->topo = temp->prox;

    free (temp);

    return 0;                               //número removido
}

int tamanho (pilha *p)
{
    if (p == NULL) return -2;               //pilha não alocada

    int cont = 0;
    no *n = p->topo;

    while (n != NULL)
    {
        cont++;
        n = n->prox;
    }

    return cont;
}

int pilha_vazia (pilha *p)
{
    if (p == NULL) return -2;               //pilha não alocada
    if (p->topo == 0) return 0;             //pilha vazia
    else return 1;                          //pilha não vazia
}

//funções extras
void mostrar (pilha *p)
{
    if (p != NULL)
    {
        no *n = p->topo;

        printf ("[");

        while (n != NULL)
        {
            printf (" %d ", n->valor);
            n = n->prox;
        }

        printf ("]\n");
    }
}

int comparar (pilha *p1, pilha *p2)
{
    if ((p1 == NULL) || (p2 == NULL))
        return -2;          //pilha(s) não alocada(s)
    if (tamanho(p1) != tamanho(p2))
        return 1;           //pilhas diferentes

    int num1 = 0, num2 = 0;

    while ((pilha_vazia(p1) != 0) && (pilha_vazia(p2) != 0))
    {
        pop (p1, &num1);
        pop (p2, &num2);

        if (num1 != num2)
            return 1;       //pilhas diferentes
    }

    if ((pilha_vazia(p1) == 0) && (pilha_vazia(p2) == 0))
        return 0;           //pilhas iguais

    return 1;               //pilhas diferentes
}
