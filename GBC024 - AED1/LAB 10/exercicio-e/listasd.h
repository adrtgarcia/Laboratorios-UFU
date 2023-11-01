#ifndef LISTASD_H_INCLUDED
#define LISTASD_H_INCLUDED

typedef struct no* lista;

lista *criar ( );

int lista_vazia (lista *l);
int tamanho (lista *l);

int inserir_inicio (lista *l, int num);
int inserir_fim (lista *l, int num);
int inserir_posicao (lista *l, int num, int posicao);

int remover_inicio (lista *l);
int remover_fim (lista *l);
int remover_posicao (lista *l, int posicao);

int procura_ultimo (lista *l, int *encontrado);
int soma_elementos (lista *l);
void mostrar_reversa (lista *l);
int remover_numero (lista *l, int num);
int incrementar (lista *l);

void limpar (lista *l);
void mostrar (lista *l);

#endif // LISTASD_H_INCLUDED
