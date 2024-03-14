#include <stdio.h>
#include <stdlib.h>
#include <time.h>

void maxHeapify (int array[], int tamHeap, int i) {
    int l, r, maior = i, temp;
    while (1) {
        l = 2 * i + 1;
        r = 2 * i + 2;
        if ((l <= i) && (array[l] > array[maior])) {
            maior = l;
        }
        if ((r <= i) && (array[r] > array[maior])) {
            maior = r;
        }
        if (maior != i) {
            temp = array[i];
            array[i] = array[maior];
            array[maior] = temp;
            i = maior;
        } else break;
    }
}

void buildMaxHeap (int array[], int i) {
    int tamHeap = i;
    for (i = tamHeap/2; i >= 0; i--) {
        maxHeapify (array, tamHeap, i);
    }
}

void heapSort (int array[], int tam) {
    int temp;
    buildMaxHeap (array, tam);
    for (int i = tam - 1; i > 0; i--) {
        temp = array[0];
        array[0] = array[i];
        array[i] = temp;
        maxHeapify (array, i, 0);
    }
}

int main ( ) {
    int opcao, tipo, tamanho, num, i, j;
    double inicio, fim, tempo;

    srand(time(NULL));

    do {
        do {
            printf ("\ntipo de vetor para comparacao:\n");
            printf ("\n(1) vetor aleatorio");
            printf ("\n(2) vetor de ordem crescente");
            printf ("\n(3) vetor de ordem decrescente\n");
            printf ("\nopcao escolhida: ");
            scanf ("%d", &tipo);

            if ((tipo < 1) && (tipo > 3)) 
                printf ("\nopcao invalida, tente novamente");
        } while ((tipo < 1) && tipo > 3);

        do {
            printf ("\ndigite o tamanho do vetor: ");
            scanf ("%d", &tamanho);

            if (tamanho <= 0)
                printf ("\ntamanho invalido, tente novamente");
        } while (tamanho <= 0);
        int *v = (int *) malloc (tamanho * sizeof(int));
        int *aux = (int *) malloc (tamanho * sizeof(int));

        switch (tipo)
        {
            case 1: // vetor aleatório
                printf ("\nvetor dinamico aleatorio com %d posicoes", tamanho);

                // gerando vetor aleatório
                for (i = 0; i < tamanho; i++) {
                    aux[i] = rand() % 500 + 1;
                    v[i] = aux[i];
                }

                // ordenando com heapsort
                inicio = clock();
                heapSort (v, tamanho);
                fim = clock();
                tempo = (fim - inicio) / CLOCKS_PER_SEC;
                printf ("\ntempo: %lf", tempo);

                break;

            case 2: // vetor crescente
                printf ("\nvetor dinamico em ordem crescente com %d posicoes", tamanho);

                // gerando vetor aleatório
                for (i = 0; i < tamanho; i++) {
                    aux[i] = rand() % 500 + 1;
                }

                // ordenando em ordem crescente
                for (int i = 0; i < tamanho; i++) {
                    for (int j = i + 1; j < tamanho; j++) {
                        if (aux[i] > aux[j]) {
                            num = aux[i];
                            aux[i] = aux[j];
                            aux[j] = num;
                        }
                    }
                }

                // iniciando vetor aleatório
                for (i = 0; i < tamanho; i++) {
                    v[i] = aux[i];
                }

                // ordenando com heapsort
                inicio = clock();
                heapSort (v, tamanho);
                fim = clock();
                tempo = (fim - inicio) / CLOCKS_PER_SEC;
                printf ("\ntempo: %lf", tempo);

                break;

            case 3: // vetor decrescente
                printf ("\nvetor dinamico em ordem decrescente com %d posicoes", tamanho);

                // gerando vetor aleatório
                for (i = 0; i < tamanho; i++) {
                    aux[i] = rand() % 500 + 1;
                }

                // ordenando em ordem decrescente
                for (int i = 0; i < tamanho; i++) {
                    for (int j = i + 1; j < tamanho; j++) {
                        if (aux[i] < aux[j]) {
                            num = aux[i];
                            aux[i] = aux[j];
                            aux[j] = num;
                        }
                    }
                }

                // iniciando vetor aleatório
                for (i = 0; i < tamanho; i++) {
                    v[i] = aux[i];
                }


                // ordenando com heapsort
                inicio = clock();
                heapSort (v, tamanho);
                fim = clock();
                tempo = (fim - inicio) / CLOCKS_PER_SEC;
                printf ("\ntempo: %lf", tempo);

                break;
        }

        free (v);
        free (aux);

        // mantendo o programa em loop para facilitar as comparações
        do
        {
            printf ("\n\n\nescolha uma opcao:");
            printf ("\n(1) realizar outra comparacao");
            printf ("\n(2) encerrar programa\n");
            printf ("\nopcao escolhida: ");
            scanf ("%d", &opcao);

            if ((opcao != 1) && (opcao != 2))
                printf ("\nopcao invalida, tente novamente");
        } while ((opcao != 1) && (opcao != 2));

        if (opcao == 2)
            printf ("\n\nencerrando o programa...");

    } while (opcao != 2);

    return 0;
}
