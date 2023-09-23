#include <stdio.h>
#include <string.h>

struct filme
{
    char nome[20];
    int ano, duracao;
};
typedef struct filme filme;

struct diretor
{
    char nome[20];
    int quant;
    filme f[];
};
typedef struct diretor diretor;

int main ( )
{
    diretor d[5];
    int cont1, cont2;
    char pesquisa[20];

    for (cont1 = 0; cont1 < 5; cont1++)
    {
        setbuf (stdin, NULL);

        printf ("digite o nome do diretor: ");
        fgets (d[cont1].nome, 20, stdin);
        d[cont1].nome[strcspn(d[cont1].nome, "\n")] = '\0';

        printf ("digite quantos filmes foram produzidos: ");
        scanf ("%d", &d[cont1].quant);

        printf ("\n");

        for (cont2 = 0; cont2 < d[cont1].quant; cont2++)
        {
            setbuf (stdin, NULL);

            printf ("digite o nome do filme: ");
            fgets (d[cont1].f[cont2].nome, 20, stdin);
            d[cont1].f[cont2].nome[strcspn(d[cont1].f[cont2].nome, "\n")] = '\0';

            printf ("digite o ano de lancamento do filme: ");
            scanf ("%d", &d[cont1].f[cont2].ano);

            printf ("digite a duracao do filme, em minutos: ");
            scanf ("%d", &d[cont1].f[cont2].duracao);

            printf ("\n");
        }
    }

    setbuf (stdin, NULL);
    printf ("\ndigite o nome do diretor que deseja procurar: ");
    fgets (pesquisa, 20, stdin);
    pesquisa[strcspn(pesquisa, "\n")] = '\0';

    for (cont1 = 0; cont1 < 5; cont1++)
    {
        if (strcmp (pesquisa, d[cont1].nome) == 0)
        {
            printf ("\nfilmes encontrados:\n");

            for (cont2 = 0; cont2 < d[cont1].quant; cont2++)
            {
                printf ("\nnome: %s", d[cont1].f[cont2].nome);
                printf ("\nano: %d", d[cont1].f[cont2].ano);
                printf ("\nduracao: %d min", d[cont1].f[cont2].duracao);
                printf ("\n");
            }
            
            break;
        }
    }

    return 0;
}