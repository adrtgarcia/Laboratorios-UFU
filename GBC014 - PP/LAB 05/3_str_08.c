#include <stdio.h>
#include <string.h>

int main ( )
{
    char string[100], l1, l2;
    int tamanho, cont;

    printf ("digite a string: ");
    fgets (string, 100, stdin);
    tamanho = strlen(string);

    printf ("digite uma letra: ");
    scanf (" %c", &l1);
    printf ("digite outra letra: ");
    scanf (" %c", &l2);

    for (cont = 0; cont < tamanho; cont++)
    {
        if (string[cont] == l1)
        {
            string[cont] = l2;
        }
    }

    printf ("string final: %s", string);

    return 0;
} 