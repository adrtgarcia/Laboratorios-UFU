#include "fila.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct fila
{
    int inicio, fim, quant;
    paciente info[MAX];
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

int inserir (fila *f, paciente p)
{
    if (f == NULL) return -2;
    if (fila_cheia(f) == 0) return -1;

    strcpy (f->info[f->fim].nome, p.nome);
    f->info[f->fim].senha = f->quant;
    f->fim = (f->fim + 1) % MAX;
    f->quant++;

    return 0;
}

int remover (fila *f, paciente *p)
{
    if (f == NULL) return -2;
    if (fila_vazia(f) == 0) return -1;

    *p = f->info[f->inicio];
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

        while (q > 0)
        {
            printf ("\nnome: %s ", f->info[i].nome);
            printf ("\nsenha: %d\n", f->info[i].senha);
            i = (i + 1)% MAX;
            q--;
        }
    }
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
