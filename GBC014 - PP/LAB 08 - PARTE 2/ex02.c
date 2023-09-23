#include <stdio.h>

int main ( )
{
    float mat[3][3];
    float *p = NULL;
    int i, j;

    p = &mat[i][j];

    printf ("enderecos de memoria:\n");

    for (i = 0; i < 3; i++)
    {
        for (j = 0; j < 3; j++)
        {
            printf ("\nmat[%d][%d] = %p", i, j, (p + (i * 3 + j)));
        }
    }

    return 0;
}