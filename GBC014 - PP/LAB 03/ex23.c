#include <stdio.h>

int main ( )
{
    int num, linha, coluna, x = 0;
    printf ("digite um numero: ");
    scanf ("%d", &num);

    for (linha = 1; linha <= num; linha++)
    {
        for (coluna = 1; coluna <= linha; coluna++)
        {
            x++;
            printf ("%d ", x);
        }

        printf ("\n");
    }
    
    return 0;
}