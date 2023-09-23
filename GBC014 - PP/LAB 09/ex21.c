#include <stdio.h>
#include <stdlib.h>

void lerMatriz(int** matriz, int linhas, int colunas) 
{
    printf("Digite os elementos da matriz:\n");
    for (int i = 0; i < linhas; i++) {
        for (int j = 0; j < colunas; j++) {
            printf("Matriz[%d][%d]: ", i, j);
            scanf("%d", &matriz[i][j]);
        }
    }
}

void imprimirMatriz(int** matriz, int linhas, int colunas) 
{
    for (int i = 0; i < linhas; i++) {
        for (int j = 0; j < colunas; j++) {
            printf("%d ", matriz[i][j]);
        }
        printf("\n");
    }
}

int** multiplicarMatrizes(int** matriz1, int** matriz2, int linhas1, int colunas1, int linhas2, int colunas2) 
{
    if (colunas1 != linhas2) {
        printf("As matrizes não podem ser multiplicadas.\n");
        return NULL;
    }
    
    int** produto = (int**)malloc(linhas1 * sizeof(int*));
    for (int i = 0; i < linhas1; i++) {
        produto[i] = (int*)malloc(colunas2 * sizeof(int));
    }
    
    for (int i = 0; i < linhas1; i++) {
        for (int j = 0; j < colunas2; j++) {
            produto[i][j] = 0;
            for (int k = 0; k < colunas1; k++) {
                produto[i][j] += matriz1[i][k] * matriz2[k][j];
            }
        }
    }
    
    return produto;
}

int main ( ) 
{
    int a, b, c, d;
    
    printf("Digite as dimensões da primeira matriz (a e b): ");
    scanf("%d %d", &a, &b);
    
    printf("Digite as dimensões da segunda matriz (c e d): ");
    scanf("%d %d", &c, &d);
    
    if (b != c) {
        printf("As matrizes não podem ser multiplicadas.\n");
        return 0;
    }
    
    int** matriz1 = (int**)malloc(a * sizeof(int*));
    for (int i = 0; i < a; i++) {
        matriz1[i] = (int*)malloc(b * sizeof(int));
    }
    
    int** matriz2 = (int**)malloc(c * sizeof(int*));
    for (int i = 0; i < c; i++) {
        matriz2[i] = (int*)malloc(d * sizeof(int));
    }
    
    lerMatriz(matriz1, a, b);
    lerMatriz(matriz2, c, d);
    
    printf("Matriz 1:\n");
    imprimirMatriz(matriz1, a, b);
    
    printf("Matriz 2:\n");
    imprimirMatriz(matriz2, c, d);
    
    int** produto = multiplicarMatrizes(matriz1, matriz2, a, b, c, d);
    if (produto != NULL) {
        printf("Produto das matrizes:\n");
        imprimirMatriz(produto, a, d);
    }
    
    for (int i = 0; i < a; i++) {
        free(matriz1[i]);
    }
    free(matriz1);
    
    for (int i = 0; i < c; i++) {
        free(matriz2[i]);
    }
    free(matriz2);
    
    if (produto != NULL) {
        for (int i = 0; i < a; i++) {
            free(produto[i]);
        }
        free(produto);
    }
    
    return 0;
}