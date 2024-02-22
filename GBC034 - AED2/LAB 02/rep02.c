// NOME: AMANDA DUARTE GARCIA
// MATRÍCULA: 12221BCC031

// OBS: TABELA ESTÁ NA PASTA DO CÓDIGO

#include <stdio.h>
#include <stdlib.h>
#include <time.h>

void bubbleSort (int vetor[], int n, int *comp, int *troca) {
    int temp, i, j;
    *comp = 0;
    *troca = 0;
    for (i = 0; i < n; i++) {
        for (j = 0; j < n; j++) {
            if (vetor[j + 1] < vetor[j]) {
                temp = vetor[j];
                vetor[j] = vetor[j + 1];
                vetor[j + 1] = temp;
                (*troca)++;
            }
            (*comp)++;
        }
    }
}

void shellSort (int vetor[], int n, int *comp, int *troca) {
    int i, j, h = 1, aux;
    *comp = 0;
    *troca = 0;
    do {
        h = h * 3 + 1;
    } while (h < n);
    do {
        h /= 3;
        for (i = h; i < n; i++) {
            aux = vetor[i];
            j = i;
            while (vetor[j - h] > aux) {
                (*comp)++;
                vetor[j] = vetor[j - h];
                j -= h;
                if (j < h) break;
            }
            vetor[j] = aux;
            (*troca)++;
        }
    } while (h != 1);
}

void merge (int vetor[], int aux[], int esq, int meio, int dir, int *comp, int *troca) {
    int i, eqs_fim, n;
    eqs_fim = meio - 1;
    i = esq;
    n = dir - esq + 1;
    while (esq <= eqs_fim && meio <= dir) {
        if (vetor[esq] <= vetor[meio]) aux[i++] = vetor[esq++];
        else aux[i++] = vetor[meio++];
        (*comp)++;
    }
    while (esq <= eqs_fim) aux[i++] = vetor[esq++];
    while (meio <= dir) aux[i++] = vetor[meio++];
    for (i = 0; i < n; i++) {
        vetor[dir] = aux[dir];
        dir--;
        (*troca)++;
    }
}

void m_sort (int vetor[], int aux[], int esq, int dir, int *comp, int *troca) {
    int meio;
    if (dir > esq) {
        meio = (dir + esq) / 2;
        m_sort (vetor, aux, esq, meio, comp, troca);
        m_sort (vetor, aux, meio + 1, dir, comp, troca);
        merge (vetor, aux, esq, meio + 1, dir, comp, troca);
    }
}

void mergeSort (int vetor[], int n, int *comp, int *troca) {
    int aux[n];
    *comp = 0;
    *troca = 0;
    m_sort (vetor, aux, 0, n - 1, comp, troca);
}

void abcSort (int vetor[], int i, int j) {
    int temp;
    if (vetor[i] > vetor[j]) {
        temp = vetor[i];
        vetor[i] = vetor[j];
        vetor[j] = temp;
    }
    if (i + 1 >= j) return;
    int k = (j - 1 + 1) / 3;
    abcSort (vetor, i, j - k);
    abcSort (vetor, i + k, j);
    abcSort (vetor, i, j - k);
}

int main ( ) {
    int i, comparacao, mediac, troca, mediat;
    double inicio, fim, tempo;
    srand(time(NULL));

    printf ("[TESTE 1] vetor estatico aleatorio com 10000 posicoes");

    // criando e atribuindo o vetor aleatório
    int vet[10000], aux[10000];
    for (i = 0; i < 10000; i++) {
        aux[i] = rand() % 500 + 1;
        vet[i] = aux[i];
    }

    // teste com bubblesort
    inicio = clock();
    bubbleSort (vet, 10000, &comparacao, &troca);
    fim = clock();
    tempo = (fim - inicio) / CLOCKS_PER_SEC;
    printf ("\ntempo BubbleSort: %lf", tempo);

    // reiniciando o vetor aleatório
    for (i = 0; i < 10000; i++) {
        vet[i] = aux[i];
    }

    // teste com shellsort
    inicio = clock();
    shellSort (vet, 10000, &comparacao, &troca);
    fim = clock();
    tempo = (fim - inicio) / CLOCKS_PER_SEC;
    printf ("\ntempo ShellSort: %lf", tempo);

    // reiniciando o vetor aleatório
    for (i = 0; i < 10000; i++) {
        vet[i] = aux[i];
    }

    // teste com mergesort
    inicio = clock();
    mergeSort (vet, 10000, &comparacao, &troca);
    fim = clock();
    tempo = (fim - inicio) / CLOCKS_PER_SEC;
    printf ("\ntempo MergeSort: %lf", tempo);

    printf ("\n\n[TESTE 2] vetor dinamico aleatorio com 10000 posicoes");

    //criando e atribuindo o vetor aleatório dinâmico
    int *v = (int *) malloc (10000 * sizeof(int));
    int *a = (int *) malloc (10000 * sizeof(int));
    for (i = 0; i < 10000; i++) {
        a[i] = rand() % 500 + 1;
        v[i] = a[i];
    }

    // teste com bubblesort
    inicio = clock();
    bubbleSort (v, 10000, &comparacao, &troca);
    fim = clock();
    tempo = (fim - inicio) / CLOCKS_PER_SEC;
    printf ("\ntempo BubbleSort: %lf", tempo);

    // reiniciando o vetor aleatório
    for (i = 0; i < 10000; i++) {
        v[i] = a[i];
    }

    // teste com shellsort
    inicio = clock();
    shellSort (v, 10000, &comparacao, &troca);
    fim = clock();
    tempo = (fim - inicio) / CLOCKS_PER_SEC;
    printf ("\ntempo ShellSort: %lf", tempo);

    // reiniciando o vetor aleatório
    for (i = 0; i < 10000; i++) {
        v[i] = a[i];
    }

    // teste com mergesort
    inicio = clock();
    mergeSort (v, 10000, &comparacao, &troca);
    fim = clock();
    tempo = (fim - inicio) / CLOCKS_PER_SEC;
    printf ("\ntempo MergeSort: %lf", tempo);

    printf ("\n\n[TESTE 3] vetor dinamico aleatorio com 50000 posicoes");

    // realocando e atribuindo o vetor aleatório dinâmico
    v = (int *) realloc (v, 50000 * sizeof(int));
    a = (int *) realloc (a, 50000 * sizeof(int));
    for (i = 0; i < 50000; i++) {
        a[i] = rand() % 500 + 1;
        v[i] = a[i];
    }

    // teste com bubblesort
    inicio = clock();
    bubbleSort (v, 50000, &comparacao, &troca);
    fim = clock();
    tempo = (fim - inicio) / CLOCKS_PER_SEC;
    printf ("\ntempo BubbleSort: %lf", tempo);

    // reiniciando o vetor aleatório
    for (i = 0; i < 50000; i++) {
        v[i] = a[i];
    }

    // teste com shellsort
    inicio = clock();
    shellSort (v, 50000, &comparacao, &troca);
    fim = clock();
    tempo = (fim - inicio) / CLOCKS_PER_SEC;
    printf ("\ntempo ShellSort: %lf", tempo);

    // reiniciando o vetor aleatório
    for (i = 0; i < 50000; i++) {
        v[i] = a[i];
    }

    // teste com mergesort
    inicio = clock();
    mergeSort (v, 50000, &comparacao, &troca);
    fim = clock();
    tempo = (fim - inicio) / CLOCKS_PER_SEC;
    printf ("\ntempo MergeSort: %lf", tempo);

    printf ("\n\n[TESTE 4] vetor dinamico aleatorio com 100000 posicoes");

    // realocando e atribuindo o vetor aleatório dinâmico
    v = (int *) realloc (v, 100000 * sizeof(int));
    a = (int *) realloc (a, 100000 * sizeof(int));
    for (i = 0; i < 100000; i++) {
        a[i] = rand() % 500 + 1;
        v[i] = a[i];
    }

    // teste com bubblesort
    inicio = clock();
    bubbleSort (v, 100000, &comparacao, &troca);
    fim = clock();
    tempo = (fim - inicio) / CLOCKS_PER_SEC;
    printf ("\ntempo BubbleSort: %lf", tempo);

    // reiniciando o vetor aleatório
    for (i = 0; i < 100000; i++) {
        v[i] = a[i];
    }

    // teste com shellsort
    inicio = clock();
    shellSort (v, 100000, &comparacao, &troca);
    fim = clock();
    tempo = (fim - inicio) / CLOCKS_PER_SEC;
    printf ("\ntempo ShellSort: %lf", tempo);

    // reiniciando o vetor aleatório
    for (i = 0; i < 100000; i++) {
        v[i] = a[i];
    }

    // teste com mergesort
    inicio = clock();
    mergeSort (v, 100000, &comparacao, &troca);
    fim = clock();
    tempo = (fim - inicio) / CLOCKS_PER_SEC;
    printf ("\ntempo MergeSort: %lf", tempo);

    free (v);
    free (a);

    printf ("\n\n[TESTE 5] ABC-Sort");

    // criando e atribuindo os vetores aleatórios dinâmicos
    int *va = (int *) malloc (10000 * sizeof(int));
    int *vb = (int *) malloc (10000 * sizeof(int));
    int *vc = (int *) malloc (10000 * sizeof(int));

    for (i = 0; i < 10000; i++) va[i] = rand() % 500 + 1;
    for (i = 0; i < 50000; i++) vb[i] = rand() % 500 + 1;
    for (i = 0; i < 100000; i++) vc[i] = rand() % 500 + 1;

    // testes com abcsort
    inicio = clock();
    abcSort (va, 10000, 10000 - 1);
    fim = clock();
    tempo = (fim - inicio) / CLOCKS_PER_SEC;
    printf ("\nvetor de 10000 posicoes: %lf", tempo);

    inicio = clock();
    abcSort (vb, 50000, 50000 - 1);
    fim = clock();
    tempo = (fim - inicio) / CLOCKS_PER_SEC;
    printf ("\nvetor de 50000 posicoes: %lf", tempo);

    inicio = clock();
    abcSort (vc, 100000, 100000 - 1);
    fim = clock();
    tempo = (fim - inicio) / CLOCKS_PER_SEC;
    printf ("\nvetor de 100000 posicoes: %lf", tempo);

    free (va);
    free (vb);
    free (vc);

    printf ("\n\n[TESTE 6] numero medio de comparacoes e de trocas");

    // criando os vetores aleatórios dinâmicos;
    int *v1 = (int *) malloc (10000 * sizeof(int));
    int *v2 = (int *) malloc (10000 * sizeof(int));
    int *v3 = (int *) malloc (10000 * sizeof(int));
    int *v4 = (int *) malloc (10000 * sizeof(int));
    int *v5 = (int *) malloc (10000 * sizeof(int));
    int *v6 = (int *) malloc (10000 * sizeof(int));
    int *v7 = (int *) malloc (10000 * sizeof(int));
    int *v8 = (int *) malloc (10000 * sizeof(int));
    int *v9 = (int *) malloc (10000 * sizeof(int));
    int *v10 = (int *) malloc (10000 * sizeof(int));
    int *vaux = (int *) malloc (10000 * sizeof(int));

    for (i = 0; i < 10000; i++) {
        vaux[i] = rand() % 500 + 1;
        v1[i] = vaux[i];
        v2[i] = vaux[i];
        v3[i] = vaux[i];
        v4[i] = vaux[i];
        v5[i] = vaux[i];
        v6[i] = vaux[i];
        v7[i] = vaux[i];
        v8[i] = vaux[i];
        v9[i] = vaux[i];
        v10[i] = vaux[i];
    }

    // calculando as médias do bubblesort
    mediac = 0;
    mediat = 0;

    bubbleSort (v1, 10000, &comparacao, &troca);
    mediac += comparacao;
    mediat += troca;
    bubbleSort (v2, 10000, &comparacao, &troca);
    mediac += comparacao;
    mediat += troca;
    bubbleSort (v3, 10000, &comparacao, &troca);
    mediac += comparacao;
    mediat += troca;
    bubbleSort (v4, 10000, &comparacao, &troca);
    mediac += comparacao;
    mediat += troca;
    bubbleSort (v5, 10000, &comparacao, &troca);
    mediac += comparacao;
    mediat += troca;
    bubbleSort (v6, 10000, &comparacao, &troca);
    mediac += comparacao;
    mediat += troca;
    bubbleSort (v7, 10000, &comparacao, &troca);
    mediac += comparacao;
    mediat += troca;
    bubbleSort (v8, 10000, &comparacao, &troca);
    mediac += comparacao;
    mediat += troca;
    bubbleSort (v9, 10000, &comparacao, &troca);
    mediac += comparacao;
    mediat += troca;
    bubbleSort (v10, 10000, &comparacao, &troca);
    mediac += comparacao;
    mediat += troca;

    mediac /= 10;
    mediat /= 10;

    printf ("\nBubbleSort: %d comparacoes, %d trocas", mediac, mediat);

    // reiniciando os vetores aleatórios
    for (i = 0; i < 10000; i++) {
        v1[i] = vaux[i];
        v2[i] = vaux[i];
        v3[i] = vaux[i];
        v4[i] = vaux[i];
        v5[i] = vaux[i];
        v6[i] = vaux[i];
        v7[i] = vaux[i];
        v8[i] = vaux[i];
        v9[i] = vaux[i];
        v10[i] = vaux[i];
    }

    // calculando as médias do shellsort
    mediac = 0;
    mediat = 0;

    shellSort (v1, 10000, &comparacao, &troca);
    mediac += comparacao;
    mediat += troca;
    shellSort (v2, 10000, &comparacao, &troca);
    mediac += comparacao;
    mediat += troca;
    shellSort (v3, 10000, &comparacao, &troca);
    mediac += comparacao;
    mediat += troca;
    shellSort (v4, 10000, &comparacao, &troca);
    mediac += comparacao;
    mediat += troca;
    shellSort (v5, 10000, &comparacao, &troca);
    mediac += comparacao;
    mediat += troca;
    shellSort (v6, 10000, &comparacao, &troca);
    mediac += comparacao;
    mediat += troca;
    shellSort (v7, 10000, &comparacao, &troca);
    mediac += comparacao;
    mediat += troca;
    shellSort (v8, 10000, &comparacao, &troca);
    mediac += comparacao;
    mediat += troca;
    shellSort (v9, 10000, &comparacao, &troca);
    mediac += comparacao;
    mediat += troca;
    shellSort (v10, 10000, &comparacao, &troca);
    mediac += comparacao;
    mediat += troca;

    mediac /= 10;
    mediat /= 10;

    printf ("\nShellSort: %d comparacoes, %d trocas", mediac, mediat);

    // reiniciando os vetores aleatórios
    for (i = 0; i < 10000; i++) {
        v1[i] = vaux[i];
        v2[i] = vaux[i];
        v3[i] = vaux[i];
        v4[i] = vaux[i];
        v5[i] = vaux[i];
        v6[i] = vaux[i];
        v7[i] = vaux[i];
        v8[i] = vaux[i];
        v9[i] = vaux[i];
        v10[i] = vaux[i];
    }

    // calculando as médias do mergesort
    mediac = 0;
    mediat = 0;

    mergeSort (v1, 10000, &comparacao, &troca);
    mediac += comparacao;
    mediat += troca;
    mergeSort (v2, 10000, &comparacao, &troca);
    mediac += comparacao;
    mediat += troca;
    mergeSort (v3, 10000, &comparacao, &troca);
    mediac += comparacao;
    mediat += troca;
    mergeSort (v4, 10000, &comparacao, &troca);
    mediac += comparacao;
    mediat += troca;
    mergeSort (v5, 10000, &comparacao, &troca);
    mediac += comparacao;
    mediat += troca;
    mergeSort (v6, 10000, &comparacao, &troca);
    mediac += comparacao;
    mediat += troca;
    mergeSort (v7, 10000, &comparacao, &troca);
    mediac += comparacao;
    mediat += troca;
    mergeSort (v8, 10000, &comparacao, &troca);
    mediac += comparacao;
    mediat += troca;
    mergeSort (v9, 10000, &comparacao, &troca);
    mediac += comparacao;
    mediat += troca;
    mergeSort (v10, 10000, &comparacao, &troca);
    mediac += comparacao;
    mediat += troca;

    mediac /= 10;
    mediat /= 10;

    printf ("\nMergeSort: %d comparacoes, %d trocas", mediac, mediat);

    free (v1);
    free (v2);
    free (v3);
    free (v4);
    free (v5);
    free (v6);
    free (v7);
    free (v8);
    free (v9);
    free (v10);
    free (vaux);

    return 0;  
}
