#include <stdio.h>

struct infos
{
    char nome[100];
    int idade;
    char endereco[100];
};
typedef struct infos infos;

int main ( )
{
    infos pessoa;

    printf ("digite o nome: ");
    fgets (pessoa.nome, 100, stdin);
    printf ("digite a idade: ");
    scanf ("%d", &pessoa.idade);
    printf ("digite o enredeco: ");
    setbuf(stdin, NULL);
    fgets (pessoa.endereco, 100, stdin);

    return 0;
}