#ifndef ABB_H
#define ABB_H

#include "grafo.h"

#include <time.h>
#include <string.h>
#include <stdio.h>
#include <stdlib.h>

#define arestasMaximo 4500
#define verticesMaximo 100
#define nomeMaximo 100
#define areasMaximo 7
#define FALSE 0
#define TRUE 1

typedef struct Info {
  tipoGrafo grafo;
} info;

typedef info tipoChave;

typedef struct Registro {
  tipoChave chave;
} Registro;

typedef struct No {
  struct No *esq;
  struct No *dir;
  Registro registro;
} no;

typedef no *apontador;

typedef apontador *tipoDicionario;

void insereBinaria(Registro x, apontador *p);

void inicializaBinaria(apontador *Dicionario);

#endif /* ABB_H */
