#ifndef FILA_H_INCLUDED
#define FILA_H_INCLUDED

#define MAX 100

struct paciente
{
    char nome[50];
    int senha;
};

typedef struct paciente paciente;
typedef struct fila fila;

fila *criar ( );
void limpar (fila *f);

int inserir (fila *f, paciente p);
int remover (fila *f, paciente *p);
void mostrar (fila *f);

int tamanho (fila *f);
int fila_vazia (fila *f);
int fila_cheia (fila *f);

#endif // FILA_H_INCLUDED
