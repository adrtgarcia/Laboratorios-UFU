#include <stdio.h>
#include <stdlib.h>

int main ( ) 
{
    int tamanho = 10, posicao = 0, numero, novotam; 
    int *vetor = (int *) calloc(10, (sizeof(int))), *novovet = NULL;


    do
    {
        printf ("digite os numeros (0 para encerrar):\n");
        scanf ("%d", &numero);
        
        vetor[posicao] = numero;
        posicao++;
        
        if (posicao == tamanho) 
        {
            novotam = tamanho + 10;
            novovet = (int *) calloc (novotam, (sizeof(int)));

            for (int i = 0; i < tamanho; i++) 
            {
                novovet[i] = vetor[i];
            }

            free(vetor);

            vetor = novovet;
            tamanho = novotam;
        }

    } while (numero != 0);
    
    printf ("\vetor final:");
    printf ("\nvet[ ");
    for (int i = 0; i < posicao; i++) 
    {
        printf ("%d ", vetor[i]);
    }
    printf ("]");

    free(vetor);
    
    return 0;
}