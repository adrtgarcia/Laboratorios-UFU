#ifndef TAD_CONJUNTOS_H_INCLUDED
#define TAD_CONJUNTOS_H_INCLUDED

typedef struct conjunto conjunto;

conjunto *criacao ( );

void membro (conjunto *c);

void inserir (conjunto *c);

void remover (conjunto *c);

conjunto *uniao (conjunto *c1, conjunto *c2);

conjunto *interseccao (conjunto *c1, conjunto *c2);

conjunto *diferenca (conjunto *c1, conjunto *c2);

#endif // TAD_CONJUNTOS_H_INCLUDED
