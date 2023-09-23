#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main ( )
{
    FILE *fa = NULL, *fb = NULL;
    char arq1[100], arq2[100], pessoa[100];
    int ano, ano_nasc, idade;

    printf ("digite o nome do arquivo de entrada: ");
    fgets(arq1, 100, stdin);
    arq1[strcspn(arq1, "\n")] = '\0';

    fa = fopen (arq1, "r");
    if (fa == NULL)
    {
        printf ("\nerro ao abrir o arquivo");
        exit(1);
    }

    printf ("digite o nome do arquivo de saida: ");
    fgets(arq2, 100, stdin);
    arq2[strcspn(arq2, "\n")] = '\0';

    fb = fopen (arq2, "w");
    if (fb == NULL)
    {
        printf ("\nerro ao abrir o arquivo");
        exit(1);
    }

    printf ("digite o ano atual: ");
    scanf ("%d", &ano);

    while (!feof(fa))
    {
        fscanf(fa, "%40s %d", pessoa, &ano_nasc);

        idade = ano - ano_nasc;
        
        if (idade < 18)
        {
            fprintf (fb, "%s %s\n", pessoa, "eh menor de idade");
        } else if (idade > 18)
        {
            fprintf (fb, "%s %s\n", pessoa, "eh maior de idade");
        } else {
            fprintf (fb, "%s %s\n", pessoa, "entrando na maior idade");
        }
    }

    fclose(fa);
    fclose(fb);

    return 0;
}