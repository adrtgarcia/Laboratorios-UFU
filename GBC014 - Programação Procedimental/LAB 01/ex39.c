#include <stdio.h>
// R$ 780.000,00 para três ganhadores, calcule e imprima a quantia ganha por cada um

int main ( )
{
    float x = 780000 * 0.46; //1º ganhador = 46% do prêmio
    float y = 780000 * 0.32; //2º ganhador = 32% do prêmio
    float z = 780000 * 0.22; //3º ganhador = resto do prêmio
    
    printf ("o primeiro ganhador recebeu: R$ %.2f \n", x);
    printf ("o segundo ganhador recebeu: R$ %.2f \n", y);
    printf ("o terceiro ganhador recebeu: R$ %.2f", z);

    return 0;
}