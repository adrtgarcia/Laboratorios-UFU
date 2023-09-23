#include <stdio.h>
#include <string.h>

int main ( )
{
    char frase[100], modificada[100];
    int tamanho, cont1, cont2;

    printf ("digite uma frase: ");
    fgets (frase, 100, stdin);
    tamanho = strlen(frase);
 
    for (cont1 = 0, cont2 = 0; cont1 < tamanho; cont1++)
    {
        if (frase[cont1] != ' ')
        {
            modificada[cont2] = frase[cont1];
            cont2++;
        }
    }

    modificada[cont2] = '\0';

    printf ("frase modificada: %s", modificada);

    return 0;
}