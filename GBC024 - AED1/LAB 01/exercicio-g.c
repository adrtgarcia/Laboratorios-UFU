#include <stdio.h>

int main ( )
{
    int i, j, mat[5][10], soma[5] = {0, 0, 0, 0, 0}, mult[5][10];

    printf ("preencha os valores da matriz:\n\n");

    for (i = 0; i < 5; i++)
    {
        for (j = 0; j < 10; j++)
        {
            printf ("mat[%d][%d] = ", i, j);
            scanf ("%d", &mat[i][j]);

            soma[i] += mat[i][j];
        }
    }

    printf ("matriz resultante:\n\n");

    for (i = 0; i < 5; i++)
    {
        for (j = 0; j < 10; j++)
        {
            mult[i][j] = mat[i][j] * soma[i];
            printf (" %d ", mult[i][j]);
        }

        printf ("\n");
    }

    return 0;
}
