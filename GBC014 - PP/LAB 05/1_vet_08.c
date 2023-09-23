#include <stdio.h>

int main ( )
{
    int vetor[10], num, cont1, cont2, cont3, confere;
    //0 = não existe, 1 = já existe

    printf ("digite dez valores diferentes:\n");
    for (cont1 = 0; cont1 < 10; cont1++)
    {
        scanf (" %d", &num);
        confere = 0;

        for (cont2 = 0; cont2 < cont1; cont2++)
        {
            if (num == (vetor[cont2]))
            {
                printf ("este numero ja foi registrado, digite outro:\n");
                confere = 1;
                break;
            }
            
        }
        
        if (confere)
        {
            cont1--;
            continue;
        }

        vetor[cont1] = num;
    }   

    printf ("\nvetor final: \n");
    printf ("[");
    for (cont3 = 0; cont3 < 10; cont3++)
    {
        printf ("%d ", vetor[cont3]);
    }
    printf ("]");

    return 0;
}