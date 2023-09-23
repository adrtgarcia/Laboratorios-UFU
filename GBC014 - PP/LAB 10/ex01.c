#include <stdio.h>
#include <stdlib.h>

int main ( )
{    
    FILE *fp = NULL;
    char caractere;
    char ler;

    fp = fopen ("arq.txt", "w");
    if (fp == NULL)
    {
        printf ("erro na abertura do arquivo");
        exit(1);
    }

    printf ("digite quaisquer caracteres (0 para encerrar):\n");
    while (1)
    {
        scanf (" %c", &caractere);

        if (caractere == '0')
        {
            break;
        }

        fputc (caractere, fp);
    }

    fclose (fp);

    fp = fopen ("arq.txt", "r");
    if (fp == NULL)
    {
        printf ("\nerro ao abrir o arquivo");
        exit(1);
    }

    printf ("\nconteudo registrado:\n");
    while ((ler = fgetc(fp)) != EOF)
    {
        printf ("%c", ler);
    }

    fclose (fp);

    return 0;
}