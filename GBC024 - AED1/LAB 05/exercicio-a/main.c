#include "tad_string.h"

#include <stdio.h>
#include <stdlib.h>

int main ( )
{
    str *string;
    char c;
    int tam, quant;

    string = criar ( );

    if (string == NULL)
    {
        printf ("\nerro na criacao da string");
        return 0;
    }

    preencher (string);

    tam = tamanho (string);
    printf ("\ntamanho da string: %d caracteres\n", tam);

    printf ("\ndigite um caractere: ");
    scanf ("%c", &c);
    quant = ocorrencias (string, c);
    printf ("\no caractere '%c' aparece %dx na string\n", c, quant);

    printf ("\nstring lida:\n");
    printar (string);

    free (string);
    return 0;
}
