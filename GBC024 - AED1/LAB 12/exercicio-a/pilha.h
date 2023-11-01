#ifndef PILHA_H_INCLUDED
#define PILHA_H_INCLUDED

#define MAX 100

typedef struct pilha pilha;

pilha *criar ( );
void limpar (pilha *p);

int push (pilha *p, int i);
int pop (pilha *p);

int tamanho (pilha *p);
int pilha_vazia (pilha *p);
int pilha_cheia (pilha *p);

void mostrar (pilha *p); //função extra

#endif // PILHA_H_INCLUDED
