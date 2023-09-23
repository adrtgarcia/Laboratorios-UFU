#include <stdio.h>

int main ( )
{
    int matriz[4][4], x, y, maior10 = 0;

    printf ("digite os valores da matriz 4x4: \n");
    for (x = 0; x < 4; x++)
    {
        for (y = 0; y < 4; y++)
        {
            scanf (" %d", &matriz[x][y]);
        }
    }

    for (x = 0; x < 4; x++)
    {
        for (y = 0; y < 4; y++)
        {
            if (matriz[x][y] > 10)
            {
                maior10++;
            }
        }
    }

    printf ("a matriz possuis %d numeros maiores que 10", maior10);

    return 0;
}