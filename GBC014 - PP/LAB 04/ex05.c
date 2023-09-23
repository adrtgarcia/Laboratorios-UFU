#include <stdio.h>
#include <math.h>

int volume_esfera (int r);

int main ( )
{
    int raio;
   
    do
    {
        printf ("digite o valor do raio: ");
        scanf ("%d", &raio);
        
        if (raio < 0)
        {
            printf ("o valor precisa ser positivo");
        }

    } while (raio < 0);
    
    printf ("o volume da esfera eh aproximadamente: %d", volume_esfera (raio));

    return 0;
}

int volume_esfera (int r)
{
    int volume = (4.0/3.0 * 3 * (pow (r, 3)));
    return volume;
}