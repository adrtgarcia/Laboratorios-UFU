#include <stdio.h>
#include <stdlib.h>
#include <time.h>

void bubbleSort(int vetor[], int tam) {
    int temp, i, j;
    for (i = 0; i < tam; i++) {
        for (j = 0; j < tam - 1 - i; j++) {
            if (vetor[j + 1] < vetor[j]) {
                temp = vetor[j];
                vetor[j] = vetor[j + 1];
                vetor[j + 1] = temp;
            }
        }
    }
}

void selectionSort(int vetor[], int n) {
    int temp, menor, i, j;
    for (i = 0; i < n - 1; i++) {
        menor = i;
        for (j = i + 1; j < n; j++) {
        if (vetor[j] < vetor[menor]) {
            menor = j;
            }
        }
        temp = vetor[i];
        vetor[i] = vetor[menor];
        vetor[menor] = temp;
    }
}

void insertionSort(int vetor[], int n) {
    int i, j, temp;
    for (i = 1; i < n; i++) {
        temp = vetor[i];
        for (j = i - 1; j >= 0 && vetor[j] > temp; j--) {
            vetor[j + 1] = vetor[j];
        }
        vetor[j + 1] = temp;
    }
}

void shellSort(int vetor[], int n) {
    int i, j, h = 1, aux;
    do {
        h = h * 3 + 1;
    } while (h < n);
    do {
        h /= 3;
        for (i = h; i < n; i++) {
        aux = vetor[i];
        j = i;
        while (vetor[j - h] > aux) {
            vetor[j] = vetor[j - h];
            j -= h;
            if (j < h)
            break;
        }
        vetor[j] = aux;
        }
    } while (h != 1);
}

int main ( ) 
{
    int i;
    int vet[10000], aux[10000];
    srand(time(NULL));

    // gerando vetor aleatório
    for (i = 0; i < 10000; i++) {
        aux[i] = rand() % 10000 + 1;
        vet[i] = aux[i];
    }

    // ordenando com bubblesort
    double ini = clock();
    bubbleSort(vet, 10000);
    double fim = clock();
    double tempo = (fim - ini) / CLOCKS_PER_SEC;

    printf ("\ntempo BubbleSort: %lf", tempo);

    // reiniciando vetor aleatório
    for (i = 0; i < 10000; i++) {
        vet[i] = aux[i];
    }

    // ordenando com selectionsort
    ini = clock();
    selectionSort(vet, 10000);
    fim = clock();
    tempo = (fim - ini) / CLOCKS_PER_SEC;

    printf ("\ntempo SelectionSort: %lf", tempo);

    // reiniciando vetor aleatório
    for (i = 0; i < 10000; i++) {
        vet[i] = aux[i];
    }

    // ordenando com insertionsort
    ini = clock();
    insertionSort(vet, 10000);
    fim = clock();
    tempo = (fim - ini) / CLOCKS_PER_SEC;

    printf ("\ntempo InsertionSort: %lf", tempo);

    // reiniciando vetor aleatório
    for (i = 0; i < 10000; i++) {
        vet[i] = aux[i];
    }

    // ordenando com shellsort
    ini = clock();
    shellSort(vet, 10000);
    fim = clock();
    tempo = (fim - ini) / CLOCKS_PER_SEC;

    printf ("\ntempo ShellSort: %lf", tempo);

    // considerando alocação dinâmica
    int *v = malloc (10000 * sizeof(int));

    // atribuindo valores aleatórios, vetor com 10000 posições
    srand (time(NULL));
    for (i = 0; i < 10000; i++)
    {
        v[i] = rand() % 10000 + 1;
    }

    // organizando e calculando tempo de execução
    ini = clock();
    bubbleSort (v, 10000);
    fim = clock();
    tempo = (fim - ini) / CLOCKS_PER_SEC;
    printf ("\n\n\ntempo (alocacao dinamica + BubbleSort): %lf", tempo);

    printf ("\nvetor organizado: ");
    for (i = 0; i < 10000; i++)
    {
        printf (" %d ", v[i]);
    }

    return 0;
}
