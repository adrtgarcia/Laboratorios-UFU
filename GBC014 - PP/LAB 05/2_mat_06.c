#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main ( )
{
    int matriz[4][4], x, y, num;
    srand (time(NULL));

    for (x = 0; x < 4; x++)
    {
        for (y = 0; y < 4; y++)
        {
            num = rand() %20 + 1;
            matriz[x][y] = num;
        }
    }

    printf ("matriz original:\n");
    for (x = 0; x < 4; x++)
    {
        for (y = 0; y < 4; y++)
        {
            printf ("%8d ", matriz[x][y]);
        }

        printf ("\n");
    }
    
    for (x = 0; x < 4; x++)
    {
        for (y = (x + 1); y < 4; y++)
        {
            matriz[x][y] = 0;
        }
    }

    printf ("\n\nmatriz transformada:\n");
    for (x = 0; x < 4; x++)
    {
        for (y = 0; y < 4; y++)
        {
            printf ("%8d ", matriz[x][y]);
        }

        printf ("\n");
    }

    return 0;
}