#include <stdio.h>

int main ( )
{
    int matriz[4][4], x, y, maior, maiorx, maiory;

    printf ("digite os valores da matriz:\n");
    for (x = 0; x < 4; x++)
    {
        for (y = 0; y < 4; y++)
        {
            scanf (" %d", &matriz[x][y]);
        }
    }

    printf ("\nmatriz:\n\n");
    for (x = 0; x < 4; x++)
    {
        for (y = 0; y < 4; y++)
        {
            printf ("%10d ", matriz[x][y]);
        }
        printf ("\n");
    }

    maior = matriz[0][0];
    for (x = 0; x < 4; x++)
    {
        for (y = 0; y < 4; y++)
        {
            if (matriz[x][y] > maior)
            {
                maior = matriz[x][y];
                maiorx = x;
                maiory = y;
            } else continue;
        }
    }
    printf ("%d, o maior valor, esta localizado em (%d, %d).", maior, maiorx, maiory);

    return 0;
}