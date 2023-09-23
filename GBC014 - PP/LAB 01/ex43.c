#include <stdio.h>
//programa de ajuda para vendedores

int main ( )
{
    float valor;
    printf ("digite o valor total: ");
    scanf ("%f", &valor);

    float desc = valor * 0.90; //total a pagar com desconto de 10%
    printf ("total a pagar com desconto: R$ %.2f \n", desc);

    float parc = valor / 3; //parcelamento de 3x sem juros
    printf ("valor de cada parcela: R$ %.2f \n", parc);

    float comv = desc * 1.05; //comissão do vendedor, venda à vista (5% sobre desc)
    printf ("comissao do vendedor (venda a vista): R$ %.2f \n", comv);

    float comp = valor * 1.05; //comissão do vendedor, venda parcelada (5% sobre o valor total)
    printf ("comissao do vendedor (venda parcelada): R$ %.2f \n", comp);

    return 0;
}