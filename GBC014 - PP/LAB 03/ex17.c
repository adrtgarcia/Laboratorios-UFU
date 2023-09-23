#include <stdio.h>

int main ( )
{
    int c = 150, z = 110, ano = 0;

    while (z <= c)
    {
        c += 2;
        z += 3;
        ano++;
    }
    
    printf ("serao necessarios %d anos para que Ze seja maior que Chico", ano);

    return 0;
}