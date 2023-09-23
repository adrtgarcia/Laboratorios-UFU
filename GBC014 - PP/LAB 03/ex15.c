#include <stdio.h>
#include <math.h>

int main ( )
{
    float num, q, c, r;

    do
    {
        printf ("\ninsira um valor: ");
        scanf ("%f", &num);

        if (num <= 0)
        {
            break;
        }

        q = pow (num, 2);
        c = pow (num, 3);
        r = sqrt (num);
        
        printf ("\nquadrado de %.2f: %.2f", num, q);
        printf ("\ncubo de %.2f: %.2f", num, c);
        printf ("\nraiz quadrada de %.2f: %.2f\n", num, r);

    } while (num > 0);
    

    return 0;
}