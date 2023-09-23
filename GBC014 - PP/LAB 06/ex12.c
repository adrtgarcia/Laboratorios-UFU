#include <stdio.h>
#include <stdlib.h>
#include <time.h>

struct carta
{
    char naipe[10], valor[6];
};
typedef struct carta carta;

int main ( )
{
    carta baralho[52] = {
    {"Ás", "Paus"}, {"2", "Paus"}, {"3", "Paus"}, {"4", "Paus"}, {"5", "Paus"}, {"6", "Paus"},
    {"7", "Paus"}, {"8", "Paus"}, {"9", "Paus"}, {"10", "Paus"}, {"Valete", "Paus"}, {"Dama", "Paus"}, {"Rei", "Paus"},
    {"Ás", "Copas"}, {"2", "Copas"}, {"3", "Copas"}, {"4", "Copas"}, {"5", "Copas"}, {"6", "Copas"},
    {"7", "Copas"}, {"8", "Copas"}, {"9", "Copas"}, {"10", "Copas"}, {"Valete", "Copas"}, {"Dama", "Copas"}, {"Rei", "Copas"},
    {"Ás", "Espadas"}, {"2", "Espadas"}, {"3", "Espadas"}, {"4", "Espadas"}, {"5", "Espadas"}, {"6", "Espadas"},
    {"7", "Espadas"}, {"8", "Espadas"}, {"9", "Espadas"}, {"10", "Espadas"}, {"Valete", "Espadas"}, {"Dama", "Espadas"}, {"Rei", "Espadas"},
    {"Ás", "Ouros"}, {"2", "Ouros"}, {"3", "Ouros"}, {"4", "Ouros"}, {"5", "Ouros"}, {"6", "Ouros"},
    {"7", "Ouros"}, {"8", "Ouros"}, {"9", "Ouros"}, {"10", "Ouros"}, {"Valete", "Ouros"}, {"Dama", "Ouros"}, {"Rei", "Ouros"}
    };

    carta temporaria;
    carta jogadores[2][3];
    int i, j, k;

    srand (time(NULL));

    for (i = 52 - 1; i > 0; i--)
    {
        j = rand( ) % (i + 1);
        temporaria = baralho[i];
        baralho[i] = baralho[j];
        baralho[j] = temporaria;
    }

    for (i = 0; i < 2; i++)
    {
        for (j = 0, k = 0; j < 3; j++)
        {
            jogadores[i][j] = baralho[k++];
        }
    }

    for (i = 0; i < 2; i++)
    {
        printf ("jogador %d:\n", i + 1);

        for (j = 0; j < 3; j++)
        {
            printf ("carta %d: %s de %s\n", j + 1, jogadores[i][j].valor, jogadores[i][j].naipe);
        }

        printf ("\n");
    }

    return 0;
}