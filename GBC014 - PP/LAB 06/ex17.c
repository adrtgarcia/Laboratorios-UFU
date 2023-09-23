#include <stdio.h>

struct energia 
{
    char nome[15];
    float pot, tempo;
};
typedef struct energia energia;

int main ( )
{
    energia eletro[5];
    int t, cont;
    float contotal = 0.0, conrelat = 0.0;

    for (cont = 0; cont < 5; cont++)
    {
        setbuf (stdin, NULL);

        printf ("digite o nome do eletrodomestico: ");
        fgets (eletro[cont].nome, 15, stdin);
        eletro[cont].nome[strcspn(eletro[cont].nome, "\n")] = '\0';

        printf ("digite a potencia, em kW, dele: ");
        scanf ("%f", &eletro[cont].pot);

        printf ("digite o tempo ativo, em horas, dele: ");
        scanf ("%f", &eletro[cont].tempo);

        printf ("\n");
    }

    printf ("digite um parametro t em numero de dias: ");
    scanf ("%d", &t);

    for (cont = 0; cont < 5; cont++)
    {
        contotal += (eletro[cont].pot * eletro[cont].tempo * t);
    }

    printf ("\no consumo total na casa eh de %.2f kW", contotal);
    
    for (cont = 0; cont < 5; cont++)
    {
        conrelat = (eletro[cont].pot * eletro[cont].tempo * t) / contotal;
        printf ("\no consumo relativo de %s eh de %.2f kW", eletro[cont].nome, conrelat);
    }

    return 0;
}