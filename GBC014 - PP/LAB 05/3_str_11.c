#include <stdio.h>
#include <string.h>

int main ( )
{
    char S[100];
    int i, j, tamanho, cont;

    printf ("digite a string: ");
    fgets (S, 100, stdin);
    tamanho = strlen(S);

    do
    {
        printf ("\n");
        printf ("digite o valor de i: ");
        scanf ("%d", &i);
        printf ("digite o valor de j: ");
        scanf ("%d", &j);

        if ((i < 0) || (j < 0))
        {
            printf ("\nos numeros precisam ser inteiros nao-negativos");
        }
        if ((i >= tamanho) || (j >= tamanho))
        {
            printf ("\nos valores devem ser menores que o comprimento da string");
        }
        
    } while ((i < 0) || (j < 0) || (i >= tamanho) || (j >= tamanho));

    printf ("\no segmento escolhido eh:\n");
    for (cont = i; cont <= j; cont++)
    {
        printf ("%c", S[cont]);
    }

    return 0;
}