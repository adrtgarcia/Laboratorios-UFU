#ifndef FILA_H_INCLUDED
#define FILA_H_INCLUDED

#include "pilha.h"

typedef struct fila fila;

fila *criar_fila ( );
void limpar_fila (fila *f);

int inserir (fila *f, int i);
int remover (fila *f, int *i);

int tamanho_fila (fila *f);
int fila_vazia (fila *f);

//funções extras
void mostrar_fila (fila *f);
void inverte_fila (fila *f);

#endif // FILA_H_INCLUDED
