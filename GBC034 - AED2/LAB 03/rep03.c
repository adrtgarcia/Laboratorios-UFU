// NOME: AMANDA DUARTE GARCIA
// MATRÍCULA: 12221BCC031

// NOME: CAIKE CESAR MOTA DE ARAUJO
// MATRÍCULA: 12221BCC030

// OBS: EXERCÍCIO 1 E TABELA ESTÃO NA PASTA DO CÓDIGO

#include <stdio.h>
#include <stdlib.h>
#include <time.h>

void criarHeap (int vetor[], int i, int f) {
    int aux = vetor[i];
    int j = i * 2 + 1;
    while (j <= f) {
        if (j < f) {
            if (vetor[j] < vetor[j + 1]) {
                j = j + 1;
            }
        }
        if (aux < vetor[j]) {
            vetor[i] = vetor[j];
            i = j;
            j = 2 * i + 1;
        } else {
            j = f + 1;
        }
    }
    vetor[i] = aux;
}

void heapSort (int vetor[], int n) {
    int i, aux;
    for (i = (n - 1)/2; i >= 0; i--) {
        criarHeap (vetor, i, n - 1);
    }
    for (i = n - 1; i >= 1; i--) {
        aux = vetor[0];
        vetor[0] = vetor[i];
        vetor[i] = aux;
        criarHeap (vetor, 0, i - 1);
    }
}

void shellSort (int vetor[], int n) {
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
                if (j < h) break;
            }
            vetor[j] = aux;
        }
    } while (h != 1);
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
                printf ("\nHeapSort x ShellSort");
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
                printf ("\ntempo HeapSort: %lf", tempo);

                // reiniciando vetor aleatório
                for (i = 0; i < tamanho; i++) {
                    v[i] = aux[i];
                }

                // ordenando com shellsort
                inicio = clock();
                shellSort (v, tamanho);
                fim = clock();
                tempo = (fim - inicio) / CLOCKS_PER_SEC;
                printf ("\ntempo ShellSort: %lf", tempo);

                break;

            case 2: // vetor crescente
                printf ("\nHeapSort x ShellSort");
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
                printf ("\ntempo HeapSort: %lf", tempo);

                // reiniciando vetor aleatório
                for (i = 0; i < tamanho; i++) {
                    v[i] = aux[i];
                }

                // ordenando com shellsort
                inicio = clock();
                shellSort (v, tamanho);
                fim = clock();
                tempo = (fim - inicio) / CLOCKS_PER_SEC;
                printf ("\ntempo ShellSort: %lf", tempo);

                break;

            case 3: // vetor decrescente
                printf ("\nHeapSort x ShellSort");
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
                printf ("\ntempo HeapSort: %lf", tempo);

                // reiniciando vetor aleatório
                for (i = 0; i < tamanho; i++) {
                    v[i] = aux[i];
                }

                // ordenando com shellsort
                inicio = clock();
                shellSort (v, tamanho);
                fim = clock();
                tempo = (fim - inicio) / CLOCKS_PER_SEC;
                printf ("\ntempo ShellSort: %lf", tempo);

                break;
        }

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

        if (opcao == 2) {
            printf ("\n\nencerrando o programa...");
            free (v);
            free (aux);
        }

    } while (opcao != 2);

    return 0;
}
