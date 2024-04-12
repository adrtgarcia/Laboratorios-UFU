// pesquisa sequencial em vetor
int buscaSequencial (int *vetor, int n, int chaveBusca) {
  int i;
  for (i = 0; i < n; i++) {
    if (vetor[i] == chaveBusca) return 1;
  }
  return -1;
}

// pesquisa sequencial em lista
tElem *pesquisaLista (tElem *prim, int chaveBusca) {
  tElem *aux;
  for (aux = prim; aux != NULL; aux = aux->prox) {
    if (aux->campo == chaveBusca) return aux;
  }
  return NULL;
}

// pequisa sequencial ordenada
int buscaSequencialOrdenada (int *vetor, int n, int chaveBusca) {
  int i;
  for (i = 0; i < n; i++) {
    if (vetor[i] == chaveBusca) return i;
    else if (vetor[i] > chaveBusca) return -1;
  }
  return -1;
}
