#include <stdio.h>
#include <stdlib.h>

int main ( ) 
{
    int i, j, k, acertos = 0;
    int *sorteados = NULL, *bilhete = NULL, *corretos = NULL;

    sorteados = (int *) calloc (6, (sizeof(int)));
    if (sorteados == NULL) 
    {
        printf ("\nerro: memoria insuficiente");
        exit(1);
    }

    bilhete = (int *) calloc (6, (sizeof(int)));
    if (sorteados == NULL) 
    {
        printf ("\nerro: memoria insuficiente");
        exit(1);
    }

    printf("digite os seis numeros sorteados:\n");
    for (i = 0; i < 6; i++) 
    {
        scanf ("%d", &sorteados[i]);
    }

    printf("\ndigite os seis numeros do bilhete:\n");
    for (i = 0; i < 6; i++) 
    {
        scanf ("%d", &bilhete[i]);
    }

    for (i = 0; i < 6; i++) 
    {
        for (j = 0; j < 6; j++) 
        {
            if (bilhete[i] == sorteados[j]) 
            {
                acertos++;
                break;
            }
        }
    }

    corretos = (int *) calloc (acertos, (sizeof(int)));
    if (corretos == NULL) 
    {
        printf ("\nerro: memoria insuficiente");
        exit(1);
    }

    for (k = 0, i = 0; i < 6; i++) 
    {
        for (j = 0; j < 6; j++) 
        {
            if (bilhete[i] == sorteados[j]) 
            {
                corretos[k] = bilhete[i];
                k++;
                break;
            }
        }
    }

    printf("\nnumeros corretos: ");
    for (i = 0; i < acertos; i++) 
    {
        printf ("%d ", *(corretos + i));
    }

    free(sorteados);
    free(bilhete);
    free(corretos);

    return 0;
}