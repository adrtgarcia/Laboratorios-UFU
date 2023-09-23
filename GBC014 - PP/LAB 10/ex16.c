#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main ( )
{
    FILE *fp = NULL;
    char nome[100], binario[100];
    int vet[10], i, j;

    printf ("digite os valores do vetor:\n");
    for (i = 0; i < 10; i++)
    {
        printf ("vet[%d] = ", i);
        scanf ("%d", &vet[i]);
    }

    setbuf (stdin, NULL);
    printf ("digite o nome do arquivo: ");
    fgets (nome, 100, stdin);
    nome[strcspn(nome, "\n")] = '\0';

    fp = fopen (nome, "w");
    if (fp == NULL)
    {
        printf ("\nerro ao abrir o arquivo");
        exit(1);
    }

    for (i = 0, j = 0; i < 10; i++)
    {
        while (vet[i] > 0)
        {
            binario[j] = (vet[i] % 2) + '0';
            vet[i] /= 2;
            j++;
        }
        binario[j] = '\0';

        fprintf(fp, "%s\n", binario);
    }

    fclose(fp);

    return 0;
}