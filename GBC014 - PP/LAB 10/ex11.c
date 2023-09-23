#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main ( )
{
    FILE *fp = NULL;
    char nome[100], palavra[100], procura[100];
    int cont = 0;

    printf ("digite o nome do arquivo: ");
    fgets (nome, 100, stdin);
    nome[strcspn(nome, "\n")] = '\0';

    fp = fopen(nome, "r");
    if (fp == NULL)
    {
        printf ("\nerro ao abrir o arquivo");
        exit(1);
    }

    printf ("digite a palavra que deseja procurar: ");
    fgets (procura, 100, stdin);
    procura[strcspn(procura, "\n")] = '\0';

    while (fscanf(fp, "%s", palavra) == 1) 
    {
        if (strcmp(palavra, procura) == 0) 
        {
            cont++;
        }
    }

    printf("\na palavra '%s' aparece %d vezes no arquivo", procura, cont);

    fclose(fp);

    return 0;
}