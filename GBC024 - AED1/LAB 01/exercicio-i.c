#include <stdio.h>
#include <string.h>

struct livro
{
    char titulo[100];
    int ano, pags;
    float preco;
};
typedef struct livro livro;

int main ( )
{
    livro lvs[5];
    int i;
    float media = 0;

    printf ("digite as informacoes de cada livro:");

    for (i = 0; i < 5; i++)
    {
        setbuf (stdin, NULL);
        printf ("\ntitulo: ");
        fgets (lvs[i].titulo, 100, stdin);
        lvs[i].titulo[strcspn(lvs[i].titulo, "\n")] = '\0';

        printf ("ano de edicao: ");
        scanf ("%d", &lvs[i].ano);

        printf ("numero de paginas: ");
        scanf ("%d", &lvs[i].pags);
        media += lvs[i].pags;

        printf ("preco: R$ ");
        scanf ("%f", &lvs[i].preco);
    }

    printf ("\na media do numero de paginas dos livros eh de %.2f paginas", (media/5.0));

    return 0;
}
