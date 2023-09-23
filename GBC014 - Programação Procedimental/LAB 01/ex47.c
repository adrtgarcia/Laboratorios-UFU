#include <stdio.h>
// leia um NÚMERO INTEIRO de 4 DÍGITOS e imprima 1 DÍGITO POR LINHA

int main ( )
{
    int num;
    printf ("numero de quatro digitos: ");
    scanf ("%int", &num);
  
    int w = num / 1000;
    int x = num / 100 - 10 * w;
    int y = num / 10 - 100 * w - 10 * x;
    int z = num / 1 - 1000 * w - 100 * x - 10 * y;

    printf ("%d\n%d\n%d\n%d", w, x, y, z);

    return 0;
}