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

int main ( )
{
    // considerando alocação dinâmica
    int *v = malloc (10000 * sizeof(int));

    // atribuindo valores aleatórios, vetor com 10000 posições
    srand (time(NULL));
    for (i = 0; i < 10000; i++)
    {
        v[i] = rand() % 10000 + 1;
    }

    // organizando e calculando tempo de execução
    double ini = clock();
    bubbleSort (v, 10000);
    double fim = clock();
    double tempo = (fim - ini) / CLOCKS_PER_SEC;
    printf ("\n\n\ntempo (alocacao dinamica + BubbleSort): %lf", tempo);

    printf ("\nvetor organizado: ");
    for (i = 0; i < 10000; i++)
    {
        printf (" %d ", v[i]);
    }

    return 0;
}
