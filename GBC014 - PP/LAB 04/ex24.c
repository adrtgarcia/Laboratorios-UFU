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
        for (coluna = 1; coluna <= (2 * n - 1); coluna++)
        {
            if ((coluna >= (n - linha + 1)) && (coluna <= (n + linha - 1)))
            {
                printf ("*");
            } else printf (" ");
        }

        printf ("\n");
    }
}