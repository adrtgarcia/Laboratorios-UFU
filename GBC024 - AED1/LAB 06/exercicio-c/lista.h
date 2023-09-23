#ifndef LISTA_H_INCLUDED
#define LISTA_H_INCLUDED

struct aluno
{
	int mat;
	char nome[30];
	float n1;
};
typedef struct aluno aluno;
typedef struct lista lista;

lista *criar (int MAX);

void limpar (lista *l);

int inseririnicio (lista *l, aluno it);

int inserirfim (lista *l, aluno it);

int inserirposicao (lista *l, aluno it, int pos);

int removerinicio (lista *l);

int removerfim (lista *l);

int removerposicao (lista *l, int pos);

int removeritem (lista *l, aluno it);

int buscaritemchave (lista *l, int chave, aluno *retorno);

int buscarposicao (lista *l, int posicao, aluno *it);

int listavazia (lista *l);

int listacheia (lista *l);

int tamanho (lista *l);

void mostrar (lista *l);

int contemitem (lista *l, aluno *it);

int contaitem (lista *l, aluno it);

lista *reversa (lista *l);

#endif // LISTA_H_INCLUDED
