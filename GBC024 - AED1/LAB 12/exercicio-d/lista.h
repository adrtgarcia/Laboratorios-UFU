#ifndef LISTA_H_INCLUDED
#define LISTA_H_INCLUDED

typedef struct lista lista;

lista *criar_lista ( );
int lista_vazia (lista *l);
int inserir_inicio (lista *l, int i);
int inserir_fim (lista *l, int i);
int remover (lista *l);
void limpar_lista (lista *l);

//função extra
void mostrar_lista (lista *l);

#endif // LISTA_H_INCLUDED
