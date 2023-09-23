#include <stdio.h>
#include <stdlib.h>

int verificar (int **matriz, int linhas, int colunas, int valor);

int main ( ) 
{
    int linhas, colunas, valor, resultado, i, j;
    int **matriz = NULL;

    printf("digite o número de linhas: ");
    scanf("%d", &linhas);

    printf("\ndigite o número de colunas: ");
    scanf("%d", &colunas);

    matriz = (int **) calloc (linhas, (sizeof(int *)));
    for (i = 0; i < linhas; i++) 
    {
        matriz[i] = (int *) calloc (colunas, (sizeof(int)));
    }

    printf("\ndigite os elementos da matriz:\n");
    for (i = 0; i < linhas; i++) 
    {
        for (j = 0; j < colunas; j++) 
        {
            scanf ("%d", &matriz[i][j]);
        }
    }

    printf ("\ndigite um valor: ");
    scanf ("%d", &valor);

    resultado = verificar (matriz, linhas, colunas, valor);

    if (resultado) 
    {
        printf("\no valor %d esta presente na matriz.", valor);
    } else {
        printf("\no valor %d nao esta presente na matriz", valor);
    }

    for (i = 0; i < linhas; i++) 
    {
        free(matriz[i]);
    }

    free(matriz);

    return 0;
}

int verificar (int **matriz, int linhas, int colunas, int valor) 
{
    int i, j;

    for (i = 0; i < linhas; i++) 
    {
        for (j = 0; j < colunas; j++) 
        {
            if (matriz[i][j] == valor) 
            {
                return 1;  
            }
        }
    }

    return 0;
}