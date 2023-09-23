#include <stdio.h>

int main ( )
{
    int vetor[8], x, y, cont, soma;

    printf ("digite oito valores:\n");
    for (cont = 0; cont < 8; cont++)
    {
        scanf (" %d", &vetor[cont]);
    }

    do
    {
        printf ("escolha o valor de X: ");
        scanf ("%d", &x);
        printf ("escolha o valor de Y: ");
        scanf ("%d", &y);

        if ((x < 0 || x > 8) || (y < 0 || y > 8))
        {
            printf ("valor invalido");
        }
    } while ((x < 0 || x > 8) || (y < 0 || y > 8));
    
    soma = vetor[x] + vetor[y];
    printf ("a soma eh %d", soma);

    return 0;
}