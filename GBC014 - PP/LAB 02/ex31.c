#include <stdio.h>

int main ( )
{
    float alt, peso;
    printf ("digite sua altura: ");
    scanf ("%f", &alt);
    printf ("digite seu peso: ");
    scanf ("%f", &peso);

    if (alt < 1.20)
    {
        if (peso <= 60)
        {
            printf ("classificacao A");
        } else {
            if ((peso > 60) && (peso <= 90))
            {
                printf ("classificacao D");
            } else {
                printf ("classificacao G");
            }
        }
    }

    if ((alt >= 1.20) && (alt <= 1.70))
    {
        if (peso <= 60)
        {
            printf ("classificacao B");
        } else {
            if ((peso > 60) && (peso <= 90))
            {
                printf ("classificacao E");
            } else {
                printf ("classificacao H");
            }
        }
    }

    if (alt > 1.70)
    {
        if (peso <= 60)
        {
            printf ("classificacao C");
        } else {
            if ((peso > 60) && (peso <= 90))
            {
                printf ("classificacao F");
            } else {
                printf ("classificacao I");
            }
        }
    }

    return 0;
}