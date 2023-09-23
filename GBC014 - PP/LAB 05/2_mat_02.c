#include <stdio.h>

int main ( )
{
    int matriz[5][5], x, y, linha, coluna;

    for (x = 0; x <5; x++)
    {
        for (y = 0; y < 5; y++)
        {
            if (x == y)
            {
                matriz[x][y] = 1;
            } else matriz[x][y] = 0;
        }
    }

    printf ("matriz resultante:\n\n");
    for (linha = 0; linha < 5; linha++)
    {
        for (coluna = 0; coluna < 5; coluna++)
        {
            printf ("%d ", matriz[linha][coluna]);
        }
        
        printf ("\n");
    }

    return 0;
}