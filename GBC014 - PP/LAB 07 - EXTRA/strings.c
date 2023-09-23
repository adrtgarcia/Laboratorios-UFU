#include <stdio.h>
#include <string.h>

int main ( )
{
    char frase[200];
    int tamanho, cont;

    printf ("digite a frase: ");
    fgets (frase, 200, stdin);
    tamanho = strlen (frase);

    for (cont = 0; cont < tamanho; cont++)
    {
        if (frase[cont] == 'R')
        {
            frase[cont] = 'L';
        }

        if (frase[cont] == 'r')
        {
            frase[cont] = 'l';
        }
    }

    printf ("frase modificada: %s", frase);

    return 0;
}