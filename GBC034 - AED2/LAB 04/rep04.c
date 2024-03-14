#include <stdio.h>
#include <stdlib.h>
#include <time.h>

void troca(int v[], int pivo, int i) {
    int temp = v[pivo];
    v[pivo] = v[i];
    v[i] = temp;
}

int particao(int v[], int esq, int dir) {
    int i, pivo;
    pivo = esq;
    for (i = esq + 1; i <= dir; i++) {
        if (v[i] < v[esq]) {
            pivo = pivo + 1;
            troca(v, pivo, i);
        }
    }
    troca(v, esq, pivo);
    return pivo;
}

void qsBasico(int v[], int esq, int dir) {
    int i;
    if (esq >= dir) return;
    i = particao(v, esq, dir);
    qsBasico(v, esq, i - 1);
    qsBasico(v, i + 1, dir);
}

int pivo_aleatorio(int esq, int dir) {
    double r;
    r = (double) rand() / RAND_MAX;
    return (int) (esq + r * (dir - esq));
}

void qsAleatorizado(int v[], int esq, int dir) {
    int i;
    if (dir <= esq) return;
    troca(v, pivo_aleatorio(esq, dir), esq);
    i = particao(v, esq, dir);
    qsAleatorizado(v, esq, i - 1);
    qsAleatorizado(v, i + 1, dir);
}

void qsMedianaTres(int v[], int esq, int dir) {
    int i;
    if (dir <= esq) return;
    troca(v, (esq + dir) / 2, esq + 1);
    if (v[esq] > v[esq + 1]) troca(v, esq, esq + 1);
    if (v[esq] > v[dir]) troca(v, esq, dir);
    if (v[esq + 1] > v[dir]) troca(v, esq + 1, dir);
    i = particao(v, esq + 1, dir - 1);
    qsMedianaTres(v, esq, i - 1);
    qsMedianaTres(v, i + 1, dir);
}

void qsParticaoTres(int a[], int l, int r) {
    int k, i = l - 1, j = r, p = l - 1, q = r;
    int v = a[r];
    if (r <= l) return;
    for (;;) {
        while(a[++i] < v) ;
        while(v < a[--j])
            if (j == l) break;
        if (i >= j) break;
        troca(a, i, j);
        if (a[i] == v) {
            p++;
            troca(a, p, i);
        }
        if (v == a[j]) {
            q--;
            troca(a, j, q);
        }
    }
    troca(a, i, r);
    j = i - 1;
    i = i + 1;
    for (k = l; k <= p; k++, j--) troca(a, k, j);
    for (k = r - 1; k >= q; k--, i++) troca(a, i, k);
    qsParticaoTres(a, l, j);
    qsParticaoTres(a, i, r);
}

int main ( ) {
    int tam, num, i, j;
    double inicio, fim, tempo;

    srand(time(NULL));
    tam = 5000;

    // alocando memória para os vetores
    int *v1 = (int *) malloc (tam * sizeof(int));
    int *v2 = (int *) malloc (tam * sizeof(int));
    int *v3 = (int *) malloc (tam * sizeof(int));
    int *v4 = (int *) malloc (tam * sizeof(int));
    int *aux = (int *) malloc (tam * sizeof(int));

    // inicializando os valores aleatórios
    for (i = 0; i < tam; i++) aux[i] = rand() % tam + 1;

    // comparando
    printf ("[ Vetores dinamicos com 5000 posicoes ]\n");
    printf ("\na) Sequencia aleatoria");

    // inicializando os vetores com os valores aleatórios
    for (i = 0; i < tam; i++) {
        v1[i] = aux[i];
        v2[i] = aux[i];
        v3[i] = aux[i];
        v4[i] = aux[i];
    }

    inicio = clock();
    qsBasico(v1, 0, tam - 1);
    fim = clock();
    tempo = (fim - inicio) / CLOCKS_PER_SEC;
    printf ("\nQuickSort Basico: %lf", tempo);

    inicio = clock();
    qsAleatorizado(v2, 0, tam - 1);
    fim = clock();
    tempo = (fim - inicio) / CLOCKS_PER_SEC;
    printf ("\nQuickSort Aleatorizado: %lf", tempo);

    inicio = clock();
    qsMedianaTres(v3, 0, tam - 1);
    fim = clock();
    tempo = (fim - inicio) / CLOCKS_PER_SEC;
    printf ("\nQuickSort com Mediana de Tres: %lf", tempo);

    inicio = clock();
    qsParticaoTres(v4, 0, tam - 1);
    fim = clock();
    tempo = (fim - inicio) / CLOCKS_PER_SEC;     
    printf ("\nQuickSort com Particao de Tres Vias: %lf\n", tempo);           

    printf ("\nb) Sequencia ordenada");

    // utilizando os vetores ordenados acima

    inicio = clock();
    qsBasico(v1, 0, tam - 1);
    fim = clock();
    tempo = (fim - inicio) / CLOCKS_PER_SEC;
    printf ("\nQuickSort Basico: %lf", tempo);

    inicio = clock();
    qsAleatorizado(v2, 0, tam - 1);
    fim = clock();
    tempo = (fim - inicio) / CLOCKS_PER_SEC;
    printf ("\nQuickSort Aleatorizado: %lf", tempo);

    inicio = clock();
    qsMedianaTres(v3, 0, tam - 1);
    fim = clock();
    tempo = (fim - inicio) / CLOCKS_PER_SEC;
    printf ("\nQuickSort com Mediana de Tres: %lf", tempo);

    inicio = clock();
    qsParticaoTres(v4, 0, tam - 1);
    fim = clock();
    tempo = (fim - inicio) / CLOCKS_PER_SEC;     
    printf ("\nQuickSort com Particao de Tres Vias: %lf\n", tempo);

    printf ("\nc) Sequencia invertida");

    // invertendo os valores ordenados
    for (i = 0; i < tam; i++) aux[i] = v1[i];

    for (i = 0, j = tam - 1; i < tam / 2; i++, j--) {
        num = aux[j];
        aux[j] = aux[i];
        aux[i] = num;
    }

    // inicializando os vetores com os valores invertidos
    for (i = 0; i < tam; i++) {
        v1[i] = aux[i];
        v2[i] = aux[i];
        v3[i] = aux[i];
        v4[i] = aux[i];
    }

    inicio = clock();
    qsBasico(v1, 0, tam - 1);
    fim = clock();
    tempo = (fim - inicio) / CLOCKS_PER_SEC;
    printf ("\nQuickSort Basico: %lf", tempo);

    inicio = clock();
    qsAleatorizado(v2, 0, tam - 1);
    fim = clock();
    tempo = (fim - inicio) / CLOCKS_PER_SEC;
    printf ("\nQuickSort Aleatorizado: %lf", tempo);

    inicio = clock();
    qsMedianaTres(v3, 0, tam - 1);
    fim = clock();
    tempo = (fim - inicio) / CLOCKS_PER_SEC;
    printf ("\nQuickSort com Mediana de Tres: %lf", tempo);

    inicio = clock();
    qsParticaoTres(v4, 0, tam - 1);
    fim = clock();
    tempo = (fim - inicio) / CLOCKS_PER_SEC;     
    printf ("\nQuickSort com Particao de Tres Vias: %lf\n", tempo);

    printf ("\nd) Sequencia com muitas repeticoes");

    // aumentando o número de repetições dos valores aleatórios
    for (i = 0; i < tam; i++) aux[i] = rand() % (tam / 5) + 1;

    // inicializando os vetores com os valores aleatórios
    for (i = 0; i < tam; i++) {
        v1[i] = aux[i];
        v2[i] = aux[i];
        v3[i] = aux[i];
        v4[i] = aux[i];
    }

    inicio = clock();
    qsBasico(v1, 0, tam - 1);
    fim = clock();
    tempo = (fim - inicio) / CLOCKS_PER_SEC;
    printf ("\nQuickSort Basico: %lf", tempo);

    inicio = clock();
    qsAleatorizado(v2, 0, tam - 1);
    fim = clock();
    tempo = (fim - inicio) / CLOCKS_PER_SEC;
    printf ("\nQuickSort Aleatorizado: %lf", tempo);

    inicio = clock();
    qsMedianaTres(v3, 0, tam - 1);
    fim = clock();
    tempo = (fim - inicio) / CLOCKS_PER_SEC;
    printf ("\nQuickSort com Mediana de Tres: %lf", tempo);

    inicio = clock();
    qsParticaoTres(v4, 0, tam - 1);
    fim = clock();
    tempo = (fim - inicio) / CLOCKS_PER_SEC;     
    printf ("\nQuickSort com Particao de Tres Vias: %lf\n\n", tempo);

    // realocando memória para os vetores
    tam = 50000;

    v1 = (int *)  realloc (v1, tam * sizeof(int));
    v2 = (int *)  realloc (v2, tam * sizeof(int));
    v3 = (int *)  realloc (v3, tam * sizeof(int));
    v4 = (int *)  realloc (v4, tam * sizeof(int));
    aux = (int *) realloc (aux, tam * sizeof(int));

    // inicializando os valores aleatórios
    for (i = 0; i < tam; i++) aux[i] = rand() % tam + 1;

    // comparando
    printf ("\n[ Vetores dinamicos com 50000 posicoes ]\n");
    printf ("\na) Sequencia aleatoria");

    // inicializando os vetores com os valores aleatórios
    for (i = 0; i < tam; i++) {
        v1[i] = aux[i];
        v2[i] = aux[i];
        v3[i] = aux[i];
        v4[i] = aux[i];
    }

    inicio = clock();
    qsBasico(v1, 0, tam - 1);
    fim = clock();
    tempo = (fim - inicio) / CLOCKS_PER_SEC;
    printf ("\nQuickSort Basico: %lf", tempo);

    inicio = clock();
    qsAleatorizado(v2, 0, tam - 1);
    fim = clock();
    tempo = (fim - inicio) / CLOCKS_PER_SEC;
    printf ("\nQuickSort Aleatorizado: %lf", tempo);

    inicio = clock();
    qsMedianaTres(v3, 0, tam - 1);
    fim = clock();
    tempo = (fim - inicio) / CLOCKS_PER_SEC;
    printf ("\nQuickSort com Mediana de Tres: %lf", tempo);

    inicio = clock();
    qsParticaoTres(v4, 0, tam - 1);
    fim = clock();
    tempo = (fim - inicio) / CLOCKS_PER_SEC;     
    printf ("\nQuickSort com Particao de Tres Vias: %lf\n", tempo);           

    printf ("\nb) Sequencia ordenada");

    // ordenando os valores aleatórios
    for (i = 0; i < tam; i++) {
        for (j = i; j < tam - 1; j++) {
            if (aux[j] < aux[j + 1]) {
                num = aux[j];
                aux[j] = aux[j + 1];
                aux[j + 1] = num;
            }
        }
    }

    // inicializando os vetores com os valores ordenados
    for (i = 0; i < tam; i++) {
        v1[i] = aux[i];
        v2[i] = aux[i];
        v3[i] = aux[i];
        v4[i] = aux[i];
    }

    inicio = clock();
    qsBasico(v1, 0, tam - 1);
    fim = clock();
    tempo = (fim - inicio) / CLOCKS_PER_SEC;
    printf ("\nQuickSort Basico: %lf", tempo);

    inicio = clock();
    qsAleatorizado(v2, 0, tam - 1);
    fim = clock();
    tempo = (fim - inicio) / CLOCKS_PER_SEC;
    printf ("\nQuickSort Aleatorizado: %lf", tempo);

    inicio = clock();
    qsMedianaTres(v3, 0, tam - 1);
    fim = clock();
    tempo = (fim - inicio) / CLOCKS_PER_SEC;
    printf ("\nQuickSort com Mediana de Tres: %lf", tempo);

    inicio = clock();
    qsParticaoTres(v4, 0, tam - 1);
    fim = clock();
    tempo = (fim - inicio) / CLOCKS_PER_SEC;     
    printf ("\nQuickSort com Particao de Tres Vias: %lf\n", tempo);

    printf ("\nc) Sequencia invertida");

    // invertendo os valores ordenados
    for (i = 0, j = tam - 1; i < tam / 2; i++, j--) {
        num = aux[j];
        aux[j] = aux[i];
        aux[i] = num;
    }

    // inicializando os vetores com os valores invertidos
    for (i = 0; i < tam; i++) {
        v1[i] = aux[i];
        v2[i] = aux[i];
        v3[i] = aux[i];
        v4[i] = aux[i];
    }

    inicio = clock();
    qsBasico(v1, 0, tam - 1);
    fim = clock();
    tempo = (fim - inicio) / CLOCKS_PER_SEC;
    printf ("\nQuickSort Basico: %lf", tempo);

    inicio = clock();
    qsAleatorizado(v2, 0, tam - 1);
    fim = clock();
    tempo = (fim - inicio) / CLOCKS_PER_SEC;
    printf ("\nQuickSort Aleatorizado: %lf", tempo);

    inicio = clock();
    qsMedianaTres(v3, 0, tam - 1);
    fim = clock();
    tempo = (fim - inicio) / CLOCKS_PER_SEC;
    printf ("\nQuickSort com Mediana de Tres: %lf", tempo);

    inicio = clock();
    qsParticaoTres(v4, 0, tam - 1);
    fim = clock();
    tempo = (fim - inicio) / CLOCKS_PER_SEC;     
    printf ("\nQuickSort com Particao de Tres Vias: %lf\n", tempo);

    printf ("\nd) Sequencia com muitas repeticoes");

    // aumentando o número de repetições dos valores aleatórios
    for (i = 0; i < tam; i++) aux[i] = rand() % (tam / 5) + 1;

    // inicializando os vetores com os valores aleatórios
    for (i = 0; i < tam; i++) {
        v1[i] = aux[i];
        v2[i] = aux[i];
        v3[i] = aux[i];
        v4[i] = aux[i];
    }

    inicio = clock();
    qsBasico(v1, 0, tam - 1);
    fim = clock();
    tempo = (fim - inicio) / CLOCKS_PER_SEC;
    printf ("\nQuickSort Basico: %lf", tempo);

    inicio = clock();
    qsAleatorizado(v2, 0, tam - 1);
    fim = clock();
    tempo = (fim - inicio) / CLOCKS_PER_SEC;
    printf ("\nQuickSort Aleatorizado: %lf", tempo);

    inicio = clock();
    qsMedianaTres(v3, 0, tam - 1);
    fim = clock();
    tempo = (fim - inicio) / CLOCKS_PER_SEC;
    printf ("\nQuickSort com Mediana de Tres: %lf", tempo);

    inicio = clock();
    qsParticaoTres(v4, 0, tam - 1);
    fim = clock();
    tempo = (fim - inicio) / CLOCKS_PER_SEC;     
    printf ("\nQuickSort com Particao de Tres Vias: %lf", tempo);

    free (v1);
    free (v2);
    free (v3);
    free (v4);
    free (aux);

    return 0;
}
