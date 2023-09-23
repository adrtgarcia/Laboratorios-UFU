#include <stdio.h>

int main ( )
{
    int ano;
    printf ("digite o ano: ");
    scanf ("%d", &ano);

    if ((ano%400 == 0) || ((ano%4 == 0) && (ano%100 != 0)))
    {
        printf ("o ano eh bissexto");
    } else {
        printf ("o ano nao eh bissexto");
    }

    return 0;
}