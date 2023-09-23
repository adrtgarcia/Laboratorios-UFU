#include <stdio.h>
// calcule ANO DE NASCIMENTO a partir da IDADE e do ANO ATUAL;

int main ( )
{
    int idade, ano;
    printf ("informe sua idade: ");
    scanf ("%d", &idade);

    printf ("informe o ano atual: ");
    scanf ("%d", &ano);

    int nasc = ano - idade;
    printf ("seu ano de nascimento: %d", nasc);

    return 0;
}