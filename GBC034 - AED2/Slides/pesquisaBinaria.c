int buscaBinaria (int *vetor, int n, int chaveBusca) {
  int inf = 0; sup = n - 1; meio;
  while (inf <= sup) {
    meio = (inf + sup) / 2;
    if (vetor[meio] == chaveBusca) return meio;
    else if (vetor[meio] > chaveBusca) sup = meio - 1;
    else inf = meio + 1;
  }
  return -1;
}
