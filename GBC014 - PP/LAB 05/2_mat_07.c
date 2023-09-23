#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main ( )
{
    int matriz[5][5], sorteados[25] = {0}, a, b, num, cont, repete;
    srand (time(NULL));

    for (a = 0; a < 5; a++)
    {
        for (b = 0; b < 5; b++)
        {
            do //0 = não repete, 1 = repete
            {
                num = rand( ) % 100;
                repete = 0;
                for (cont = 0; cont < 25; cont++)
                {
                    if (num == (sorteados[cont]))
                    {
                        repete = 1;
                        break;
                    }
                }
            } while (repete);

            sorteados[a*5+b] = num;
            matriz[a][b] = num;
        }
    }

    printf ("tabela:\n");
    for (a = 0; a < 5; a++)
    {
        for (b = 0; b < 5; b++)
        {
            printf ("%5d ", matriz[a][b]);
        }

        printf ("\n");
    }

    return 0;
}