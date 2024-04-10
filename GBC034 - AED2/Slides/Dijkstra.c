void Dijkstra (TipoGrafo *Grafo, TipoValorVertice *Raiz) {
	TipoPeso P[MAXNUMVERTICES + 1];
	TipoValorVertice Pos[MAXNUMVERTICES + 1];
	long Antecessor[MAXNUMVERTICES + 1];
	short Itensheap[MAXNUMVERTICES + 1];
	TipoVetor A;
	TipoValorVertice u, v;
	TipoItem temp;
	for (u = 0; u <= Grafo->NumVertices; u++) {
		Antecessor[u~= -1; P[u] = INFINITO;
		A[u + 1].Chave = u;
		Itensheap[u] = TRUE; Pos[u] = u + 1;
	}
	n = Grafo->NumVertices;
	P[*(Raiz)] = 0;
	Constroi(A, P, Pos);
	while (n >= 1) {
		temp = RetiraMinInd(A, P, Pos);
		u = temp.Chave; Itensheap[u] = FALSE;
		if (!ListaAdjVazia(&u, Grafo) {
			Aux = PrimeiroListaAdj(&u, Grafo); FimListaAdj = FALSE;
			while (!FimListaAdj) {
				ProxAdj(&u, Grafo, &v, &Peso, &Aux, &FimListaAdj);
				if (P[v] > P[u] + Peso) {
					P[v] = P[u] + Peso; Antecessor[v] = u;
					DiminuiChaveInd(Pos[v], P[v], A, P, Pos);
					printf(“Caminho: v[%d] v[%d] d[%d]”, v, Antecessor[v], P[v]);
					scanf(“%*[^\n]”);
					getchar( );
				}
			}
		}
	}
}
