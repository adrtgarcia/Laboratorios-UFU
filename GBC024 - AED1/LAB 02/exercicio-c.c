#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main ( )
{
    int **mat1 = NULL, **mat2 = NULL, **mat3 = NULL;
    int i, j;

    mat1 = (int **) calloc (3, (sizeof(int *)));
    for (i = 0; i < 3; i++)
    {
        mat1[i] = (int *) calloc (3, (sizeof(int)));
    }

    if (mat1 == NULL)
    {
        printf ("erro na alocacao de memoria");
        return 0;
    }

    mat2 = (int **) calloc (3, (sizeof(int *)));
    for (i = 0; i < 3; i++)
    {
        mat2[i] = (int *) calloc (3, (sizeof(int)));
    }

    if (mat2 == NULL)
    {
        printf ("erro na alocacao de memoria");
        return 0;
    }

    srand (time(NULL));

    for (i = 0; i < 3; i++)
    {
        for (j = 0; j < 3; j++)
        {
            mat1[i][j] = rand ( ) % 100;
            mat2[i][j] = rand ( ) % 100;
        }
    }

    mat3 = (int **) calloc (3, (sizeof(int *)));
    for (i = 0; i < 3; i++)
    {
        mat3[i] = (int *) calloc (3, (sizeof(int)));
    }

    if (mat3 == NULL)
    {
        printf ("erro na alocacao de memoria");
        return 0;
    }

    for (i = 0; i < 3; i++)
    {
        for (j = 0; j < 3; j++)
        {
            mat3[i][j] = mat1[i][j] + mat2[i][j];
        }
    }

    printf ("matriz 1:\n");
    for (i = 0; i < 3; i++)
    {
        for (j = 0; j < 3; j++)
        {
            printf (" %d ", mat1[i][j]);
        }

        printf ("\n");
    }

    printf ("\nmatriz 2:\n");
    for (i = 0; i < 3; i++)
    {
        for (j = 0; j < 3; j++)
        {
            printf (" %d ", mat2[i][j]);
        }

        printf ("\n");
    }

    printf ("\nmatriz 3:\n");
    for (i = 0; i < 3; i++)
    {
        for (j = 0; j < 3; j++)
        {
            printf (" %d ", mat3[i][j]);
        }

        printf ("\n");
    }

    for (i = 0; i < 3; i++)
    {
        free(mat1[i]);
        free(mat2[i]);
        free(mat3[i]);
    }

    free(mat1);
    free(mat2);
    free(mat3);

    return 0;
}
