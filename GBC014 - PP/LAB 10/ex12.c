#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main ( ) 
{
    FILE *fp = NULL;
    char nome[100], ch, str[100];
    int caractere = 0, linha = 0, palavra = 0, cont, i;

    printf ("digite o nome do arquivo: ");
    fgets (nome, 100, stdin);
    nome[strcspn(nome, "\n")] = '\0';

    fp = fopen(nome, "r");
    if (fp == NULL)
    {
        printf ("\nerro ao abrir o arquivo");
        exit(1);
    }

    while ((ch = fgetc(fp)) != EOF) 
    {
        caractere++;

        if (ch == '\n') 
        {
            linha++;
        }
    }

    fseek (fp, 0, SEEK_SET);

    while (fscanf(fp, "%s", str) == 1)
    {
        palavra++;
    }

    printf ("\nnumero de caracteres: %d", caractere);
    printf ("\nnumero de linhas: %d", (linha + 1));
    printf ("\nnumero de palavras: %d\n", palavra);
    printf ("\nContagem de letras:");

    for (i = 97; i <= 122; i++)
    {
        fseek (fp, 0, SEEK_SET);
        cont = 0;

        while ((caractere = fgetc(fp)) != EOF)
        {
            if ((caractere >= 'A') && (caractere <= 'Z'))
            {
                caractere += 32;
            }

            if (caractere == i)
            {
                cont++;
            }
        }

        printf ("\na letra '%c' aparece %d vezes", (i - 32), cont);
    }

    fclose(fp);

    return 0;
}