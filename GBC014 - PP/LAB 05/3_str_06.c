#include <stdio.h>
#include <string.h>

int main ( )
{
    char sequencia[100];
    int cont, tamanho;

    printf ("digite a sequencia de caracteres: ");
    fgets (sequencia, 100, stdin);
    tamanho = strlen (sequencia);

    for (cont = 0; cont < tamanho; cont++)
    {
        if ((sequencia[cont] >= 'a') && (sequencia[cont] <= 'z'))
        {
            sequencia[cont] -= 32;
        }
    }

    printf ("sequencia final: %s", sequencia);

    return 0;
}