#include <stdio.h>

int quadrado_perf (int x);

int main ( )
{
    int num;
    
    do 
    {
        printf ("digite um numero: ");
        scanf ("%d", &num);

        if (num <= 0)
        {
            printf ("o numero precisa ser maior que zero\n\n");
        }

    } while (num <= 0);

    if (quadrado_perf (num))
    {
        printf ("%d eh um quadrado perfeito", num);
    } else printf ("%d nao eh quadrado perfeito", num);

    return 0;
}

int quadrado_perf (int x) 
{
    int y;

    for (y = 1; y * y <= x; y++) 
    {
        if (y * y == x) 
        {
            return 1;
        }
    }
    return 0;
}
