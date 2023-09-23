#include <stdio.h>
#include <string.h>

int main ( )
{
    char palavra[100];
    int tamanho, cont;

    printf ("digite uma palavra:\n");
    fgets (palavra, 100, stdin);
    tamanho = strlen(palavra);

    printf ("palavra ao contrario: ");
    for (cont = (tamanho - 1); cont >= 0; cont--)
    {
        printf ("%c", palavra[cont]);
    }

    return 0;
}