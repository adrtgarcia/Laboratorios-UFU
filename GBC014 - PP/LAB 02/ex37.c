#include <stdio.h>

int main ( )
{
    int hcheg, hpart, mincheg, minpart, duracao, hora;
    float preco;

    printf ("em HH:MM, insira a hora e minuto de chegada: ");
    scanf ("%d:%d", &hcheg, &mincheg);
    printf ("em HH:MM, insira a hora e minuto de partida: ");
    scanf ("%d:%d", &hpart, &minpart);

    if (hcheg < hpart)
    {
        duracao = ((hpart - hcheg) * 60) + (minpart - mincheg);
    } else {
        duracao = (((24 - hcheg) + hpart) * 60) + (minpart - mincheg);
    }

    if (duracao%60 == 0)
    {
        hora = duracao/60;
    } else {
        hora = duracao/60;
        hora++;
    }

    if (hora <= 2)
    {
        preco = 1.00 * hora;
        printf ("preco final: R$ %.2f", preco);
    } else {
        if ((hora >= 3) && (hora <= 4))
        {
            preco = 1.40 * hora;
            printf ("preco final: R$ %.2f", preco);
        } else {
            preco = 2.00 * hora;
            printf ("preco final: R$ %.2f", preco);
        }
    }

    return 0;
}