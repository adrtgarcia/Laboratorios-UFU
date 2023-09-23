#include <stdio.h>      //fopen, feof
#include <stdlib.h>     //exit

int main ( )
{
    FILE *fp = NULL;
    char nome[100];
    int n1, n2, n3, media;
    
    fp = fopen ("notas.txt", "r");
    if (fp == NULL)
    {
        printf ("\nerro ao abrir o arquivo");
        exit(1);
    }

    while ((fscanf (fp, "%s %d %d %d", &nome, &n1, &n2, &n3)) == 4)
    {
        media = (n1 + n2 + n3) / 3;

        if (media >= 6)
        {
            printf ("\nnome: %s", nome);
            printf ("\nmedia final: %d", media);
            printf ("\naprovado\n");
        } else {
            printf ("\nnome: %s", nome);
            printf ("\nmedia final: %d", media);
            printf ("\nreprovado\n");
        }
    }

    return 0;
}