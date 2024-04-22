#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define N 127

typedef struct aluno {
  int mat;
  char nome[20];
  float nota;
} aluno;

typedef aluno *hash[N];

int funcHash(int mat) { return (mat % N); }

aluno *hashInsere(hash tab, int mat, char *nome, float nota) {
  int h = funcHash(mat);
  while (tab[h] != NULL) {
    if (tab[h]->mat == mat)
      break;
    h = (h + 1) % N;
  }
  if (tab[h] == NULL) {
    tab[h] = (aluno *)malloc(sizeof(aluno));
    tab[h]->mat = mat;
  }
  strcpy(tab[h]->nome, nome);
  tab[h]->nota = nota;
  return tab[h];
}

aluno *hashBusca(hash tab, int mat) {
  int h = funcHash(mat);
  while (tab[h] != NULL) {
    if (tab[h]->mat == mat) {
      return tab[h];
    }
    h = (h + 1) % N;
  }
  return NULL;
}

int main() {
  hash tab;
  for (int i = 0; i < N; i++) {
    tab[i] = NULL;
  }

  hashInsere(tab, 123, "Joao", 7.5);
  hashInsere(tab, 456, "Maria", 8.0);
  hashInsere(tab, 789, "Ana", 6.0);

  int matricula = 456;
  aluno *busca = hashBusca(tab, matricula);
  if (busca != NULL) {
    printf("Aluno encontrado:\nMatricula: %d, Nome: %s, Nota: %.2f\n",
           busca->mat, busca->nome, busca->nota);
  } else {
    printf("Aluno com matricula %d nao encontrado.\n", matricula);
  }

  return 0;
}
