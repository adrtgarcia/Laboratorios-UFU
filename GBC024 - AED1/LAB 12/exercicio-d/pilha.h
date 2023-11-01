#ifndef PILHA_H_INCLUDED
#define PILHA_H_INCLUDED

typedef struct pilha pilha;
typedef struct lista lista;

pilha *criar_pilha ( );
void limpar_pilha (pilha *p);

int push (pilha *p, int i);
int pop (pilha *p, int *i);
int pop_aux (pilha *p);

int tamanho (pilha *p);
int pilha_vazia (pilha *p);

//função extra
int binario (lista *l, int decimal);

#endif // PILHA_H_INCLUDED
