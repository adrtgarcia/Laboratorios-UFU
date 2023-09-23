#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main ( )
{
    FILE *fp = NULL;
    char nome[100], pessoa[100], telefone[15];
    
    printf ("digite o nome do arquivo: ");
    fgets(nome, 100, stdin);
    nome[strcspn(nome, "\n")] = '\0'; 

    fp = fopen (nome, "w"); 
    if (fp == NULL)
    {
        printf ("\nerro ao abrir o arquivo");
        exit(1);
    }

    while (1)
    {
        printf ("\ndigite o nome (0 para encerrar): ");
        fgets(pessoa, 100, stdin);
        pessoa[strcspn(pessoa, "\n")] = '\0';

        if (strcmp(pessoa, "0") == 0) 
        {
            break;
        }

        printf ("digite o telefone: ");
        fgets(telefone, 100, stdin);
        telefone[strcspn(telefone, "\n")] = '\0';

        fprintf(fp, "%s %s\n", pessoa, telefone);
    }

    fclose(fp);

    return 0;
}