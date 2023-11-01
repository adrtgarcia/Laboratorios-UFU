#ifndef PILHA_H_INCLUDED
#define PILHA_H_INCLUDED

typedef struct pilha pilha;

pilha *criarP ( );
void limparP (pilha *p);

int push (pilha *p, int i);
int pop (pilha *p, int *i);

int tamanho_pilha (pilha *p);
int pilha_vazia (pilha *p);

//função extra
void mostrar_pilha (pilha *p);
int polonesa (char *expressao);

#endif // PILHA_H_INCLUDED
