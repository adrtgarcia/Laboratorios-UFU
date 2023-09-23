#include <stdio.h>
#include <string.h>

int main ( )
{
    char modelo[5][100];
    float consumo[5], cons;
    int cont, economico;

    for (cont = 0; cont < 5; cont++)
    {
        printf ("digite o modelo do carro: ");
        scanf ("%s", modelo[cont]);
    }
    
    printf ("\n");
    for (cont = 0; cont < 5; cont++)
    {
        printf ("digite o consumo do modelo %s: ", modelo[cont]);
        scanf ("%s", consumo[cont]);
    }

    for (cont = 1, economico = 0; cont < 5; cont++)
    {
        if (consumo[cont] < consumo[economico])
        {
            economico = cont;
        }
    }
    printf ("\n%s eh o modelo mais economico\n", modelo[economico]);
    
    printf ("\n");
    for (cont = 0; cont < 5; cont++)
    {
        cons = 1000 / consumo[cont];
        printf ("o modelo %s consome %.2f litros de combustivel para percorrer 1000Km\n", modelo[cont], cons);
    }

    return 0;
}