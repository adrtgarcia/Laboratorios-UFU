#include <stdio.h>
#include <string.h>

struct livro
{
    char titulo[30], autor[15];
    int ano;
};
typedef struct livro livro;

int main ( )
{
    livro l[5];
    int cont, quant;
    char pesquisa[30];

    printf ("registro de livros\n");
    for (cont = 0; cont < 5; cont++)
    {
        setbuf (stdin, NULL);
        
        printf ("digite o titulo: ");
        fgets (l[cont].titulo, 30, stdin);
        l[cont].titulo[strcspn(l[cont].titulo, "\n")] = '\0';

        printf ("digite o nome do autor: ");
        fgets (l[cont].autor, 15, stdin);
        l[cont].autor[strcspn(l[cont].autor, "\n")] = '\0';

        printf ("digite o ano: ");
        scanf ("%d", &l[cont].ano);

        printf ("\n");
    }

    printf ("qual livro deseja buscar?");
    printf ("\ndigite o titulo: ");
    fgets (pesquisa, 30, stdin);
    pesquisa[strcspn(pesquisa, "\n")] = '\0';

    for (cont = 0; cont < 5; cont++)
    {
        if (strcmp (pesquisa, l[cont].titulo) == 0)
        {
            printf ("\nlivro(s) encontrado(s):");
            printf ("\ntitulo: %s", l[cont].titulo);
            printf ("\nautor: %s", l[cont].autor);
            printf ("\nano: %d", l[cont].ano);
            quant++;
        }
    }

    if (quant == 0)
    {
        printf ("\nnenhum livro foi encontrado");
    }

    return 0;
}