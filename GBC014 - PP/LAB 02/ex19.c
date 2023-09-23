#include <stdio.h>

int main ( )
{
    int num;
    printf ("digite um numero: ");
    scanf ("%d", &num);

    if ((num%3 == 0) && (num%5 != 0))
    {
        printf ("eh divisivel por 3, mas nao por 5");
    } else {
        if ((num%3 != 0) && (num%5 == 0))
        {
            printf ("eh divisivel por 5, mas nao por 3");
        } else {
            if ((num%3 == 0) && (num%5 == 0))
            {
                printf ("eh divisivel por 3 e por 5");
            } else {
                printf ("nao eh divisivel por 3 nem por 5");
            }
        }
    }

    return 0;
}