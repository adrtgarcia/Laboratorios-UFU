#include <stdio.h>

int main ( )
{
    int op;
    float x, y;

    do
    {
        printf ("escolha uma opcao: \n");
        printf ("\n(1) adicao\n");
        printf ("(2) subtracao\n");
        printf ("(3) multiplicacao\n");
        printf ("(4) divisao\n");
        scanf ("%d", &op);

        if ((op < 1) || (op > 4))
        {
            printf ("\nopcao invalida, tente novamente\n");
        }
    } while ((op < 1) || (op > 4));

    switch (op)
    {
    case 1:
        printf ("digite o primeiro numero: ");
        scanf ("%f", &x);
        printf ("digite o segundo numero: ");
        scanf ("%f", &y);
        printf ("resultado: %.2f", x+y);
        break;
    case 2:
        printf ("digite o primeiro numero: ");
        scanf ("%f", &x);
        printf ("digite o segundo numero: ");
        scanf ("%f", &y);
        printf ("resultado: %.2f", x-y);
        break;
    case 3:
        printf ("digite o primeiro numero: ");
        scanf ("%f", &x);
        printf ("digite o segundo numero: ");
        scanf ("%f", &y);
        printf ("resultado: %.2f", x*y);
        break;
    case 4:
        printf ("digite o primeiro numero: ");
        scanf ("%f", &x);
        printf ("digite o segundo numero: ");
        scanf ("%f", &y);
        printf ("resultado: %.2f", x/y);
        break;
    }

    return 0;
}