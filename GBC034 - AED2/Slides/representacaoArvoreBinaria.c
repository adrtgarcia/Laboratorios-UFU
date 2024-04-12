typedef struct tipoNo{
  int info;
  tipoNo *esq;
  tipoNo *dir;
} tipoNo;

// com pai
typedef struct tipoNo {
  int info;
  tipoNo *esq;
  tipoNo *dir;
  tipoNo *pai;
} tipoNo;

// estrutura do dicionário
typedef int tipoChave;
typedef struct registro {
  tipoChave chave;
  /* outros componentes */
} registro;
typedef struct No *apontador;
typedef struct No {
  registro reg;
  apontador esq, dir;
} No;
typedef apontador tipoDicionario;

// funções
void inicializa (apontador *dicionario) {
  *dicionario = NULL;
}

void vazio (apontador *dicionario) {
  return (dicionario == NULL);
}

// percurso central
void central (apontador p) {
  if (p == NULL) return;
  central (p->esq);
  printf ("%d\n", p->reg.chave);
  central (p->dir);
}
