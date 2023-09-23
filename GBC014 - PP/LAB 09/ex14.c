#include <stdio.h>
#include <stdlib.h>

int main ( ) 
{
    int linhas, colunas, i, j;
    float **matriz = NULL;

    printf("digite o número de linhas: ");
    scanf("%d", &linhas);

    printf("\ndigite o número de colunas: ");
    scanf("%d", &colunas);

    matriz = (float **) calloc(linhas, (sizeof(float *)));
    for (i = 0; i < linhas; i++) 
    {
        matriz[i] = (float *) calloc (colunas, (sizeof(float)));
    }

    printf("\ndigite os elementos da matriz:\n");
    for (i = 0; i < linhas; i++) 
    {
        for (j = 0; j < colunas; j++) 
        {
            scanf("%f", &matriz[i][j]);
        }
    }

    printf("\nmatriz final:\n");
    for (i = 0; i < linhas; i++) 
    {
        for (j = 0; j < colunas; j++) 
        {
            printf("%.2f ", matriz[i][j]);
        }
 
        printf("\n");
    }

    for (i = 0; i < linhas; i++) 
    {
        free(matriz[i]);
    }
    free(matriz);

    return 0;
}