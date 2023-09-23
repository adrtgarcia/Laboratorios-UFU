#include <stdio.h>
#include <string.h>

int main ( )
{
    char frase[100], codigo[100];
    int tamanho, cont;

    printf ("digite a frase a ser codificada: ");
    fgets (frase, 100, stdin);
    tamanho = strlen(frase);

    for (cont = 0; cont < tamanho; cont++)
    {
        if ((frase[cont] >= 'a') && (frase[cont] <= 'z'))
        {
            codigo[cont] = frase[cont] - 32 + 3;

            if (codigo[cont] > 'Z')
            {
                codigo[cont] -= 26;
            }

        } else if ((frase[cont] >= 'A') && (frase[cont] <= 'Z'))
        {
            codigo[cont] = frase[cont] + 3;
            
            if ((codigo[cont] > 'Z') && (codigo[cont] < 'a'))
            {
                codigo[cont] -= 26;
            } else if (codigo[cont] > 'z')
            {
                codigo[cont] -= 26;
            }
            
        } else codigo[cont] = frase[cont];
    }

    codigo[cont] = '\0';

    printf ("frase codificada: %s", codigo);

    return 0;
}