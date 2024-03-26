#ifndef GRAFONP_H_INCLUDED
#define GRAFONP_H_INCLUDED

#define MAXNUMVERTICES

#define MAX_NUM_VERTICES  100
#define TRUE  1
#define FALSE 0

typedef int Sala;

typedef struct GrafoNP {
    int mat[MAX_NUM_VERTICES][MAX_NUM_VERTICES];
    int numVertices;
} GrafoNP;
typedef int TipoApontador;

void fgVazio(GrafoNP *grafo);

void insereAresta(Sala *sala1, Sala *sala2, GrafoNP *grafo);

short existeAresta(Sala sala1, Sala sala2, GrafoNP *grafo);

short listaAdjVazia(Sala *sala, GrafoNP *grafo);

TipoApontador primeiroListaAdj(Sala *sala, GrafoNP *grafo);

void proxAdj(Sala *sala, GrafoNP *grafo, Sala *adj, TipoApontador *prox, short *fimListaAdj);

void retiraAresta(Sala *sala1, Sala *sala2, GrafoNP *grafo);

void imprimeGrafo(GrafoNP *grafo);

#endif // GRAFONP_H_INCLUDED
