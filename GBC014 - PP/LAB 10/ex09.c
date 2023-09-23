#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main ( )
{
    FILE *fa = NULL, *fb = NULL, *fc = NULL;
    char arq1[100], arq2[100], arq3[100], letra;

    printf ("digite o nome do primeiro arquivo: ");
    fgets (arq1, 100, stdin);
    arq1[strcspn(arq1, "\n")] = '\0';

    fa = fopen(arq1, "r");
    if (fa == NULL)
    {
        printf ("\nerro ao abrir o arquivo");
        exit(1);
    }

    printf ("digite o nome do segundo arquivo: ");
    fgets (arq2, 100, stdin);
    arq2[strcspn(arq2, "\n")] = '\0';

    fb = fopen(arq2, "r");
    if (fb == NULL)
    {
        printf ("\nerro ao abrir o arquivo");
        exit(1);
    }

    printf ("digite o nome do novo arquivo: ");
    fgets (arq3, 100, stdin);
    arq3[strcspn(arq3, "\n")] = '\0';

    fc = fopen(arq3, "a");
    if (fc == NULL)
    {
        printf ("\nerro ao abrir o arquivo");
        exit(1);
    }

    while ((letra = fgetc(fa)) != EOF)
    {
        fprintf (fc, "%c", letra);
    }

    while ((letra = fgetc(fb)) != EOF)
    {
        fprintf (fc, "%c", letra);
    }

    fclose(fa);
    fclose(fb);
    fclose(fc);

    return 0;
}