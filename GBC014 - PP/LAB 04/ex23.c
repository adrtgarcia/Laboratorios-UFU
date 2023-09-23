#include <stdio.h>

void piramide (int n);

int main ( )
{
    int num, altura, largura;
    printf ("digite um numero: ");
    scanf ("%d", &num);

    piramide (num);

    return 0;
}

void piramide (int n)
{
    int linha, coluna;
    
    for (linha = 1; linha <= (2 * n - 1); linha++)
    {
        if (linha <= n)
        {
            for (coluna = 1; coluna <= linha; coluna++)
            {
                printf ("*");
            }
        } else {
            for (coluna = 1; coluna <= (2 * n - linha); coluna++)
            {
                printf ("*");
            }
        }
        printf ("\n");
    }
}