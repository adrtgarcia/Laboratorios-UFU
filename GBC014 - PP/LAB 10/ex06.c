#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main ( )
{
    FILE *fp = NULL;
    char nome[100], caractere;
    int i, quant;
    
    printf("digite o nome do arquivo: ");
    fgets(nome, 100, stdin);
    nome[strcspn(nome, "\n")] = '\0'; 

    fp = fopen (nome, "r"); 
    if (fp == NULL)
    {
        printf("\nerro ao abrir o arquivo");
        exit(1);
    }

    for (i = 97; i <= 122; i++)
    {
        fseek (fp, 0, SEEK_SET);
        quant = 0;

        while ((caractere = fgetc(fp)) != EOF)
        {
            if ((caractere >= 'A') && (caractere <= 'Z'))
            {
                caractere += 32;
            }

            if (caractere == i)
            {
                quant++;
            }
        }

        printf ("\na letra %c aparece %d vezes", (i - 32), quant);
    }
    
    fclose(fp);
    
    return 0;
}