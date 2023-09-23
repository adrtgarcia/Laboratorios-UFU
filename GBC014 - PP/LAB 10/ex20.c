#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main ( )
{
    int num, i;
    char **nomes;
    float *notas;
    FILE *fp = NULL;

    printf ("digite o número de alunos: ");
    scanf ("%d", &num);

    nomes = (char **) calloc (num, (sizeof(char *)));
    notas = (float *) calloc (num, (sizeof(float)));

    for (i = 0; i < num; i++)
    {
        nomes[i] = (char *) calloc ((40 + 1), (sizeof(char)));

        setbuf (stdin, NULL);
        printf ("digite o nome: ");
        fgets (nomes[i], 40, stdin);
        nomes[strcspn(nomes, "\n")] = '\0';

        printf("digite a nota final: ");
        scanf("%f", &notas[i]);
    }

    fp = fopen ("alunos.txt", "w");
    if (fp == NULL) 
    {
        printf("\nerro ao criar o arquivo");
        exit(1);
    }

    for (i = 0; i < num; i++) 
    {
        fprintf(fp, "%40s %.2f\n", nomes[i], notas[i]);
    }

    fclose(fp);

    for (int i = 0; i < num; i++) 
    {
        free(nomes[i]);
    }
    
    free(notas);

    return 0;
}