#include <stdio.h>

int main ( )
{
    int num1, num2, produto, contrario, aux, maiorp = 0;
    
    for (num1 = 100; num1 <= 999; num1++)
    {
        for (num2 = num1; num2 <= 999; num2++)
        {
            produto = num1*num2; 
            aux = produto;
            contrario = 0;

            while (aux != 0)
            {
                contrario = contrario*10 + aux%10;
                aux = aux/10;
            }

            if ((contrario == produto) && (produto > maiorp))
            {
                maiorp = produto;
            }
        }
    }

    printf ("maior palindromo: %d", maiorp);

    return 0;
}