#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main ( )
{
    FILE *fa = NULL, *fb = NULL;
    char nome[100], pessoa[100];
    int dia, mes, ano, dia_nasc, mes_nasc, ano_nasc, idade;

    printf ("digite o nome do arquivo: ");
    fgets(nome, 100, stdin);
    nome[strcspn(nome, "\n")] = '\0';

    fa = fopen (nome, "r");
    if (fa == NULL)
    {
        printf ("\nerro ao abrir o arquivo");
        exit(1);
    }

    printf ("digite a data atual (DD/MM/AAAA): ");
    scanf ("%d/%d/%d", &dia, &mes, &ano);

    fb = fopen ("idade.txt", "w");
    if (fb == NULL)
    {
        printf ("\nerro ao criar o arquivo");
        exit(1);
    }

    while (!feof(fa))
    {
        fscanf(fa, "%s %d/%d/%d", pessoa, &dia_nasc, &mes_nasc, &ano_nasc);

        idade = ano - ano_nasc;

        if ((mes < mes_nasc) || ((mes == mes_nasc) && (dia < dia_nasc)))
        {
            idade -= 1;
        }

        fprintf(fb, "%s %d\n", pessoa, idade);
    }
    

    fclose(fa);
    fclose(fb);

    return 0;
}