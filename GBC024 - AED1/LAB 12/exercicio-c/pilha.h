#ifndef PILHA_H_INCLUDED
#define PILHA_H_INCLUDED

typedef struct pilha pilha;

pilha *criar ( );
void limpar (pilha *p);

int push (pilha *p, char c);
int pop (pilha *p, char *c);
int pop_aux (pilha *p);

int tamanho (pilha *p);
int pilha_vazia (pilha *p);

//função extra
int delimitadores (pilha *p, char *str);

#endif // PILHA_H_INCLUDED
