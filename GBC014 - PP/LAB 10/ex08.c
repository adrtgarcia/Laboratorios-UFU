#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

int main ( )
{
    FILE *fa = NULL, *fb = NULL;
    char arq1[100], arq2[100], caractere;

    printf ("digite o nome do arquivo original: ");
    fgets (arq1, 100, stdin);
    arq1[strcspn(arq1, "\n")] = '\0';

    fa = fopen(arq1, "r");
    if (fa == NULL)
    {
        printf ("\nerro ao abrir o arquivo");
        exit(1);
    }

    setbuf (stdin, NULL);
    printf ("digite o nome do novo arquivo: ");
    fgets (arq2, 100, stdin);
    arq2[strcspn(arq1, "\n")] = '\0';

    fb = fopen(arq2, "w");
    if (fb == NULL)
    {
        printf ("\nerro ao criar o arquivo");
        exit(1);
    }

    while ((caractere = fgetc(fa)) != EOF)
    {
        if ((caractere >= 'a') && (caractere <= 'z'))
        {
            caractere = toupper(caractere);
        }

        fprintf (fb, "%c", caractere);
    }

    fclose(fa);
    fclose(fb);

    return 0;
}