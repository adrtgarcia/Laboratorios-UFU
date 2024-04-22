// o programa está rodando em outras plataformas
// porém teve problemas no replit a partir da area central

// algoritmos de ordenação, de grafo e de árvore de Nivio Ziviani

#include "abb.h"
#include "grafo.h"

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

#define arestas_maximo 4500
#define vertices_maximo 100
#define areas_maximo 6

int numJogadores;

typedef struct Jogador {
  char nome[20];
  double tempoAreas[6];
  double tempoTotal;
  double tempoAC;
  int pontuacao;
} Jogador;

int apagarRegistro(Jogador *vetor, int numRegistro);
void lerArquivo(Jogador *vetorJogadores);
int apagarRanking();
int salvarRanking(Jogador *vetor);
int qtdJogadores(Jogador *vetor);
void adicionarJogador(Jogador novoJogador, Jogador *vetorJogadores);
void mostrarRanking();
void jogar(tipoDicionario p, Jogador *jogador);
void caminhoAreaCentral(tipoVerticeValor verticeA, tipoGrafo *Grafo, Jogador *jogador);
void caminho(tipoVerticeValor verticeA, tipoGrafo *Grafo, Jogador *jogador);
void insertionSort(Jogador *vetor, int tamVetor, int opcaoRanking, int opcaoArea);
void printarMapa(int indice);

int main() {
  Jogador vetorJogadores[10], jogadorAtual;
  int opcaoMenu, opcaoRanking, opcaoArea;
  int i, registroJogador, retorno;
  Registro registro;
  tipoDicionario Dicionario;

  lerArquivo(vetorJogadores);
  numJogadores = qtdJogadores(vetorJogadores);

  while (1) {
    printf("MENU\n");
    printf("(1) JOGAR\n");
    printf("(2) RANKING\n");
    printf("(3) APAGAR HISTORICO\n");
    printf("(4) APAGAR REGISTRO DE JOGADOR\n");
    printf("(5) SAIR\n\n");

    do {
      lerArquivo(vetorJogadores);
      printf("OPCAO: ");
      scanf("%d", &opcaoMenu);
      if ((opcaoMenu < 1) || (opcaoMenu > 5))
        printf("OPCAO INDISPONIVEL, TENTE NOVAMENTE.\n");
    } while ((opcaoMenu < 1) || (opcaoMenu > 5));

    if (opcaoMenu == 5) {
      retorno = salvarRanking(vetorJogadores);
      if (retorno == 0)
        printf("ENCERRANDO...\n");
      else
        printf("NAO FOI POSSIVEL SAIR SALVAR O RANK.\n");
      break;
    }

    switch (opcaoMenu) {
    case 1:
      inicializaBinaria(&Dicionario);

      setbuf(stdin, NULL);
      printf("DIGITE SEU NOME: ");
      fgets(jogadorAtual.nome, 20, stdin);
      jogadorAtual.nome[strcspn(jogadorAtual.nome, "\n")] = '\0';
      jogadorAtual.pontuacao = 0;
      jogadorAtual.tempoTotal = 0;
      for (i = 0; i < 6; i++) {
        jogadorAtual.tempoAreas[i] = 0;
      }

      registro.chave.grafo = lerGrafo("areaCentral.txt");
      insereBinaria(registro, &Dicionario);
      registro.chave.grafo = lerGrafo("Area5.txt");
      insereBinaria(registro, &Dicionario);
      registro.chave.grafo = lerGrafo("Area4.txt");
      insereBinaria(registro, &Dicionario);
      registro.chave.grafo = lerGrafo("Area3.txt");
      insereBinaria(registro, &Dicionario);
      registro.chave.grafo = lerGrafo("Area2.txt");
      insereBinaria(registro, &Dicionario);
      registro.chave.grafo = lerGrafo("Area1.txt");
      insereBinaria(registro, &Dicionario);

      jogar(&Dicionario, &jogadorAtual);

      if (jogadorAtual.pontuacao >= vetorJogadores[9].pontuacao) {
        adicionarJogador(jogadorAtual, vetorJogadores);
        printf("\n\nREGISTRO SALVO NO RANKING!\n\n");
        retorno = salvarRanking(vetorJogadores);

      }

      break;
    case 2:
      printf("\nORDENACAO DO RANKING\n");
      printf("(1) PONTUACAO\n");
      printf("(2) TEMPO TOTAL\n");
      printf("(3) TEMPO POR AREA\n");

      do {
        printf("OPCAO: ");
        scanf("%d", &opcaoRanking);
        if ((opcaoRanking < 1) || (opcaoRanking > 3))
          printf("OPCAO INDISPONIVEL, TENTE NOVAMENTE.\n");
      } while ((opcaoRanking < 1) || (opcaoRanking > 3));

      switch (opcaoRanking) {
      case 1:
        insertionSort(vetorJogadores, 10, 1, 0);
        printf ("\n\n");
        for (int i = 0; i < 10; i++) {
          printf("NOME: %s\t", vetorJogadores[i].nome);
          printf("PONTUACAO: %d\n\n", vetorJogadores[i].pontuacao);
        }
        printf ("\n");
        break;
      case 2:
        insertionSort(vetorJogadores, 10, 2, 0);
        printf ("\n\n");
        for (int i = 0; i < 10; i++) {
          printf("NOME: %s\t", vetorJogadores[i].nome);
          printf("TEMPO TOTAL: %.3lf\n\n", vetorJogadores[i].tempoTotal);
        }
        printf ("\n");
        break;
      case 3:
        do {
          printf("ESCOLHA UMA AREA (1 -> 6): ");
          scanf("%d", &opcaoArea);
          if ((opcaoArea < 1) || (opcaoArea > 6))
            printf("OPCAO INDISPONIVEL, TENTE NOVAMENTE.\n");
        } while ((opcaoArea < 1) || (opcaoArea > 6));

        insertionSort(vetorJogadores, 10, 3, opcaoArea);
        printf ("\n\n");
        for (int i = 0; i < 10; i++) {
          printf("NOME: %s\t", vetorJogadores[i].nome);
          if (opcaoArea != 6)
            printf("TEMPO AREA %d: %.3lf\n\n", opcaoArea,
                   vetorJogadores[i].tempoAreas[opcaoArea-1]);
          else
            printf("TEMPO AREA CENTRAL: %.3lf\n\n",
                   vetorJogadores[i].tempoAreas[5]);
        }
        printf("\n");
        break;
      }
      break;
    case 3:
      retorno = apagarRanking();
      if (retorno == 0) {
        printf("HISTORICO EXCLUIDO.\n\n");
      } else
        printf("NAO FOI POSSIVEL EXCLUIR O HISTORICO.\n");
      break;
    case 4:
      do {
        printf("DIGITE O NUMERO DO REGISTRO DO JOGADOR (1-10): ");
        scanf("%d", &registroJogador);
        if ((registroJogador < 1) || (registroJogador > 10))
          printf("OPCAO INDISPONIVEL, TENTE NOVAMENTE.\n");
      } while ((registroJogador < 1) || (registroJogador > 10));

      retorno = apagarRegistro(vetorJogadores, registroJogador-1);
      if (retorno == 0)
        printf("JOGADOR EXCLUIDO.\n");
      else
        printf("NAO FOI POSSIVEL EXCLUIR O JOGADOR.\n");
      break;
    }
  }
  return 0;
}

void insertionSort(Jogador *vetor, int tamVetor, int opcaoRanking, int opcaoArea) {
  int i, j;
  Jogador temp;

  switch (opcaoRanking) {
  case 1: // pontuação
    for (i = 1; i < tamVetor; i++) {
      temp = vetor[i];
      for (j = i - 1; j >= 0 && vetor[j].pontuacao < temp.pontuacao ||
                      strcmp(vetor[j].nome, "SEM REGISTRO") == 0;
           j--) { // Alteração aqui // mudar && para ||
        vetor[j + 1] = vetor[j];
      }
      vetor[j + 1] = temp;
    }
    break;

    case 2: // tempo total
    for (i = 1; i < tamVetor; i++) {
        temp = vetor[i];
        if (strcmp(temp.nome, "SEM REGISTRO") != 0) {
            j = i - 1;
            while (j >= 0 && strcmp(vetor[j].nome, "SEM REGISTRO") == 0) {
                vetor[j + 1] = vetor[j];
                j--;
            }
            while (j >= 0 && vetor[j].tempoTotal > temp.tempoTotal) {
                vetor[j + 1] = vetor[j];
                j--;
            }
            vetor[j + 1] = temp;
        }
    }
    break;

    case 3: // tempo área específica
    for (i = 1; i < tamVetor; i++) {
        temp = vetor[i];
        if (strcmp(temp.nome, "SEM REGISTRO") != 0) {
            j = i - 1;
            while (j >= 0 && strcmp(vetor[j].nome, "SEM REGISTRO") == 0) {
                vetor[j + 1] = vetor[j];
                j--;
            }
            while (j >= 0 && (vetor[j].tempoAreas[opcaoArea-1] > temp.tempoAreas[opcaoArea-1] ||
                              (vetor[j].tempoAreas[opcaoArea-1] == temp.tempoAreas[opcaoArea-1] &&
                               strcmp(vetor[j].nome, "SEM REGISTRO") != 0))) {
                vetor[j + 1] = vetor[j];
                j--;
            }
            vetor[j + 1] = temp;
        }
    }
    break;
  }
}

int salvarRanking(Jogador *vetor) {
  FILE *arquivo = fopen("ranking.txt", "w");
  if (arquivo == NULL)
    return -1;
  for(int i = 0; i < 10; i++){
  fprintf(arquivo,"%s;%d;%lf;%lf;%lf;%lf;%lf;%lf;%lf;\n", vetor[i].nome, vetor[i].pontuacao, vetor[i].tempoTotal, vetor[i].tempoAreas[0], vetor[i].tempoAreas[1], vetor[i].tempoAreas[2], vetor[i].tempoAreas[3], vetor[i].tempoAreas[4], vetor[i].tempoAreas[5]);
  }
  fclose(arquivo);
  return 0;
}

int apagarRanking() {
  FILE *arquivo = fopen("ranking.txt", "w");
  if (arquivo == NULL)
    return -1;

  for (int i = 0; i < 10; i++) {
    fprintf(arquivo, "SEM REGISTRO;0;0;0;0;0;0;0;0;\n");
  }
  numJogadores = 0;
  fclose(arquivo);
  return 0;
}

void adicionarJogador(Jogador novoJogador, Jogador *vetor){
  vetor[numJogadores] = novoJogador;
  if(numJogadores-1 < 9){
    numJogadores++;
  }

}

int apagarRegistro(Jogador *vetor, int numRegistro) {
  strcpy(vetor[numRegistro].nome, "SEM REGISTRO");
  vetor[numRegistro].pontuacao = 0;
  for (int i = 0; i < 6; i++) {
    vetor[numRegistro].tempoAreas[i] = 0;
  }
  vetor[numRegistro].tempoTotal = 0;

  for (int i = numRegistro; i < 10; i++) {
    strcpy(vetor[i].nome, vetor[i + 1].nome);
    vetor[i].pontuacao = vetor[i + 1].pontuacao;
    vetor[i].tempoTotal = vetor[i + 1].tempoTotal;
    vetor[i].tempoAreas[0] = vetor[i + 1].tempoAreas[0];
    vetor[i].tempoAreas[1] = vetor[i + 1].tempoAreas[1];
    vetor[i].tempoAreas[2] = vetor[i + 1].tempoAreas[2];
    vetor[i].tempoAreas[3] = vetor[i + 1].tempoAreas[3];
    vetor[i].tempoAreas[4] = vetor[i + 1].tempoAreas[4];
    vetor[i].tempoAreas[5] = vetor[i + 1].tempoAreas[5];
  }

  strcpy(vetor[9].nome, "SEM REGISTRO");
  vetor[9].pontuacao = 0;
  for (int i = 0; i < 6; i++) {
    vetor[9].tempoAreas[i] = 0;
  }
  vetor[9].tempoTotal = 0;

  int retorno = salvarRanking(vetor);
  if (retorno != 0) {
    printf("\nERRO AO APAGAR O REGISTRO\n");
    return -1;
  }
  numJogadores--;
  return 0;
}

void printarMapa(int indice) {
  switch (indice) {
  case 1:
    printf("\n XXXXXXXXXXXXXXXXXXXXXX");
    printf("\n X                    X");
    printf("\n X                    X");
    printf("\n X                    X");
    printf("\n X                    X");
    printf("\n X                    X");
    printf("\n X                    X");
    printf("\n X                    X");
    printf("\n X                    X");
    printf("\n X                    X");
    printf("\n X                    X");
    printf("\n X                    X");
    printf("\n X                    X");
    printf("\n X                    X");
    printf("\n X                    X");
    printf("\n X                    X");
    printf("\n X                    X");
    printf("\n X                    X");
    printf("\n X ...                X");
    printf("\n X .1.                X");
    printf("\n X ...                X");
    printf("\n X                    X");
    printf("\n XXXXXXXXXXXXXXXXXXXXXX");
    break;
  case 2:
    printf("\n XXXXXXXXXXXXXXXXXXXXXX");
    printf("\n X                    X");
    printf("\n X                    X");
    printf("\n X                    X");
    printf("\n X                    X");
    printf("\n X                    X");
    printf("\n X                    X");
    printf("\n X                    X");
    printf("\n X                    X");
    printf("\n X                    X");
    printf("\n X                    X");
    printf("\n X                    X");
    printf("\n X                    X");
    printf("\n X                    X");
    printf("\n X                    X");
    printf("\n X                    X");
    printf("\n X                    X");
    printf("\n X                    X");
    printf("\n X ...  ...           X");
    printf("\n X .1.--.2.           X");
    printf("\n X ...  ...           X");
    printf("\n X                    X");
    printf("\n XXXXXXXXXXXXXXXXXXXXXX");
    break;
  case 3:
    printf("\n XXXXXXXXXXXXXXXXXXXXXX");
    printf("\n X                    X");
    printf("\n X                    X");
    printf("\n X                    X");
    printf("\n X                    X");
    printf("\n X                    X");
    printf("\n X                    X");
    printf("\n X                    X");
    printf("\n X                    X");
    printf("\n X                    X");
    printf("\n X                    X");
    printf("\n X                    X");
    printf("\n X                    X");
    printf("\n X    ...             X");
    printf("\n X    .3.             X");
    printf("\n X    ...             X");
    printf("\n X      \\             X");
    printf("\n X       \\            X");
    printf("\n X ...  ...           X");
    printf("\n X .1.--.2.           X");
    printf("\n X ...  ...           X");
    printf("\n X                    X");
    printf("\n XXXXXXXXXXXXXXXXXXXXXX");
    break;
  case 4:
    printf("\n XXXXXXXXXXXXXXXXXXXXXX");
    printf("\n X                    X");
    printf("\n X                    X");
    printf("\n X                    X");
    printf("\n X                    X");
    printf("\n X                    X");
    printf("\n X                    X");
    printf("\n X                    X");
    printf("\n X                    X");
    printf("\n X                    X");
    printf("\n X                    X");
    printf("\n X                    X");
    printf("\n X                    X");
    printf("\n X    ...             X");
    printf("\n X    .3.\\            X");
    printf("\n X    ... \\           X");
    printf("\n X      \\  \\          X");
    printf("\n X       \\  \\         X");
    printf("\n X ...  ...  ...      X");
    printf("\n X .1.--.2.  .4.      X");
    printf("\n X ...  ...  ...      X");
    printf("\n X                    X");
    printf("\n XXXXXXXXXXXXXXXXXXXXXX");
    break;
  case 5:
    printf("\n XXXXXXXXXXXXXXXXXXXXXX");
    printf("\n X                    X");
    printf("\n X                    X");
    printf("\n X                    X");
    printf("\n X                    X");
    printf("\n X                    X");
    printf("\n X                    X");
    printf("\n X                    X");
    printf("\n X                    X");
    printf("\n X                    X");
    printf("\n X                    X");
    printf("\n X                    X");
    printf("\n X                    X");
    printf("\n X    ...             X");
    printf("\n X    .3.\\            X");
    printf("\n X    ... \\           X");
    printf("\n X      \\  \\          X");
    printf("\n X       \\  \\         X");
    printf("\n X ...  ...  ...  ... X");
    printf("\n X .1.--.2.  .4.--.5. X");
    printf("\n X ...  ...  ...  ... X");
    printf("\n X                    X");
    printf("\n XXXXXXXXXXXXXXXXXXXXXX");
    break;
  case 6:
    printf("\n XXXXXXXXXXXXXXXXXXXXXX");
    printf("\n X                    X");
    printf("\n X                    X");
    printf("\n X  ****************  X");
    printf("\n X  * AREA CENTRAL *  X");
    printf("\n X  ****************  X");
    printf("\n X            \\\\      X");
    printf("\n X             \\\\     X");
    printf("\n X              ||    X");
    printf("\n X              ||    X");
    printf("\n X              ||    X");
    printf("\n X              \\\\    X");
    printf("\n X               \\\\   X");
    printf("\n X    ...        ||   X");
    printf("\n X    .3.\\       ||   X");
    printf("\n X    ... \\      \\\\   X");
    printf("\n X      \\  \\      ||  X");
    printf("\n X       \\  \\     ||  X");
    printf("\n X ...  ...  ...  ... X");
    printf("\n X .1.--.2.  .4.--.5. X");
    printf("\n X ...  ...  ...  ... X");
    printf("\n X                    X");
    printf("\n XXXXXXXXXXXXXXXXXXXXXX\n");
    break;
  default:
    printf("\nErro.");
    break;
  }
}

void caminho(tipoVerticeValor verticeA, tipoGrafo *grafo, Jogador *jogador) {

  if (verticeA == grafo->numVertices - 1) {

    printf("\nVOCE CHEGOU A SAIDA!!\n");

    return;
  }

  printf("\nSALA ATUAL: [%d]\n\n", verticeA);
  int escolha;
  TipoApontador aux = primeiroListaAdj(grafo, &verticeA);

  if (aux == NULL) {
    printf("\nSALA SEM SAIDA!!\n\n");
    return caminho(0, grafo, jogador);
  }

  while (1) {
    aux = primeiroListaAdj(grafo, &verticeA);
    printf("\nESCOLHA UMA SALA\n");
    imprimeLista(grafo->adj[verticeA]);
    scanf("%d", &escolha);

    while (aux->prox != NULL) {
      if (aux->item.vertice == escolha)
        break;
      aux = aux->prox;
    }

    if (aux->item.vertice != escolha)
      printf("SALA INVALIDA\n\n");
    else
      break;
  }
 caminho(aux->item.vertice, grafo, jogador);
}

void caminhoAreaCentral(tipoVerticeValor verticeA, tipoGrafo *grafo, Jogador *jogador) {

  if (verticeA == grafo->numVertices - 1) {
    getchar();
    return;
  }

  printf("\nQUANTIDADE DE PONTOS: %d\n\n", jogador->pontuacao);
  int escolha;
  TipoApontador aux = primeiroListaAdj(grafo, &verticeA);
  int ganhou = 0;
  while (aux != NULL) {
    if (aux->item.vertice == 10) {
      ganhou = 1;
    }
    aux = aux->prox;
  }

  while (1) {

    aux = primeiroListaAdj(grafo, &verticeA);
    while (1) {
      aux = primeiroListaAdj(grafo, &verticeA);
      printf("\nESCOLHA UMA SALA:\n");
      imprimeLista(grafo->adj[verticeA]);

      scanf("%d", &escolha);

      while (aux->prox != NULL) {
        if (aux->item.vertice == escolha)
          break;
        aux = aux->prox;
      }
      if (aux->item.vertice == escolha)
        break;

      printf("SALA INVALIDA\n\n");

    }

    if (ganhou == 1) {
    printf ("PARABENS!! VOCE GANHOU O JOGO!!\n\n");
    return;
  }

    if (jogador->pontuacao + aux->item.peso >= 0) {
      break;
    } else {
      printf("QUANTIDADE DE PONTOS INSUFICIENTE!\n");
      if (aux->prox == NULL) {
        printf("        \\     /        \n");
        printf("       \\ \\   / /       \n");
        printf("        \\ ... /        \n");
        printf("         .   .         \n");
        printf("        . X X .        \n");
        printf("   GAME .     . END    \n");
        printf("        . --- .        \n");
        printf("       / .   . \\       \n");
        printf("      / / ... \\ \\      \n");
        printf("       /       \\       \n");
        printf("          | |          \n");
        printf("          | |          \n");
        printf("          | |          \n");
        printf("          | |          \n");
        printf("          | |          \n");
        printf("          | |          \n");
        printf("          | |          \n");
        printf("          | |          \n");
        printf("          | |          \n");
        printf("          | |          \n");
        printf("          | |          \n");
        jogador->pontuacao = 0;
        return;
      }
    }
  }

  jogador->pontuacao += aux->item.peso;
  caminhoAreaCentral(aux->item.vertice, grafo, jogador);
}

void jogar(tipoDicionario p, Jogador *jogador) {
  if (*p == NULL) {
    return;
  }

  jogar(&(*p)->esq, jogador);
  jogar(&(*p)->dir, jogador);

  tipoGrafo *aux = (tipoGrafo *)malloc(sizeof(tipoGrafo));

  if (aux == NULL) {
    printf("ERRO DE ALOCACAO DE MEMORIA\n");
    exit(1);
  }

  fgVazio(aux);

  *aux = (*p)->registro.chave.grafo;
  int salaAtual = aux->numVertices - 4;
  int contador = salaAtual + 1;

  printarMapa(contador-1);

  printf("\n\n\nTEMPO TOTAL GASTO: %f", jogador->tempoTotal);

  if (aux->adj[0].primeiro->prox->item.peso == 0) {
    time_t comeco = time(NULL);
    caminho(0, aux, jogador);
    time_t termino = time(NULL);
    jogador->tempoAreas[salaAtual] = termino - comeco;
    for (int i = 0; i < 6; i++) {
      jogador->tempoTotal += jogador->tempoAreas[i];
    }

  } else {
    printarMapa(6);
    printf("\nVOCE ESTA NA AREA CENTRAL!!!");
    time_t inicioCentral = time(NULL);
    caminhoAreaCentral(0, aux, jogador);
    time_t fimCentral = time(NULL);
    jogador->tempoAC = fimCentral - inicioCentral;
    jogador->tempoTotal += jogador->tempoAC;
  }

  free(aux);
  if (contador < 6)
    printf("PARABENS! VOCE AVANCOU PARA A PROXIMA AREA!\n");
}

void inicializaRanking(Jogador *vetorJogadores) {
  FILE *arquivo;
  Jogador novoJogador;

  arquivo = fopen("ranking.txt", "r");
  if (arquivo == NULL) {
    printf("ERRO DE ABERTURA NO ARQUIVO\n");
    return;
  }

  while (fscanf(arquivo, "%s %lf %lf %lf %lf %lf %lf %lf %d", novoJogador.nome,
                &novoJogador.tempoAreas[0], &novoJogador.tempoAreas[1],
                &novoJogador.tempoAreas[2], &novoJogador.tempoAreas[3],
                &novoJogador.tempoAreas[4], &novoJogador.tempoAreas[5],
                &novoJogador.tempoTotal, &novoJogador.pontuacao) == 9) {
    adicionarJogador(novoJogador, vetorJogadores);
  }

  fclose(arquivo);
}

void lerArquivo(Jogador *vetorJogadores) {
  FILE *arqRanking = fopen("ranking.txt", "r");
  int i = 0;
  if (arqRanking == NULL) {
    printf("ERRO! O arquivo não foi aberto!\n");
  }

  while (
      fscanf(arqRanking,
             "%[^;];%d;%lf;%lf;%lf;%lf;%lf;%lf;%lf;%*c",
             vetorJogadores[i].nome, &vetorJogadores[i].pontuacao,
             &vetorJogadores[i].tempoTotal, &vetorJogadores[i].tempoAreas[0],
             &vetorJogadores[i].tempoAreas[1], &vetorJogadores[i].tempoAreas[2],
             &vetorJogadores[i].tempoAreas[3], &vetorJogadores[i].tempoAreas[4],
             &vetorJogadores[i].tempoAreas[5]) != EOF) {
    i++;
  }
  fclose(arqRanking);
}

int qtdJogadores(Jogador *vetor){
  int i, qtd = 0;
  for(i = 0; i < 10 ;i++){
    if(strcmp(vetor[i].nome, "SEM REGISTRO") != 0)
      qtd++;
  }
  return qtd;
}
