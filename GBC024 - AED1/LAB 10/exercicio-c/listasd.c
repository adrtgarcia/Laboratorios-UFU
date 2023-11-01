#include "listasd.h"

#include <stdio.h>
#include <stdlib.h>

struct no
{
    int valor;
    struct no *prox;
};

typedef struct no no;
typedef struct no* lista;

lista *criar ( )
{
    lista *l = (lista*) malloc (sizeof(lista));
    (*l) = NULL;
    return l;
}

int lista_vazia (lista *l)
{
    if (l == NULL) return 2;        //lista não alocada
    if (*l == NULL) return 0;       //vazia
    return 1;                       //não vazia
}

int tamanho (lista *l)
{
    if (l == NULL) return -2;       //lista não alocada
    if (lista_vazia(l) == 0) return 0;  //tamanho 0

    int cont = 0;

    no *n = (*l);
    while (n != NULL)
    {
        n = n->prox;
        cont++;
    }

    return cont;                    //tamanho da lista
}

int inserir_inicio (lista *l, int num)
{
    if (l == NULL) return 2;        //lista não alocada

    no *n = (no*) malloc (sizeof(no));
    n->valor = num;
    n->prox = (*l);
    (*l) = n;

    return 0;                       //número inserido
}

int inserir_fim (lista *l, int num)
{
    if (l == NULL) return 2;        //lista não alocada
    if (lista_vazia(l) == 0) return inserir_inicio (l, num);    //número inserido

    no *n = (no*) malloc (sizeof(no));
    n->valor = num;
    n->prox = NULL;

    no *nlista = (no*) malloc (sizeof(no));
    nlista = (*l);

    while (nlista->prox != NULL)
        nlista = nlista->prox;

    nlista->prox = n;

    return 0;                       //número inserido
}

int inserir_posicao (lista *l, int num, int posicao)
{
    if (l == NULL) return 2;        //lista não alocada
    if ((lista_vazia(l) == 0) || (posicao == 0)) return inserir_inicio(l, num);     //número inserido

    int tam = tamanho(l);
    if ((posicao > tam) || (posicao < 0)) return 3;     //posição inválida

    no *nlista = (*l);
    while ((nlista->prox != NULL) && (posicao > 1))
    {
        nlista = nlista->prox;
        posicao--;
    }

    no *n = (no*) malloc (sizeof(no));
    n->valor = num;
    n->prox = nlista->prox;
    nlista->prox = n->prox;

    return 0;                       //número inserido
}

int remover_inicio (lista *l)
{
    if (l == NULL) return 2;        //lista não alocada
    if (lista_vazia(l) == 0) return 1;  //lista vazia

    no *nlista = (*l);
    (*l) = (*l)->prox;
    free (nlista);

    return 0;                       //número removido
}

int remover_fim (lista *l)
{
    if (l == NULL) return 2;        //lista não alocada
    if (lista_vazia(l) == 0) return 1;  //lista vazia

    no *nlista = (*l);
    no *aux = NULL;

    while (nlista->prox != NULL)
    {
        aux = nlista;
        nlista = nlista->prox;
    }

    if (aux == NULL) (*l) = NULL;
    else aux->prox = NULL;

    free (nlista);

    return 0;                       //número removido
}

int remover_posicao (lista *l, int posicao)
{
    if (l == NULL) return 2;        //lista não alocada
    if (lista_vazia(l) == 0) return 1;  //lista vazia
    if (posicao == 0) return remover_inicio(l);  //número removido

    int tam = tamanho(l);
    if ((posicao > tam) || (posicao < 0)) return 3;     //posição inválida

    no *nlista = (*l);
    no *aux = NULL;

    while ((nlista->prox != NULL) && (posicao > 0))
    {
        aux = nlista;
        nlista = nlista->prox;
        posicao--;
    }

    if (nlista->prox == NULL) remover_fim (l);  //número removido
    else {
        aux->prox = nlista->prox;
        free(nlista);
    }
    return 0;                       //número removido

}

int procura_ultimo (lista *l, int *encontrado)
{
    if (l == NULL) return 2;        //lista não alocada
    if (lista_vazia(l) == 0) return 1; //lista vazia

    no *n = (*l);
    if (n->prox == NULL)
    {
        *encontrado = n->valor;
        return 0;                   //número encontrado
    }

    return procura_ultimo(&(n->prox), encontrado);
}

int soma_elementos (lista *l)
{
    if (l != NULL)
    {
        no *n = (*l);

        if (n->prox == NULL)
            return n->valor;

        return (n->valor + soma_elementos(&(n->prox)));
    }
}

void mostrar_reversa (lista *l)
{
    no *n = (*l);

    if (n != NULL)
    {
        mostrar_reversa (&(n->prox));
        printf (" %d ", n->valor);
    }
}

void limpar (lista *l)
{
    while (lista_vazia(l) != 0)
        remover_inicio (l);
}

void mostrar (lista *l)
{
    if (l != NULL)
    {
        printf ("[");
        no *n = (*l);

        while (n != NULL)
        {
            printf (" %d ", n->valor);
            n = n->prox;
        }

        printf ("]");
    }
}
