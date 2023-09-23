#include <stdio.h>
#include <string.h>
 
int main ( )
{
    char palavra[100], letra;
    int tamanho, cont, vogal = 0;

    printf ("digite uma palavra:\n");
    fgets (palavra, 100, stdin);
    printf ("digite uma letra:\n");
    scanf (" %c", &letra);

    tamanho = strlen(palavra);

    for (cont = 0; cont < tamanho; cont++)
    {
        if (strchr("AaEeIiOoUu", palavra[cont]))
        {
            vogal++;
            palavra[cont] = letra;
        }
    }

    printf ("\na palavra tem %d vogais", vogal);
    printf ("\npalavra modificada: %s", palavra);

    return 0;
}