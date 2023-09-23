#include <stdio.h>
#include <string.h>

struct aluno
{
    char matricula[50], nome[100], codigo[50];
    float n1, n2;
};
typedef struct aluno aluno;

float media (float a, float b);

int main ( )
{
    aluno dados[10];
    int cont;

    for (cont = 0; cont < 10; cont++)
    {
        setbuf (stdin, NULL);

        printf ("digite a matricula do aluno: ");
        fgets (dados[cont].matricula, 50, stdin);
        dados[cont].matricula[strcspn(dados[cont].matricula, "\n")] = '\0';

        printf ("digite o nome do aluno: ");
        fgets (dados[cont].nome, 50, stdin);
        dados[cont].nome[strcspn(dados[cont].nome, "\n")] = '\0';

        printf ("digite o codigo da disciplina: ");
        fgets (dados[cont].codigo, 50, stdin);
        dados[cont].codigo[strcspn(dados[cont].codigo, "\n")] = '\0';

        printf ("digite a nota 1: ");
        scanf ("%f", &dados[cont].n1);

        printf ("digite a nota 2: ");
        scanf ("%f", &dados[cont].n2);

        printf ("\n");
    }

    for (cont = 0; cont < 10; cont++)
    {
        printf ("aluno: %s\n", dados[cont].nome);
        printf ("media final: %.2f\n", media(dados[cont].n1, dados[cont].n2));
    }

    return 0;
}

float media (float a, float b)
{
    a *= 1.0;
    b *= 2.0;

    return ((a + b)/3.0);
}