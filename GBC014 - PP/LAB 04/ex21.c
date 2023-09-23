#include <stdio.h>

void piramide (int n);

int main ( )
{
    int num;
    printf ("digite um numero: ");
    scanf ("%d", &num);

    piramide (num);

    return 0;
}

void piramide (int n)
{
    int linha, coluna;
    
    for (linha = 1; linha <= n; linha++)
    {
        for (coluna = 1; coluna <= linha; coluna++)
        {
            printf ("!");
        }

        printf ("\n");
    }
}