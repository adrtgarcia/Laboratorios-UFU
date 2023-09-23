#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main ( )
{    
    FILE *fp = NULL, *farq = NULL;
    char nome[100], caractere;

    printf ("digite o nome do arquivo: ");
    fgets (nome, 100, stdin);
    nome[strcspn(nome, "\n")] = '\0';

    fp = fopen(nome, "r");
    if (fp == NULL)
    {
        printf ("\nerro ao abrir o arquivo");
        exit(1);
    }

    farq = fopen("novo.txt", "w");
    if (farq == NULL)
    {
        printf ("\nerro ao criar o arquivo");
        exit(1);
    }

    while ((caractere = fgetc(fp)) != EOF)
    {
        if ((caractere == 'a') || (caractere == 'e') || (caractere == 'i') || (caractere == 'o') || (caractere == 'u'))
        {
            caractere = '*';
        }

        if ((caractere == 'A') || (caractere == 'E') || (caractere == 'I') || (caractere == 'O') || (caractere == 'U'))
        {
            caractere = '*';
        }

        fprintf (farq, "%c", caractere);
    }

    fclose(fp);
    fclose(farq);

    return 0;
}