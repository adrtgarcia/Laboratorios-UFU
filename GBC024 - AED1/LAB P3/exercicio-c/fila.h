#ifndef FILA_H_INCLUDED
#define FILA_H_INCLUDED

typedef struct fila fila;

fila *criarF ( );
void limparF (fila *f);

int inserir (fila *f, int i);
int remover (fila *f, int *i);

int tamanhoF (fila *f);
int fila_vazia (fila *f);

//funções extras
void mostrar_fila (fila *f);
int fura_fila (fila *f, int num);

#endif // FILA_H_INCLUDED
