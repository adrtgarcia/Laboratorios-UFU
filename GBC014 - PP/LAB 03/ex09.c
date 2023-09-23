#include <stdio.h>

int main ( )
{
    int N, imp = 1, cont;
    printf ("digite um numero: ");
    scanf ("%d", &N);

    for (cont = 0; cont < N; cont++)
    {
        if (imp%2 == 0)
        {
            continue;
        }

        printf ("%d  ", imp);
        imp = imp + 2;
    }

    return 0;
}