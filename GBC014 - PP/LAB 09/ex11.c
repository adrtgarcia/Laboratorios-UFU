#include <stdio.h>
#include <stdlib.h>

struct registro
{
    char mat[10], sobrenome[50];
    int ano;
};
typedef struct registro registro;

int main ( )
{
    int num, i;
    registro *r = NULL;
    
    printf ("informe o numero de alunos: ");
    scanf ("%d", &num);
    setbuf (stdin, NULL);

    r = (registro *) calloc (num, (sizeof(registro)));
    if (r == NULL)
    {
        printf ("\nerro: memoria insuficiente");
        exit(1);
    }

    printf ("\ndigite as informacoes dos alunos:\n");
    for (i = 0; i < num; i++)
    {
        setbuf (stdin, NULL);
        printf ("matricula: ");
        fgets (r[i].mat, 10, stdin);
        printf ("sobrenome: ");
        fgets (r[i].sobrenome, 50, stdin);
        printf ("ano de nascimento: ");
        scanf ("%d", &r[i].ano);
        printf ("\n");
    }

    printf ("\ninformacoes registradas:\n");
    for (i = 0; i < num; i++)
    {
        printf ("matricula: %s", r[i].mat);
        printf ("sobrenome: %s", r[i].sobrenome);
        printf ("ano de nascimento: %d", r[i].ano);
        printf ("\n\n");
    }

    free(r);
    
    return 0;
}