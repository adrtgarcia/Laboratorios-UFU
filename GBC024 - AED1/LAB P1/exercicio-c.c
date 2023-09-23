#include <stdio.h>
#include <stdlib.h>

int main ( )
{
    int linhas, colunas, tamanho, tamanho_final, repete;
    int **matriz, *vetor, *vetor_final;
    int i, j, k;

    printf ("digite o numero de linhas da matriz: ");
    scanf ("%d", &linhas);

    printf ("digite o numero de colunas da matriz: ");
    scanf ("%d", &colunas);

    matriz = (int **) calloc (linhas, (sizeof(int *)));
    if (matriz == NULL)
    {
        printf ("\nerro na alocacao de memoria");
        return 0;
    }

    for (i = 0; i < linhas; i++)
    {
        matriz[i] = (int *) calloc (colunas, (sizeof(int)));
        if (matriz[i] == NULL)
        {
            printf ("\nerro na alocacao de memoria");
            return 0;
        }
    }

    printf ("\ndigite os elementos da matriz:\n");
    for (i = 0; i < linhas; i++)
    {
        for (j = 0; j < colunas; j++)
        {
            printf ("matriz[%d][%d] = ", i, j);
            scanf ("%d", &matriz[i][j]);
        }
    }

    tamanho = linhas * colunas;
    vetor = (int *) calloc (tamanho, (sizeof(int)));
    if (vetor == NULL)
    {
        printf ("\nerro na alocacao de memoria");
        return 0;
    }

    for (i = 0, k = 0; i < linhas; i++)
    {
        for (j = 0; j < colunas; j++)
        {
            vetor[k] = matriz[i][j];
            k++;
        }
    }

    vetor_final = (int *) calloc (tamanho, (sizeof(int)));
    if (vetor_final == NULL)
    {
        printf ("\nerro na alocacao de memoria");
        return 0;
    }

    for (i = 0, tamanho_final = 0; i < tamanho; i++)
    {
        repete = 0;

        for (j = 0; j < tamanho_final; j++)
        {
            if (vetor_final[j] == vetor[i])
            {
                repete = 1;
                break;
            }
        }

        if (repete == 0)
        {
            vetor_final[tamanho_final] = vetor[i];
            tamanho_final++;
        }
    }

    vetor_final = (int *) realloc (vetor_final, (tamanho_final * (sizeof(int))));
    if (vetor_final == NULL)
    {
        printf ("\nerro na alocacao de memoria");
        return 0;
    }

    printf ("\nvetor resultante = [");
    for (i = 0; i < tamanho_final; i++)
    {
        printf (" %d ", vetor_final[i]);
    }
    printf ("]");

    for (i = 0; i < linhas; i++)
    {
        free(matriz[i]);
    }
    free(matriz);
    free(vetor);
    free(vetor_final);

    return 0;
}
