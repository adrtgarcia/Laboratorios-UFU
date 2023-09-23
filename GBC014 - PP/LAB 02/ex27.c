#include <stdio.h>

int main ( )
{
    int idd;
    printf ("digite sua idade: ");
    scanf ("%d", &idd);

    if ((idd >= 5) && (idd <= 7))
    {
        printf ("sua categoria: Infantil A");
    } else {
        if ((idd >= 8) && (idd <= 10))
        {
            printf ("sua categoria: Infatil B");
        } else {
            if ((idd >= 11) && (idd <= 13))
            {
                printf ("sua categoria: Juvenil A");
            } else {
                if ((idd >= 14) && (idd <= 17))
                {
                    printf ("sua categoria: Juvenil B");
                } else {
                    printf ("sua categoria: Senior");
                }
            }
        }
    }

    return 0;
}