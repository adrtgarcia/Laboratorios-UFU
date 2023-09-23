#include <stdio.h>
// leia um NÚMERO INTEIRO POSITIVO de TRÊS DÍGITOS e INVERTA o número

int main ( )
{
    int num;
    printf ("digite um numero de tres digitos: ");
    scanf ("%d", &num);

    int num1, num2, num3;
    
    num1 = num%10;
    num = num/10;
    num2 = num%10;
    num = num/10;
    num3 = num%10;
    num = num/10;
    
    printf ("invertido: %d%d%d", num1, num2, num3);

    return 0;
}