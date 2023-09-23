#include <stdio.h>

int main ( )
{
    int a, b, c;
    printf ("digite o primeiro numero: ");
    scanf ("%d", &a);
    printf ("digite o segundo numero: ");
    scanf ("%d", &b);
    printf ("digite o terceiro numero: ");
    scanf ("%d", &c);

    if (a <= b && b <= c)
    {
      printf("A ordem crescente: %d %d %d", a, b, c);
    } else if (a <= c && c <= b)
    {
      printf("A ordem crescente: %d %d %d", a, c, b);
    } else if (b <= a && a <= c)
    {
      printf("A ordem crescente: %d %d %d", b, a, c);
    } else if (b <= c && c <= a) 
    {
      printf("A ordem crescente: %d %d %d", b, c, a);
    } else if (c <= a && a <= b) 
    {
      printf("A ordem crescente: %d %d %d", c, a, b);
    } else
    {
      printf("A ordem crescente: %d %d %d", c, b, a);
    }

    return 0;
}