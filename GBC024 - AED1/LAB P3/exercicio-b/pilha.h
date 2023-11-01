#ifndef PILHA_H_INCLUDED
#define PILHA_H_INCLUDED

typedef struct pilha pilha;

pilha *criarP ( );
void limparP (pilha *p);

int push (pilha *p, int num);
int pop (pilha *p, int *num);

int tamanhoP (pilha *p);
int pilha_vazia (pilha *p);

//função extra
void mostrarP (pilha *p);

#endif // PILHA_H_INCLUDED
