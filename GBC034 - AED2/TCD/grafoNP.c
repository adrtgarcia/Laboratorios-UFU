#include "grafoNP.h"
#include <stdlib.h>
#include <stdio.h>

#define MAX_NUM_VERTICES  100
#define TRUE  1
#define FALSE 0

typedef int Sala;
typedef struct GrafoNP {
    int mat[MAX_NUM_VERTICES][MAX_NUM_VERTICES];
    int numVertices;
} GrafoNP;
typedef int TipoApontador;

TipoApontador aux;
int i;
Sala nVertices;
int fimListaAdj;

void fgVazio(GrafoNP *grafo) {
    int i, j;
    for (i = 0; i < grafo->numVertices; i++) {
        for (j = 0; j < grafo->numVertices; j++)
            grafo->mat[i][j] = 0;
    }
}

void insereAresta(Sala *sala1, Sala *sala2,
                  GrafoNP *grafo) {
    grafo->mat[*sala1][*sala2] = 1;
}

int existeAresta(Sala sala1,
                   Sala sala2, GrafoNP *grafo) {
    return (grafo->mat[sala1][sala2] > 0);
}

/* Operadores para obter a lista de adjacentes */
int listaAdjVazia(Sala *sala, GrafoNP *grafo) {
    TipoApontador aux = 0;
    int listaVazia = TRUE;
    while (aux < grafo->numVertices && listaVazia) {
        if (grafo->mat[*sala][aux] > 0)
            listaVazia = FALSE;
        else aux++;
    }
    return (listaVazia == TRUE);
}

TipoApontador primeiroListaAdj(Sala *sala, GrafoNP *grafo) {
    Sala result;
    TipoApontador aux = 0;
    int listaVazia = TRUE;
    while (aux < grafo->numVertices && listaVazia) {
        if (grafo->mat[*sala][aux] > 0) {
            result = aux;
            listaVazia = FALSE;
        }
        else aux++;
    }
    if (aux == grafo->numVertices)
        printf("Erro: Lista adjacencia vazia (primeiroListaAdj)\n");
    return result;
}

void proxAdj(Sala *sala, GrafoNP *grafo,
             Sala *adj, TipoApontador *prox, int *fimListaAdj) {
    /* Retorna adj apontado por prox */
    *adj = *prox;
    (*prox)++;
    while (*prox < grafo->numVertices && grafo->mat[*sala][*prox] == 0) {
        (*prox)++;
    }
    if (*prox == grafo->numVertices) {
        *fimListaAdj = TRUE;
    }
}

void retiraAresta(Sala *sala1, Sala *sala2,
                  GrafoNP *grafo) {
    grafo->mat[*sala1][*sala2] = 0;
}

void imprimeGrafo(GrafoNP *grafo) {
    int i, j;
    printf("   ");
    for (i = 0; i < grafo->numVertices; i++) printf("%d", i);
    printf("\n");
    for (i = 0; i <  grafo->numVertices; i++) {
        printf("%d", i);
        for (j = 0; j < grafo->numVertices; j++)
            printf("%d", grafo->mat[i][j]);
        printf("\n");
    }
}
