#include <stdio.h>

int main ( )
{
    int vetor[5], cont, menor, p_menor, maior, p_maior;
    
    printf ("digite cinco valores:\n");
    for (cont = 0; cont < 5; cont++)
    {
        scanf (" %d", &vetor[cont]);
    }

    menor = vetor[0];
    p_menor = 0;
    maior = vetor[0];
    p_maior = 0;

    for (cont = 0; cont < 5; cont++)
    {
        if (vetor[cont] > maior)
        {
            maior = vetor[cont];
            p_maior = cont;
        }
        
        if (vetor[cont] < menor)
        {
            menor = vetor[cont];
            p_menor = cont;
        }
    }

    printf ("\na posicao com maior valor eh: vetor[%d] = %d", p_maior, maior);
    printf ("\na posicao com menor valor eh: vetor[%d] = %d", p_menor, menor);
      
    return 0;
}