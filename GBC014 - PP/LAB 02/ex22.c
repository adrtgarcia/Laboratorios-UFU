#include <stdio.h>

int main ( )
{
    int idd, trab;
    printf ("digite sua idade: ");
    scanf ("%d", &idd);
    printf ("digite seu tempo de servico, em anos: ");
    scanf ("%d", &trab);

    if (idd == 65)
    {
        printf ("pode se aposentar");
    } else {
        if (trab == 30)
        {
            printf ("pode se aposentar");
        } else {
            if ((idd == 60) && (trab == 25))
            {
                printf ("pode se aposentar");
            } else {
                printf ("ainda nao pode se aposentar");
            }
        }
    }

    return 0;
}