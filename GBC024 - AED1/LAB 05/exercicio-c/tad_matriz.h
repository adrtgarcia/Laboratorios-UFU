#ifndef TAD_MATRIZ_H_INCLUDED
#define TAD_MATRIZ_H_INCLUDED

typedef struct matriz matriz;

matriz *criar (int linhas, int colunas);

void destruir (matriz *m);

void atribuir (matriz *m, int i, int j);

float acessar (matriz *m, int i, int j);

int numero_linhas (matriz *m);

int numero_colunas (matriz *m);

void preencher (matriz *m, float minimo, float maximo);

matriz *somar (matriz *m1, matriz *m2);

#endif // TAD_MATRIZ_H_INCLUDED
