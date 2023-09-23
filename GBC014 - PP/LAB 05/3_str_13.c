#include <stdio.h>
#include <string.h>

int main ( )
{
    char string[100];
    int tamanho, cont1, cont2, palindromo = 1;
 
    printf ("digite uma palavra ou uma frase: ");
    fgets (string, 100, stdin);
    tamanho = strlen(string);

    for (cont1 = 0, cont2 = (tamanho - 2); cont1 < (tamanho/2); cont1++, cont2--)
    {
        if (string[cont1] != string[cont2])
        {
            palindromo = 0; //falso
            break;
        }
    }

    if (palindromo)
    {
        printf ("\neh um palindromo");
    } else printf ("\n nao eh um palindromo");

    return 0;
}