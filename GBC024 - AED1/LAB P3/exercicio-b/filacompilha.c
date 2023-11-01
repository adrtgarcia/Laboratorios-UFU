#include "pilha.h"
#include "pilhaF.h"

#include <stdio.h>
#include <stdlib.h>

typedef struct noF noF;

typedef struct fila
{
    pilha *p1;
    pilha *p2;
} fila;

fila *criar ( )
{
    fila *f = (fila *) malloc (sizeof(fila));
    f->p1 = criarP ( );
    f->p2 = criarP ( );
    return f;
}

void limpar (fila *f)
{
    if (f != NULL)
    {
        limparP (f->p1);
        limparP (f->p2);
    } else return;
}

int inserir (fila *f, int num)
{
    if (f == NULL) return -2;
    push (f->p1, num);
}

int consultar (fila *f, int *num)
{
    if (f == NULL) return -2;
    int valor;

    while (pilha_vazia(f->p1) != 0)
    {
        pop (f->p1, &valor);
        push (f->p2, valor);
    }

    *num = valor;

    while (pilha_vazia(f->p2) != 0)
    {
        pop (f->p2, &valor);
        push (f->p1, valor);
    }
}

int remover (fila *f, int *num)
{
    if (f == NULL) return -2;
    int valor;

    while (pilha_vazia(f->p1) != 0)
    {
        pop (f->p1, &valor);
        push (f->p2, valor);
    }

    pop (f->p2, &valor);
    *num = valor;

    while (pilha_vazia(f->p2) != 0)
    {
        pop (f->p2, &valor);
        push (f->p1, valor);
    }
}

int tamanho (fila *f)
{
    if (f == NULL) return -2;
    return tamanhoP(f->p1);
}

int fila_vazia (fila *f)
{
    if (f == NULL) return -2;
    return pilha_vazia(f->p1);
}

//função extra
void mostrar (fila *f)
{
    if (f != NULL)
    {
        int valor;

        while (pilha_vazia(f->p1) != 0)
        {
            pop (f->p1, &valor);
            push (f->p2, valor);
        }

        mostrarP (f->p2);

        while (pilha_vazia(f->p2) != 0)
        {
            pop (f->p2, &valor);
            push (f->p1, valor);
        }
    } else return;
}
