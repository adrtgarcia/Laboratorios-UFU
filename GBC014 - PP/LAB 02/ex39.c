#include <stdio.h>

int main ( )
{
    float sal_atual, sal_novo;
    int tempo;

    printf ("digite o salario atual: R$ ");
    scanf ("%f", &sal_atual);
    printf ("digite o tempo de servico (em anos): ");
    scanf ("%d", &tempo);

    if (sal_atual <= 500.00)
    {
       sal_novo = sal_atual * 1.25;
    } else {
        if ((sal_atual > 500.00) && (sal_atual <= 1000.00))
        {
            sal_novo = sal_atual * 1.20;
        } else {
            if ((sal_atual > 1000.00) && (sal_atual <= 1500.00))
            {
                sal_novo = sal_atual * 1.15;
            } else {
                if ((sal_atual > 1500.00) && (sal_atual <= 2000.00))
                {
                    sal_novo = sal_atual * 1.10;
                } else {
                    if (sal_atual > 2000.00)
                    {
                        sal_novo = sal_atual;
                    }
                }
            }
        }
    }

    if (tempo < 1)
    {
        printf ("salario reajustado: R$ %.2f", sal_novo);
    } else {
        if ((tempo >= 1) && (tempo <= 3))
        {
            printf ("salario reajustado: R$ %.2f", sal_novo + 100.00);
        } else {
            if ((tempo >= 4) && (tempo <= 6))
            {
                printf ("salario reajustado: R$ %.2f", sal_novo + 200.00);
            } else {
                if ((tempo >= 7) && (tempo <= 10))
                {
                    printf ("salario reajustado: R$ %.2f", sal_novo + 300.00);
                } else {
                    if (tempo > 10)
                    {
                        printf ("salario reajustado: R$ %.2f", sal_novo + 500.00);
                    }
                }
            }
        }
    }

    return 0;
}