#include <stdio.h>

int main ( )
{
    int nasc, ano, idade_atual, idade_2030;

    printf ("digite seu ano de nascimento: ");
    scanf ("%d", &nasc);

    printf ("digite o ano atual: ");
    scanf ("%d", &ano);

    idade_atual = ano - nasc;
    printf ("\nvoce tem %d anos", idade_atual);

    idade_2030 = 2030 - nasc;
    printf ("\nem 2030, voce tera %d anos", idade_2030);

    return 0;
}
