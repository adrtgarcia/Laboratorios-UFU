#ifndef PILHA_H_INCLUDED
#define PILHA_H_INCLUDED

typedef struct pilha pilha;

pilha *criar ( );
void limpar (pilha *p);

int push (pilha *p, int i);
int pop (pilha *p, int *i);
int pop_aux (pilha *p);

int tamanho (pilha *p);
int pilha_vazia (pilha *p);

//funções extras
void mostrar (pilha *p);
int comparar (pilha *p1, pilha *p2);

#endif // PILHA_H_INCLUDED
