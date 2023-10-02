#ifndef LISTADUP_H_INCLUDED
#define LISTADUP_H_INCLUDED

struct aluno
{
    char nome[30];
    int mat;
    float nota;
};

typedef struct aluno aluno;
typedef struct lista lista;
typedef struct no no;

lista *criar ( );

int lista_vazia (lista *l);

int inserir_aluno (lista *l, aluno a);

int remover_aluno (lista *l, int mat);

void mostrar (lista *l);

int maior_nota (lista *l, aluno *retorno);

void limpar (lista *l);

int trocar_posicao (lista *l, int p1, int p2);

int tamanho (lista *l);

#endif // LISTADUP_H_INCLUDED
