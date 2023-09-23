#include <stdio.h>
#include <stdlib.h>

int main ( ) 
{
    int N, M;
    
    printf("Digite o número de linhas (N): ");
    scanf("%d", &N);
    printf("Digite o número de colunas (M): ");
    scanf("%d", &M);

    int **matriz = (int **)malloc(N * sizeof(int *));
    for (int i = 0; i < N; i++) 
    {
        matriz[i] = (int *)malloc(M * sizeof(int));
        for (int j = 0; j < M; j++) 
        {
            printf("Digite o elemento [%d][%d]: ", i, j);
            scanf("%d", &matriz[i][j]);
        }
    }

    int **matrizTransposta = (int **)malloc(M * sizeof(int *));
    for (int i = 0; i < M; i++) 
    {
        matrizTransposta[i] = (int *)malloc(N * sizeof(int));
        for (int j = 0; j < N; j++) 
        {
            matrizTransposta[i][j] = matriz[j][i];
        }
    }

    printf("\nMatriz original %dx%d:\n", N, M);
    for (int i = 0; i < N; i++) 
    {
        for (int j = 0; j < M; j++) 
        {
            printf("%d ", matriz[i][j]);
        }
        printf("\n");
    }

    printf("\nMatriz transposta %dx%d:\n", M, N);
    for (int i = 0; i < M; i++) 
    {
        for (int j = 0; j < N; j++) 
        {
            printf("%d ", matrizTransposta[i][j]);
        }
        printf("\n");
    }

    for (int i = 0; i < N; i++) 
    {
        free(matriz[i]);
    }
    free(matriz);

    for (int i = 0; i < M; i++) 
    {
        free(matrizTransposta[i]);
    }
    free(matrizTransposta);

    return 0;
}