#include "pilha.h"

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

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
    }
}

int push (pilha *p, int i)
{
    if (p == NULL) return -2;

    noP *n = (noP *) malloc (sizeof(noP));
    n->valor = i;
    n->prox = p->topo;
    p->topo = n;

    return 0;
}

int pop (pilha *p, int *i)
{
    if (p == NULL) return -2;
    if (pilha_vazia(p) == 0) return -1;

    noP *n = p->topo;
    *i = n->valor;
    p->topo = n->prox;

    free (n);
    n = NULL;

    return 0;
}

int tamanho_pilha (pilha *p)
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
void mostrar_pilha (pilha *p)
{
    if (p == NULL) return;

    printf ("\n[");
    noP *n = p->topo;

    while (n != NULL)
    {
        printf (" %d ", n->valor);
        n = n->prox;
    }

    printf ("]\n");
}

char auxPolonesa_extraiTermo (char *s, char r[], int *i)
{
    char c = s[(*i)];
    while ((c != ' ') && (c != '\0'))
    {
        strncat(r, &c, 1);
        (*i)++;
        c = s[(*i)];
    }
    (*i)++;
    return r;
}

int polonesa (char *expressao)
{
    pilha *p = criarP ( );

    int i = 0;
    int op1, op2;
    int resultado;

    while (expressao[i] != '\0')
    {
        char termo[5] = "";
        auxPolonesa_extraiTermo (expressao, termo, &i);
        if ((strcmp(termo,"/") != 0) && (strcmp(termo,"-") != 0) && (strcmp(termo,"+") != 0) && (strcmp(termo,"*") != 0))
            push(p,atoi(termo));
        else
        {
            pop(p,&op1);
            pop(p,&op2);
            if (strcmp(termo,"/") == 0) resultado = op2 / op1;
            else if (strcmp(termo,"-") == 0) resultado = op2 - op1;
            else if (strcmp(termo,"+") == 0) resultado = op2 + op1;
            else if (strcmp(termo,"*") == 0) resultado = op2 * op1;
            push(p,resultado);
        }
    }
    pop(p,&resultado);
    return resultado;
}
