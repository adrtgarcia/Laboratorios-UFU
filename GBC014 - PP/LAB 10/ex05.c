#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main ( ) 
{
    FILE *fp = NULL;
    char nome[100], caractere, procura;
    int quant = 0;

    printf ("digite o nome do arquivo: ");
    fgets (nome, 100, stdin);
    nome[strcspn(nome, "\n")] = '\0';

    fp = fopen(nome, "r");
    if (fp == NULL)
    {
        printf ("erro ao abrir o arquivo");
        exit(1);
    }

    printf ("digite o caractere que deseja procurar: ");
    scanf (" %c", &procura);

    while ((caractere = fgetc(fp)) != EOF)
    {
        if (caractere == procura)
        {
            quant++;
        } 
    }

    printf ("o caractere '%c' aparece %d vezes no arquivo", procura, quant);

    fclose (fp);

    return 0;
}