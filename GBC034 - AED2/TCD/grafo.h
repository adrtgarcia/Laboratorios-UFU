#ifndef GRAFO_H
#define GRAFO_H

#include <time.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define arestas_maximo 4500
#define vertices_maximo 100

typedef time_t tempo;

typedef int tipoPeso;

typedef int tipoVerticeValor;

typedef struct TipoItem {
tipoVerticeValor vertice;
  tipoPeso peso;
} tipoItem;

typedef struct TipoCelula {
  tipoItem item;
  struct TipoCelula *prox;
} tipoCelula;

typedef tipoCelula *TipoApontador;

typedef struct TipoLista {
  TipoApontador primeiro, ultimo;
} tipoLista;

typedef struct TipoGrafo {
  tipoLista adj[vertices_maximo];
  int numVertices;
  int numArestas;
} tipoGrafo;

void listaVazia(tipoLista *lista);

short vazia(tipoLista lista);

void insere(tipoItem *x, tipoLista *lista);

void fgVazio(tipoGrafo *grafo);

void insereAresta(tipoVerticeValor v1, tipoVerticeValor v2, tipoPeso Peso,tipoGrafo *grafo);

short existeAresta(tipoGrafo *grafo, tipoVerticeValor vertice1, tipoVerticeValor vertice2);

short listaAdjVazia(tipoGrafo *grafo, tipoVerticeValor *vertice);

TipoApontador primeiroListaAdj(tipoGrafo *grafo, tipoVerticeValor *vertice);

void proxAdj(tipoGrafo *grafo, tipoVerticeValor *vertice, tipoVerticeValor *adj, tipoPeso *peso, TipoApontador *prox, short *Fimlistaadj);

void retira(tipoLista *lista, TipoApontador p, tipoItem *item);

void retiraAresta(tipoGrafo *grafo, tipoVerticeValor *v1, tipoVerticeValor *v2, tipoPeso *peso);

void liberaGrafo(tipoGrafo *grafo);

void imprimeGrafo(tipoGrafo *grafo);

void imprimeLista(tipoLista lista);

tipoGrafo lerGrafo(const char *nomeArquivo);

void imprimeAdjacentes(int sala, tipoGrafo *grafo);

#endif /* GRAFO_H */
