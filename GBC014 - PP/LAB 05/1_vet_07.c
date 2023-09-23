#include <stdio.h>

int main ( )
{
    int vetor[6], cont, soma = 0, quant = 0;
    
    printf ("digite seis valores:\n");
    for (cont = 0; cont < 6; cont++)
    {
        scanf (" %d", &vetor[cont]);
    }

    printf ("\nnumeros pares: ");
    for (cont = 0; cont < 6; cont++)
    {
        if (vetor[cont]%2 == 0)
        {
            printf ("%d ", vetor[cont]);
            soma += vetor[cont];
        }
    }
    printf ("\nsoma dos pares: %d", soma);

    printf ("\nnumeros impares: ");
    for (cont = 0; cont < 6; cont++)
    {
        if (vetor[cont]%2 != 0)
        {
            printf ("%d ", vetor[cont]);
            quant++;
        }
    }
    printf ("\nquantidade de impares: %d", quant);

    return 0;
}