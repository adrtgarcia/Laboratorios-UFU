#include <stdio.h>

int main ( )
{
    int matriz[5][5], a, b, X, encontrado;

    printf ("digite os valores da matriz:\n");
    for (a = 0; a < 5; a++)
    {
        for (b = 0; b < 5; b++)
        {
            scanf (" %d", &matriz[a][b]);
        }
    }

    printf ("\ndigite o valor a ser buscado: ");
    scanf ("%d", &X);

    //0 = não encontrado, 1 = encontrado
    encontrado = 0;
    for (a = 0; a < 5; a++)
    {
        for (b = 0; b < 5; b++)
        {
            if (matriz[a][b] == X)
            {
                encontrado = 1;
                break;
            }
        }
    }

    if (encontrado == 1)
    {
        printf ("\n%d foi encontrado na posicao (%d, %d).", X, a, b);
    } else printf ("\n%d nao foi encontrado na matriz.", X);

    return 0;
}