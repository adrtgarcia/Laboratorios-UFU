#ifndef LISTACIRC_H_INCLUDED
#define LISTACIRC_H_INCLUDED

#define MAX 100

struct aluno
{
    int mat;
    char nome[30];
    float n1;
};
typedef struct aluno aluno;
typedef struct lista lista;

lista *criar ( );
void limpar (lista *l);

int inserir_inicio (lista *l, aluno it);
int inserir_fim (lista *l, aluno it);
int inserir_posicao (lista *l, aluno it, int pos);

int remover_inicio (lista *l);
int remover_fim (lista *l);
int remover_posicao (lista *l, int pos);
int remover_item (lista *l, int it);
int remover_centro (lista *l);

int buscar_itemchave (lista *l, int chave, aluno *retorno);
int buscar_posicao (lista *l, int posicao, int *retorno);

int lista_vazia (lista *l);
int lista_cheia (lista *l);

int tamanho (lista *l);
void mostrar (lista *l);

#endif // LISTACIRC_H_INCLUDED
