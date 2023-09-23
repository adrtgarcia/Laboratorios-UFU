#include <stdio.h>

struct aluno
{
    char nome[100];
    char matricula[50];
    char curso[100];
};
typedef struct aluno aluno;

int main ( )
{
    aluno dados[5];
    int cont;

    for (cont = 0; cont < 5; cont++)
    {
        printf ("digite o nome do aluno: ");
        fgets (dados[cont].nome, 100, stdin);
        printf ("digite o numero de matricula: ");
        fgets (dados[cont].matricula, 50, stdin);
        printf ("digite o curso: ");
        fgets (dados[cont].curso, 100, stdin);

        printf ("\n");
    }

    printf ("dados armazenados:\n\n");
    for (cont = 0; cont < 5; cont++)
    {
        printf ("nome: %s", dados[cont].nome);
        printf ("numero de matricula matricula: %s", dados[cont].matricula);
        printf ("curso: %s", dados[cont].curso);

        printf ("\n");
    }

    return 0;
}