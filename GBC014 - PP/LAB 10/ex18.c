#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main ( )
{
    FILE *fp = NULL;
    char nome[100], prod[100];
    float preco, total = 0;

    printf ("digite o nome do arquivo: ");
    fgets (nome, 100, stdin);
    nome[strcspn(nome, "\n")] = '\0';

    fp = fopen (nome, "r");
    if (fp == NULL)
    {
        printf ("\nerro ao abrir o arquivo");
        exit(1);
    }

    while ((fscanf (fp, "%s %f", prod, &preco)) == 2)
    {
        total += preco;
    }

    printf ("\npreco total da compra: R$ %.2f", total);

    fclose(fp);

    return 0;
}