#ifndef PILHAF_H_INCLUDED
#define PILHAF_H_INCLUDED

#include "pilha.h"

typedef struct fila fila;

fila *criar ( );
void limpar (fila *f);

int inserir (fila *f, int num);
int consultar (fila *f, int *num);
int remover (fila *f, int *num);

int tamanho (fila *f);
int fila_vazia (fila *f);

//função extra
void mostrar (fila *f);

#endif // PILHAF_H_INCLUDED
