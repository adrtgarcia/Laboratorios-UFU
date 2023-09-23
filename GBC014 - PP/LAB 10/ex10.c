#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct cidade
{
    char nome[40];
    int habitantes;
};
typedef struct cidade cidade;

int main ( )
{
    FILE *fa = NULL, *fb = NULL;
    char arq1[100], arq2[100];
    cidade cid[100];
    int num = 0, maxhab = 0, i;

    printf ("digite o nome do arquivo de entrada: ");
    fgets (arq1, 100, stdin);
    arq1[strcspn(arq1, "\n")] = '\0';

    fa = fopen(arq1, "r");
    if (fa == NULL)
    {
        printf ("\nerro ao abrir o arquivo");
        exit(1);
    }

    printf ("digite o nome do arquivo de saída: ");
    fgets (arq2, 100, stdin);
    arq2[strcspn(arq2, "\n")] = '\0';

    fb = fopen(arq2, "w");
    if (fb == NULL)
    {
        printf ("\nerro ao abrir o arquivo");
        exit(1);
    }

    while ((fscanf (arq1, "%40s %d", &cid[num].nome)) == 2)
    {
        if (cid[num].habitantes > maxhab) 
        {
            maxhab = cid[num].habitantes;
            i = num;
        }

        num++;
    }

    fclose(fa);
    fclose(fb);

    return 0;
}