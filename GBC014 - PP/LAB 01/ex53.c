#include <stdio.h>
// leia as DIMENSÕES de um terreno, o PREÇO POR METRO de tela, imprima o CUSTO da tela

int main ( )
{
    float c, l, p;
    printf ("comprimento do terreno: ");
    scanf ("%f", &c);

    printf ("largura do terreno: ");
    scanf ("%f", &l);

    printf ("preco do metro de tela: ");
    scanf ("%f", &p);

    float ptotal = (c * l) * p;
    printf ("custo total: R$ %.2f", ptotal);

    return 0;
}