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

int push (pilha *p, char c)
{
    if (p == NULL) return -2;                                       //pilha n�o alocada

    no *n = (no *) malloc (sizeof(no));
    n->valor = c;
    n->prox = p->topo;
    p->topo = n;

    return 0;                                                       //n�mero inserido
}

int pop (pilha *p, char *c)
{
    if (p == NULL) return -2;                                       //pilha n�o alocada
    if (pilha_vazia(p) == 0) return -1;                             //pilha vazia

    no *temp = p->topo;
    *c= temp->valor;
    p->topo = temp->prox;

    free (temp);

    return 0;                                                       //n�mero removido
}

int pop_aux (pilha *p)
{
    if (p == NULL) return -2;                                       //pilha n�o alocada
    if (pilha_vazia(p) == 0) return -1;                             //pilha vazia

    no *temp = p->topo;
    p->topo = temp->prox;

    free (temp);

    return 0;                                                       //n�mero removido
}

int tamanho (pilha *p)
{
    if (p == NULL) return -2;                                       //pilha n�o alocada

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
    if (p == NULL) return -2;                                       //pilha n�o alocada
    if (p->topo == 0) return 0;                                     //pilha vazia
    else return 1;                                                  //pilha n�o vazia
}

//fun��o extra
int delimitadores (pilha *p, char *str)
{
    if (p == NULL) return -2;                                       //pilha n�o alocada

    int i = 0;
    char c;

    while (str[i] != '\0')
    {
        if ((str[i] == '(') || (str[i] == ')') || (str[i] == '['))
            push (p, str[i]);
        else if ((str[i] == ')') || (str[i] == ']') || (str[i] == '}'))
        {
            if (pilha_vazia(p) == 0) return 1;                      //delimitador inv�lido

            pop (p, &c);
            if ((str[i] == ')') && (c != '(')) return 1;            //delimitador inv�lido
            if ((str[i] == ']') && (c != '[')) return 1;            //delimitador inv�lido
            if ((str[i] == '}') && (c != '{')) return 1;            //delimitador inv�lido

        } else if (str[i] != ' ') return -3;                        //caractere inv�lido

        i++;
    }

    if (pilha_vazia(p) == 0) return 0;                              //delimitadores em ordem v�lida
    else return 1;                                                  //delimitadores em ordem inv�lida
}
