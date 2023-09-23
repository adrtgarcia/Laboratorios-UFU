#include <stdio.h>

int main ( )
{
    char string[100];
    int cont, qnts_1 = 0;
    
    printf ("digite uma sequencia de numeros: ");
    fgets (string, 100, stdin);

    for (cont = 0; cont < 100; cont++)
    {
        if (string[cont] == '1')
        {
            qnts_1++;
        } else continue;
    }

    printf ("o numero 1 aparece %dx na sequencia lida", qnts_1);

    return 0;
}