#include <stdio.h>
#include <stdlib.h>

int main ( ) 
{
    int N, M, i, j;
    int **matriz = NULL;

    printf ("digite o número de linhas: ");
    scanf ("%d", &N);

    printf ("\ndigite o número de colunas: ");
    scanf ("%d", &M);

    matriz = (int **) calloc (N, (sizeof(int *)));
    for (i = 0; i < N; i++) 
    {
        matriz[i] = (int *) calloc (M, (sizeof(int)));
    }

    printf ("\ndigite os elementos da matriz:\n");
    for (i = 0; i < N; i++) 
    {
        for (j = 0; j < M; j++) 
        {
            scanf("%d", &matriz[i][j]);
        }
    }

    int maior1 = matriz[0][0], linha1 = 0, coluna1 = 0;
    int maior2 = matriz[0][0], linha2 = 0, coluna2 = 0;
    int maior3 = matriz[0][0], linha3 = 0, coluna3 = 0;

    for (i = 0; i < N; i++) 
    {
        for (j = 0; j < M; j++) 
        {
            if (matriz[i][j] > maior1) 
            {
                maior3 = maior2;
                linha3 = linha2;
                coluna3 = coluna2;

                maior2 = maior1;
                linha2 = linha1;
                coluna2 = coluna1;

                maior1 = matriz[i][j];
                linha1 = i;
                coluna1 = j;
            } else if (matriz[i][j] > maior2) 
            {
                maior3 = maior2;
                linha3 = linha2;
                coluna3 = coluna2;

                maior2 = matriz[i][j];
                linha2 = i;
                coluna2 = j;
            } else if (matriz[i][j] > maior3) 
            {
                maior3 = matriz[i][j];
                linha3 = i;
                coluna3 = j;
            }
        }
    }

    printf ("\nmaiores numeros:\n");
    printf ("\nprimeiro: %d (linha: %d, coluna: %d)", maior1, linha1, coluna1);
    printf ("\nsegundo: %d (linha: %d, coluna: %d)", maior2, linha2, coluna2);
    printf ("\nterceiro: %d (linha: %d, coluna: %d)", maior3, linha3, coluna3);

    for (i = 0; i < N; i++) 
    {
        free(matriz[i]);
    }
    free(matriz);

    return 0;
}