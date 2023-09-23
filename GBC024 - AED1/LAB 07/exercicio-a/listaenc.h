#ifndef LISTAENC_H_INCLUDED
#define LISTAENC_H_INCLUDED

#define MAX 100

struct aluno
{
    int mat;
    char nome[30];
    float n1;
};

typedef struct aluno aluno;
typedef struct lista lista;
typedef struct no no;

lista *criar ( );

int lista_vazia (lista *l);

int inserir_inicio (lista *l, aluno it);

int inserir_fim (lista *l, aluno it);

int inserir_posicao (lista *l, aluno it, int posicao);

int remover_inicio (lista *l);

int remover_fim (lista *l);

int remover_posicao (lista *l, int posicao);

int remover_item (lista *l, aluno it);

int buscar_itemchave (lista *l, int chave, aluno *retorno);

int buscar_posicao (lista *l, int posicao, aluno *retorno);

void limpar (lista *l);

void mostrar (lista *l);

#endif // LISTAENC_H_INCLUDED
