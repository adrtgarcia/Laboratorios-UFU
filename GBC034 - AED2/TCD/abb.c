#include "abb.h"

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include <unistd.h>

void insereBinaria(Registro r, apontador *p) {
  if (*p == NULL) {
    *p = (apontador)malloc(sizeof(no));
    (*p)->registro = r;
    (*p)->esq = NULL;
    (*p)->dir = NULL;
    return;
  }

  if (r.chave.grafo.numVertices < (*p)->registro.chave.grafo.numVertices) {
    insereBinaria(r, &(*p)->esq);
    return;
  }
  if (r.chave.grafo.numVertices > (*p)->registro.chave.grafo.numVertices)
    insereBinaria(r, &(*p)->dir);
}

void inicializaBinaria(apontador *Dicionario) { *Dicionario = NULL; }

