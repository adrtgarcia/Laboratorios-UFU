#include <stdio.h>
#include <string.h>

int main ( )
{
    char nome[100];
    float preco, desconto, pagar;

    printf ("digite o nome da mercadoria: ");
    fgets (nome, 100, stdin);
    printf ("digite o valor da mercadoria: ");
    scanf ("%f", &preco);

    desconto = preco*0.10;
    pagar = preco - desconto;

    printf ("\nmercadoria: %s", nome);
    printf ("valor total: %.2f", preco);
    printf ("\nvalor do desconto: %.2f", desconto);
    printf ("\nvalor a ser pago: %.2f", pagar);

    return 0;
}