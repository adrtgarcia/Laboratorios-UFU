#include <stdio.h>

int main ( )
{
    int cod, quant;
    float preco;

    printf ("digite o codigoo do produto: ");
    scanf ("%d", &cod);

    switch (cod)
    {
    case 100:
        printf ("digite a quantidade: ");
        scanf ("%d", &quant);
        preco = 1.20 * quant;
        printf ("total: R$ %.2f", preco);
        break;
    
    case 101:
        printf ("digite a quantidade: ");
        scanf ("%d", &quant);
        preco = 1.30 * quant;
        printf ("total: R$ %.2f", preco);
        break;

    case 102:
        printf ("digite a quantidade: ");
        scanf ("%d", &quant);
        preco = 1.50 * quant;
        printf ("total: R$ %.2f", preco);
        break;

    case 103:
        printf ("digite a quantidade: ");
        scanf ("%d", &quant);
        preco = 1.20 * quant;
        printf ("total: R$ %.2f", preco);
        break;

    case 104:
        printf ("digite a quantidade: ");
        scanf ("%d", &quant);
        preco = 1.70 * quant;
        printf ("total: R$ %.2f", preco);
        break;

    case 105:
        printf ("digite a quantidade: ");
        scanf ("%d", &quant);
        preco = 2.20 * quant;
        printf ("total: R$ %.2f", preco);
        break;
    
    case 106:
        printf ("digite a quantidade: ");
        scanf ("%d", &quant);
        preco = 1.00 * quant;
        printf ("total: R$ %.2f", preco);
        break;
    
    default:
        printf ("codigo invalido");
        break;
    }

    return 0;
}