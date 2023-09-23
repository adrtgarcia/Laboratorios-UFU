#include <stdio.h>
#include <string.h>

struct pessoa
{
    char nome[100], end[100], tel[15]; 
};
typedef struct pessoa pessoa;

int main ( )
{
    pessoa p[5], temporario;
    int cont1, cont2;

    for (cont1 = 0; cont1 < 5; cont1++)
    {
        printf ("digite o nome: ");
        fgets (p[cont1].nome, 100, stdin);
        p[cont1].nome[strcspn(p[cont1].nome, "\n")] = '\0';

        printf ("digite o endereco: ");
        fgets (p[cont1].end, 100, stdin);
        p[cont1].end[strcspn(p[cont1].end, "\n")] = '\0';

        printf ("digite o telefone: ");
        fgets (p[cont1].tel, 10, stdin);
        p[cont1].tel[strcspn(p[cont1].tel, "\n")] = '\0';

        printf ("\n");
    }

    for (cont1 = 0; cont1 < 4; cont1++)
    {
        for (cont2 = cont1 + 1; cont2 < 5; cont2++)
        {
            if (strcmp (p[cont1].nome, p[cont2].nome) > 0)
            {
                temporario = p[cont1];
                p[cont1] = p[cont2];
                p[cont2] = temporario;
            }
        }
    }

    printf ("\ndados registrados:\n");
    for (cont1 = 0; cont1 < 5; cont1++)
    {
        printf ("\nnome: %s", p[cont1].nome);
        printf ("\nendereco: %s", p[cont1].end);
        printf ("\ntelefone: %s", p[cont1].tel);
        printf ("\n");
    }

    return 0;
}