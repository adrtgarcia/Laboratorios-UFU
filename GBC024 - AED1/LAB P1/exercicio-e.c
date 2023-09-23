#include <stdio.h>
#include <stdlib.h>

int main ( )
{
    int lotomania[50], apostados[50], *acertos, quant;
    float porcentagem;
    int i, j;

    printf ("digite os numeros sorteados pela Lotomania:\n");
    for (i = 0; i < 50; i++)
    {
        printf ("numero %d = ", (i + 1));
        scanf ("%d", &lotomania[i]);
    }

    printf ("\ndigite os numeros apostados:\n");
    for (i = 0; i < 50; i++)
    {
        printf ("numero %d = ", (i + 1));
        scanf ("%d", &apostados[i]);
    }

    acertos = (int *) calloc (1, (sizeof(int)));
    if (acertos == NULL)
    {
        printf ("\nerro na alocacao de memoria");
        return 0;
    }

    for (i = 0, quant = 0; i < 50; i++)
    {
        for (j = (i + 1); j < 50; j++)
        {
            if (lotomania[i] == apostados[j])
            {
                acertos[quant] = lotomania[i];
                quant++;

                acertos = (int *) realloc (acertos, (quant * (sizeof(int))));
                if (acertos == NULL)
                {
                    printf ("erro na realocacao de memoria");
                    return 0;
                }
            }
        }
    }

    printf ("\n\nnumeros sorteados pela Lotomania:\n");
    for (i = 0; i < 50; i++)
    {
        printf (" %d ", lotomania[i]);

        if ((i + 1) % 10 == 0)
        {
            printf ("\n");
        }
    }

    printf ("\n\nnumeros corretos:\n");
    for (i = 0; i < quant; i++)
    {
        printf (" %d ", acertos[i]);

        if ((i + 1) % 10 == 0)
        {
            printf ("\n");
        }
    }

    porcentagem = (((quant * 1.0)/50) * 100);
    printf ("\na porcentagem de acertos foi de %.2f%%", porcentagem);

    free(acertos);

    return 0;
}
