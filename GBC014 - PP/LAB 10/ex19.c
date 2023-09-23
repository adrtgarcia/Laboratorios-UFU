#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main ( )
{
    FILE *fp = NULL;
    char nome[100], aluno[100], maior_aluno[100];
    float nota, maior_nota;

    printf ("digite o nome do arquivo: ");
    fgets (nome, 100, stdin);
    nome[strcspn(nome, "\n")] = '\0';

    fp = fopen (nome, "r");
    if (fp == NULL)
    {
        printf ("\nerro ao abrir o arquivo");
        exit(1);
    }

    maior_nota = -1;

    while (!feof(fp))
    {
        fscanf(fp, "NOME: %s NOTA: %f", aluno, &nota);
    
        if (nota > maior_nota)
        {
            maior_nota = nota;
            strcpy(maior_aluno, aluno);
        }
    }

    printf ("\naluno com maior nota:");
    printf ("\nnome: %s", maior_aluno);
    printf ("\nnota: %.2f", maior_nota);

    fclose(fp);

    return 0;
}