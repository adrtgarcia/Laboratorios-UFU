#ifndef PILHA_H_INCLUDED
#define PILHA_H_INCLUDED

typedef struct pilha pilha;

pilha *criar_pilha ( );
void limpar_pilha (pilha *p);

int push (pilha *p, int i);
int pop (pilha *p, int *i);

int tamanho_pilha (pilha *p);
int pilha_vazia (pilha *p);

//função extra
void mostrar_pilha (pilha *p);

#endif // PILHA_H_INCLUDED
