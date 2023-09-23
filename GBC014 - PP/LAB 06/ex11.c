#include <stdio.h>
#include <string.h>

struct aluno
{
    char nome[100], mat[20];
    float mfinal;
};
typedef struct aluno aluno;

int main ( )
{
    aluno a[10], aprov[10], repro[10];
    int cont, numaprov, numrepro, tamanho;

    for (cont = 0, numaprov = 0, numrepro = 0; cont < 10; cont++)
    {
        setbuf (stdin, NULL);

        printf ("digite o nome do aluno: ");
        fgets (a[cont].nome, 100, stdin);
        a[cont].nome[strcspn(a[cont].nome, "\n")] = '\0';

        printf ("digite a matricula: ");
        fgets (a[cont].mat, 20, stdin);
        a[cont].mat[strcspn(a[cont].mat, "\n")] = '\0';

        printf ("digite a media final: ");
        scanf("%f", &a[cont].mfinal);

        printf ("\n");

        if (a[cont].mfinal >= 5.0)
        {
            aprov[numaprov] = a[cont];
            numaprov++;
        } else {
            repro[numrepro] = a[cont];
            numrepro++;
        }
    }

    printf ("\nlista dos aprovados\n");
    for (cont = 0; cont < numaprov; cont++)
    {
        printf ("\nnome: %s", aprov[cont].nome);
        printf ("\nmatricula: %s", aprov[cont].mat);
        printf ("\nmedia final: %.2f", aprov[cont].mfinal);
        printf ("\n");
    }

    printf ("\nlista dos reprovados\n");
    for (cont = 0; cont < numrepro; cont++)
    {
        printf ("\nnome: %s", repro[cont].nome);
        printf ("\nmatricula: %s", repro[cont].mat);
        printf ("\nmedia final: %.2f", repro[cont].mfinal);
        printf ("\n");
    }
    
    return 0;
}