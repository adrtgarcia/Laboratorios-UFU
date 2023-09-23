#include <stdio.h>

int main ( )
{
    float ant, novo;
    printf ("digite o preco antigo: R$ ");
    scanf ("%f", &ant);
    
    if (ant <= 50)
    {
        novo = ant * 1.05;
        printf ("preco novo: R$ %.2f", novo);
    } else {
        if ((ant > 50) && (ant <= 100))
        {
            novo = ant * 1.10;
            printf ("preco novo: R$ %.2f", novo);
        } else {
            novo = ant * 1.15;
            printf ("preco novo: R$ %.2f", novo);
        }
    }

    return 0;
}