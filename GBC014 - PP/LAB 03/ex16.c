#include <stdio.h>

int main ( )
{
    int op, x, y;

    do
    {
        printf ("\nmenu de operacoes:\n");
        printf ("\n(1) adicao");
        printf ("\n(2) subtracao");
        printf ("\n(3) multiplicacao");
        printf ("\n(4) divisao");
        printf ("\n(5) saida\n");
        scanf ("%d", &op);

        switch (op)
        {
        case 1:
            printf ("\ndigite o primeiro valor: ");
            scanf ("%d", &x);
            printf ("digite o segundo valor: ");
            scanf ("%d", &y);
            printf ("\nresultado: %d\n", x+y);
            break;
        
        case 2:
            printf ("\ndigite o primeiro valor: ");
            scanf ("%d", &x);
            printf ("digite o segundo valor: ");
            scanf ("%d", &y);
            printf ("\nresultado: %d\n", x-y);
            break;
        
        case 3:
            printf ("\ndigite o primeiro valor: ");
            scanf ("%d", &x);
            printf ("digite o segundo valor: ");
            scanf ("%d", &y);
            printf ("\nresultado: %d\n", x*y);
            break;

        case 4:
            printf ("\ndigite o primeiro valor: ");
            scanf ("%d", &x);
            printf ("digite o segundo valor: ");
            scanf ("%d", &y);
            printf ("\nresultado: %d\n", x/y);
            break;

        case 5:
            break;
        }

    } while (op != 5);

    return 0;
}