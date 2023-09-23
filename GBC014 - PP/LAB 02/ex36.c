#include <stdio.h>

int main ( )
{
    float ven, com;
    printf ("digite o valor da venda: R$ ");
    scanf ("%f", &ven);

    if (ven >= 100000.00)
    {
        com = 700.00 + (1.16 * ven);
        printf ("comissao: R$ %.2f", com);
    } else {
        if ((ven < 100000.00) && (ven >= 80000.00))
        {
            com = 650.00 + (1.14 * ven);
            printf ("comissao: R$ %.2f", com);
        } else {
            if ((ven < 80000.00) && (ven >= 60000.00))
            {
                com = 600.00 + (1.14 * ven);
                printf ("comissao: R$ %.2f", com);
            } else {
                if ((ven < 60000.00) && (ven >= 40000.00))
                {
                    com = 550.00 + (1.14 * ven);
                    printf ("comissao: R$ %.2f", com);
                } else {
                    if ((ven < 40000.00) && (ven >= 20000.00))
                    {
                        com = 500.00 + (1.14 * ven);
                        printf ("comissao: R$ %.2f", com);
                    } else {
                        if (ven < 20000.00)
                        {
                            com = 400.00 + (1.14 * ven);
                            printf ("comissao: R$ %.2f", com);
                        }
                    }
                }
            }
        }
    }

    return 0;
}