#include <stdio.h>

int main ( )
{
    int op;
    float x, y;

    do
    {
        printf ("Escolha a opcao:\n");
        printf ("\n1 - Soma de 2 numeros.\n");
        printf ("2 - Diferenca entre 2 numeros (maior pelo menor).\n");
        printf ("3 - Produto entre 2 numeros.\n");
        printf ("4 - Divisao entre 2 numeros (o denominador nao pode ser zero).\n");
        scanf ("%d", &op);

        if ((op < 1) || (op > 4))
        {
            printf ("Opcao invalida.");
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

        if (x > y)
        {
            printf ("resultado: %.2f", x-y);
        } else {
            if (x < y)
            {
                printf ("resultado: %.2f", y-x);
            } else {
                printf ("resultado: %.2f", x-y);
            }
        }
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
        
        if ((y > 0) || (y < 0))
        {
            printf ("resultado: %.2f", x/y);
        } else {
            printf ("o denominador nao pode ser zero");
        }
        break;
    }
    
    return 0;
}