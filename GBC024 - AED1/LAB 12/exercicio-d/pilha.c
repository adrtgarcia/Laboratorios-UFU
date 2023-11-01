#include "pilha.h"
#include "lista.h"

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

pilha *criar_pilha ( )
{
    pilha *p = (pilha *) malloc (sizeof(pilha));
    p->topo = NULL;
    return p;
}

void limpar_pilha (pilha *p)
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
    if (p == NULL) return -2;               //pilha n�o alocada

    no *n = (no *) malloc (sizeof(no));
    n->valor = i;
    n->prox = p->topo;
    p->topo = n;

    return 0;                               //n�mero inserido
}

int pop (pilha *p, int *i)
{
    if (p == NULL) return -2;               //pilha n�o alocada
    if (pilha_vazia(p) == 0) return -1;     //pilha vazia

    no *temp = p->topo;
    *i = temp->valor;
    p->topo = temp->prox;

    free (temp);

    return 0;                               //n�mero removido
}

int pop_aux (pilha *p)
{
    if (p == NULL) return -2;               //pilha n�o alocada
    if (pilha_vazia(p) == 0) return -1;     //pilha vazia

    no *temp = p->topo;
    p->topo = temp->prox;

    free (temp);

    return 0;                               //n�mero removido
}

int tamanho (pilha *p)
{
    if (p == NULL) return -2;               //pilha n�o alocada

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
    if (p == NULL) return -2;               //pilha n�o alocada
    if (p->topo == 0) return 0;             //pilha vazia
    else return 1;                          //pilha n�o vazia
}

int binario (lista *l, int decimal)
{
    if(l == NULL) return -2;                //lista n�o alocada

    pilha *p = criar_pilha ( );
    int resto, tam, binario;

    while (decimal > 0)
    {
        resto = decimal % 2;
        push (p, resto);
        decimal = decimal / 2;
    }

    tam = tamanho(p);
    while (tam > 0)
    {
        pop (p, &binario);
        inserir_fim (l, binario);
        tam--;
    }

    return 0;                               //n�mero em bin�rio
}
