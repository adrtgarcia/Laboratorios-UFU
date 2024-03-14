// FGVazio(Grafo) : cria um grafo vazio
// InsereAresta(V1, V2, Peso, Grafo): insere uma aresta no grafo
// ExisteAresta(V1, V2, Grafo): verifica se existe uma determinada aresta

// obtém a lista de vértices adjacentes a um determinado vértice
// ListaAdjVazia(v, Grafo): retorna true se a lista de adjacentes de v está vazia
// PrimeiroListaAdj(v, Grafo): retorna o endereço do primeiro vértice na lista de adjacentes de v
// ProxAdj(v, Grafo, u, Peso, Aux, FimListaAdj): retorna o vértice u (apontado por aux) da lista de adjacentes de v, o peso da aresta (u,v)
//-> ao retornar, aux aponta para o próximo vértice da lista de adjacentes de v, e FimListaAdj retorna true se o final da lista de adjacentes foi encontrado

// RetiraAresta(V1, V2, Peso, Grafo): retira uma aresta do grafo
// LiberaGrafo(Grafo): liberar o espaço ocupado pelo grafo
// ImprimeGrafo(Grafo): imprime um grafo
// GrafoTransposto(Grafo, GrafoT): obtém o transposto de um grafo direcionado
// RetiraMin(A): obtém a aresta de menor peso de um grafo com peso nas arestas
