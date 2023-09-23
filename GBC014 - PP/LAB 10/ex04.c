#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main ( ) 
{
    FILE *fp = NULL;
    char nome[100], caractere;
    int consoantes = 0, vogais = 0;

    printf ("digite o nome do arquivo: ");
    fgets (nome, 100, stdin);
    nome[strcspn(nome, "\n")] = '\0';

    fp = fopen(nome, "r");
    if (fp == NULL)
    {
        printf ("erro ao abrir o arquivo");
        exit(1);
    }

    while ((caractere = fgetc(fp)) != EOF)
    {
        if (((caractere >= 65) && (caractere <= 90 )) || ((caractere >= 97) && (caractere <= 122)))
        {
            if ((caractere != 'A') && (caractere != 'a') && (caractere != 'E') && (caractere != 'e') && (caractere != 'I') && (caractere != 'i') && (caractere != 'O') && (caractere != 'o') && (caractere != 'U') && (caractere != 'u'))
            {
                consoantes++;
            } else {
                vogais++;
            }
        } 
    }

    printf ("o arquivo possui %d vogais e %d consoantes", vogais, consoantes);

    fclose (fp);

    return 0;
}