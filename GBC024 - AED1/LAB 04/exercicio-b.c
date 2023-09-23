#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int analisastring (char *string, int tamanho, char caractere);

int main ( )
{
    char *str, caractere;
    int quant;

    str = (char *) calloc (100, (sizeof(char)));
    if (str == NULL)
    {
        printf ("erro na alocacao de memoria");
        return 0;
    }

    printf ("digite uma string: ");
    fgets (str, 100, stdin);
    str[strcspn(str, "\n")] = '\0';

    printf ("digite um caractere: ");
    scanf ("%c", &caractere);

    quant = analisastring (str, 100, caractere);

    printf ("\nnova string: %s", str);
    printf ("\no caractere '%c' repetiu %dx vezes", caractere, quant);

    return 0;
}

int analisastring (char *string, int tamanho, char caractere)
{
    int i, quant;

    for (i = 0, quant = 0; i < tamanho; i++)
    {
        if (string[i] == caractere)
        {
            string[i] = '*';
            quant++;
        }
    }

    return quant;
}
