#include <stdio.h>

int main ( )
{
    float valor, preco;
    int estado;

    printf ("digite o valor do produto: ");
    scanf ("%f", &valor);

    do{
    printf ("\nselecione o estado destino:");
    printf ("\n(1) MG\n");
    printf ("(2) SP\n");
    printf ("(3) RJ\n");
    printf ("(4) MS\n");
    scanf ("%d", &estado);

    if ((estado < 1) || (estado > 4))
    {
        printf ("o estado escolhido nao eh valido\n");
    }
    } while ((estado < 1) || (estado > 4));

    switch (estado)
    {
    case 1:
        preco = valor * 1.07;
        printf ("\npreco final: R$ %.2f", preco);
        break;
    
    case 2:
        preco = valor * 1.12;
        printf ("\npreco final: R$ %.2f", preco);
        break;

    case 3:
        preco = valor * 1.15;
        printf ("\npreco final: R$ %.2f", preco);
        break;

    case 4:
        preco = valor * 1.08;
        printf ("\npreco final: R$ %.2f", preco);
        break;
    }

    return 0;
}