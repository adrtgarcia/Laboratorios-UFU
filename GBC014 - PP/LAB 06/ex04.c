#include <stdio.h>
#include <string.h>

struct aluno
{
    char matricula[50], nome[100];
    float n1, n2, n3;
};
typedef struct aluno aluno;

int main ( )
{
    aluno dados[5];
    int cont, tamanho; 
    char nomeaux1[100], nomeaux2[100];
    float media, maior_n1, maiormedia, menormedia;

    for (cont = 0; cont < 5; cont++)
    {
        setbuf (stdin, NULL);

        printf ("digite o numero de matricula do aluno: ");
        fgets (dados[cont].matricula, 50, stdin);
        dados[cont].matricula[strcspn(dados[cont].matricula, "\n")] = '\0';

        printf ("digite o nome do aluno: ");
        fgets (dados[cont].nome, 100, stdin);
        dados[cont].nome[strcspn(dados[cont].nome, "\n")] = '\0';

        printf ("digite a nota da prova 1: ");
        scanf ("%f", &dados[cont].n1);

        printf ("digite a nota da prova 2: ");
        scanf ("%f", &dados[cont].n2);

        printf ("digite a nota da prova 3: ");
        scanf ("%f", &dados[cont].n3);

        printf ("\n");
    }

    maior_n1 = dados[0].n1;
    for (cont = 1; cont < 5; cont++)
    {
        if (dados[cont].n1 > maior_n1)
        {
            maior_n1 = dados[cont].n1;
            strcpy (nomeaux1, dados[cont].nome);
        }
    }
    printf ("%s tem a maior nota da prova 1 (%.2f)\n", nomeaux1, maior_n1);

    media = (dados[0].n1 + dados[0].n2 + dados[0].n3)/3;
    maiormedia = media;
    menormedia = media;

    for (cont = 1; cont < 5; cont++)
    {
        media = (dados[cont].n1 + dados[cont].n2 + dados[cont].n3)/3;
        
        if (media > maiormedia)
        {
            maiormedia = media;
            strcpy (nomeaux1, dados[cont].nome);
        }

        if (media < menormedia)
        {
            menormedia = media;
            strcpy (nomeaux2, dados[cont].nome);
        }
    }
    printf ("%s tem a maior media geral (%.2f)\n", nomeaux1, maiormedia);
    printf ("%s tem a menor media geral (%.2f)\n", nomeaux2, menormedia);

    for (cont = 0; cont < 5; cont++)
    {
        media = (dados[cont].n1 + dados[cont].n2 + dados[cont].n3)/3;

        if (media >= 6)
        {
            printf ("\n%s esta aprovado", dados[cont].nome);
        } else printf ("\n%s esta reprovado", dados[cont].nome);

    }

    return 0;
}