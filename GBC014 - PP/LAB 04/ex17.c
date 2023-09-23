#include <stdio.h>

int soma_inteiros (int a, int b);

int main ( )
{
    int num1, num2;
    
    do
    {
        printf ("digite o primeiro numero: ");
        scanf ("%d", &num1);
        printf ("digite o segundo numero: ");
        scanf ("%d", &num2);

        if (num2 < num1)
        {
            printf ("\ncoloque o menor numero primeiro!\n\n");
        }
    } while (num2 < num1);

    printf ("a soma dos inteiros entre %d e %d eh %d", num1, num2, soma_inteiros (num1, num2));

    return 0;
}

int soma_inteiros (int a, int b)
{
    int cont, soma = 0;

    for (cont = (a + 1); cont < b; cont++)
    {
        soma += cont;
    }

    return soma;
}