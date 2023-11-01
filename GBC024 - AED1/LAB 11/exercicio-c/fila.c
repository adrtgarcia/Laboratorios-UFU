#include "fila.h"
#include <stdio.h>
#include <stdlib.h>

struct fila
{
    int inicio, fim, quant;
    int valor[MAX];
};

typedef struct fila fila;

fila *criar ( )
{
    fila *f = (fila *) malloc (sizeof(fila));

    f->inicio = 0;
    f->fim = 0;
    f->quant = 0;

    return f;
}

void limpar (fila *f)
{
    free (f);
    f = NULL;
}

int inserir (fila *f, int numero)
{
    if (f == NULL) return -2;
    if (fila_cheia(f) == 0) return -1;

    f->valor[f->fim] = numero;
    f->fim = (f->fim + 1) % MAX;
    f->quant++;

    return 0;
}

int remover (fila *f, int *numero)
{
    if (f == NULL) return -2;
    if (fila_vazia(f) == 0) return -1;

    *numero = f->valor[f->inicio];
    f->inicio = (f->inicio + 1 ) % MAX;
    f->quant--;

    return 0;
}

void mostrar (fila *f)
{
    if (f != NULL)
    {
        int i = f->inicio;
        int q = f->quant;

        printf("\n[");
        while(q > 0)
        {
            printf(" %d ", f->valor[i]);
            i = (i + 1)% MAX;
            q--;
        }
        printf("]\n");
    }
}

fila *intercalada (fila *a, fila *b)
{
    if ((a != NULL) && (b != NULL))
    {
        fila *f = criar ( );

        if (f != NULL)
        {
            int num;

            while(fila_vazia(a) != 0)
            {
                if(remover(a, &num) == 0) inserir(f, num);
                if(remover(b, &num) == 0) inserir(f, num);
            }

            while(fila_vazia(b) != 0)
            {
                if(remover(b, &num) == 0) inserir(f, num);
            }

            return f;

        }
    }

    return NULL;
}

int remover_negativos (fila *f)
{
    if (f == NULL) return -2;
    if (fila_vazia(f) == 0) return -1;

    int num;
    int q = tamanho (f);

    while (q > 0)
    {
        remover (f, &num);
        if (num >= 0) inserir (f, num);
        q--;
    }

    return 0;
}

int tamanho (fila *f)
{
    if (f == NULL) return -2;

    return f->quant;
}

int fila_vazia (fila *f)
{
    if (f == NULL) return -2;
    if (f->quant == 0) return 0;
    else return 1;
}

int fila_cheia (fila *f)
{
    if (f == NULL) return -2;
    if (f->quant == MAX) return 0;
    else return 1;
}
