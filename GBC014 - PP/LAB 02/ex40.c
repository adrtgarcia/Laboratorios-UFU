#include <stdio.h>

int main ( )
{
    float fab, total;
    printf ("digite o custo de fabrica: R$ ");
    scanf ("%f", &fab);

    if (fab <= 12000.00)
    {
        total = (fab * 1.05);
        printf ("custo total: R$ %.2f", total);
    } else {
        if ((fab > 12000.00) && (fab <= 25000.00))
        {
            total = (fab * 1.10) + (fab * 1.15);
            printf ("custo total: R$ %.2f", total);
        } else {
            total = (fab * 1.15) + (fab * 1.20);
            printf ("custo total: R$ %.2f", total);
        }
    }

    return 0;
}