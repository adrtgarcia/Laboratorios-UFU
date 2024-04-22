#include "grafo.h"
#include "abb.h"

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include <unistd.h>

#define verdadeiro 1
#define falso 0

void listaVazia(tipoLista *lista) {
  lista->primeiro = (TipoApontador)malloc(sizeof(tipoCelula));
  lista->ultimo = lista->primeiro;
  lista->primeiro->prox = NULL;
}

short vazia(tipoLista lista) { return (lista.primeiro == lista.ultimo); }

void insere(tipoItem *x, tipoLista *lista) {
  lista->ultimo->prox = (TipoApontador)malloc(sizeof(tipoCelula));
  lista->ultimo = lista->ultimo->prox;
  lista->ultimo->item = *x;
  lista->ultimo->prox = NULL;
}

void fgVazio(tipoGrafo *grafo) {
  long i;
  for (i = 0; i < grafo->numVertices; i++)
    listaVazia(&grafo->adj[i]);
}

void insereAresta(tipoVerticeValor v1, tipoVerticeValor v2, tipoPeso Peso,
                  tipoGrafo *grafo) {
  tipoItem x;
  x.vertice = v2;
  x.peso = Peso;
  insere(&x, &grafo->adj[v1]);
}

short existeAresta(tipoGrafo *grafo, tipoVerticeValor vertice1,
                   tipoVerticeValor vertice2) {
  TipoApontador Aux;
  short EncontrouAresta = falso;
  Aux = grafo->adj[vertice1].primeiro->prox;
  while (Aux != NULL && EncontrouAresta == falso) {
    if (vertice2 == Aux->item.vertice)
      EncontrouAresta = verdadeiro;
    Aux = Aux->prox;
  }
  return EncontrouAresta;
}

short listaAdjVazia(tipoGrafo *grafo, tipoVerticeValor *vertice) {
  return (grafo->adj[*vertice].primeiro == grafo->adj[*vertice].ultimo);
}

TipoApontador primeiroListaAdj(tipoGrafo *grafo, tipoVerticeValor *vertice) {
  return (grafo->adj[*vertice].primeiro->prox);
}

void proxAdj(tipoGrafo *grafo, tipoVerticeValor *vertice, tipoVerticeValor *adj,
             tipoPeso *peso, TipoApontador *prox, short *Fimlistaadj) {
  *adj = (*prox)->item.vertice;
  *peso = (*prox)->item.peso;
  *prox = (*prox)->prox;
  if (*prox == NULL)
    *Fimlistaadj = verdadeiro;
}

void retira(tipoLista *lista, TipoApontador p, tipoItem *item) {
  TipoApontador q = (TipoApontador)malloc(sizeof(TipoApontador));

  if (vazia(*lista) || p == NULL || p->prox == NULL) {
    printf("Erro: lista vazio ou posicao nao existe\n");
    return;
  }
  q = p->prox;
  *item = q->item;
  p->prox = q->prox;
  if (p->prox == NULL)
    lista->ultimo = p;
  free(q);
}

void retiraAresta(tipoGrafo *grafo, tipoVerticeValor *v1, tipoVerticeValor *v2,
                  tipoPeso *peso) {
  TipoApontador AuxAnterior, Aux;
  short EncontrouAresta = falso;
  tipoItem x;
  AuxAnterior = grafo->adj[*v1].primeiro;
  Aux = grafo->adj[*v1].primeiro->prox;
  while (Aux != NULL && EncontrouAresta == falso) {
    if (*v2 == Aux->item.vertice) {
      retira(&grafo->adj[*v1], AuxAnterior, &x);
      grafo->numArestas--;
      EncontrouAresta = verdadeiro;
    }
    AuxAnterior = Aux;
    Aux = Aux->prox;
  }
}

void liberaGrafo(tipoGrafo *grafo) {
  TipoApontador AuxAnterior, Aux;
  AuxAnterior = (TipoApontador)malloc(sizeof(TipoApontador));
  Aux = (TipoApontador)malloc(sizeof(TipoApontador));

  for (int i = 0; i < grafo->numVertices; i++) {
    Aux = grafo->adj[i].primeiro->prox;
    free(grafo->adj[i].primeiro);
    grafo->adj[i].primeiro = NULL;
    while (Aux != NULL) {
      AuxAnterior = Aux;
      Aux = Aux->prox;
      free(AuxAnterior);
    }
  }
  grafo->numVertices = 0;
}

void imprimeGrafo(tipoGrafo *grafo) {
  int i;
  TipoApontador Aux;
  for (i = 0; i < grafo->numVertices; i++) {
    printf("vertice%2d:", i);
    if (!vazia(grafo->adj[i])) {
      Aux = grafo->adj[i].primeiro->prox;
      while (Aux != NULL) {
        printf("%3d (%d)", Aux->item.vertice, Aux->item.peso);
        Aux = Aux->prox;
      }
    }
    putchar('\n');
  }
}

void imprimeLista(tipoLista lista) {
  TipoApontador aux;
  aux = lista.primeiro->prox;
  while (aux != NULL) {
    printf("------------------------\n");
    printf("|        Sala %d        |\n", aux->item.vertice);
    printf("------------------------\n");
    aux = aux->prox;
  }
}

tipoGrafo lerGrafo(const char *nomeArquivo) {
  FILE *arquivo;
  tipoGrafo grafo;

  arquivo = fopen(nomeArquivo, "r");
  if (arquivo == NULL) {
    printf("Erro ao abrir o arquivo para ler os grafos.\n");
    exit(1);
  }

  fscanf(arquivo, "%d %d", &grafo.numVertices, &grafo.numArestas);
  fgVazio(&grafo);

  for (int i = 0; i < grafo.numArestas; i++) {
    int v1, v2;
    tipoPeso p;
    fscanf(arquivo, "%d %d %d", &v1, &v2, &p);
    insereAresta(v1, v2, p, &grafo);
  }

  fclose(arquivo);

  return grafo;
}
