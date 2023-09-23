#include <stdio.h>

struct voo
{
    int origem, destino;
};
typedef struct voo voo;

struct aeroporto
{
    int cod, sai, chega;
};
typedef struct aeroporto aeroporto;

int main ( )
{
    voo V[5];
    aeroporto A[5];
    int cont;

    printf ("registre os voos:\n");
    for (cont = 0; cont < 5; cont++)
    {
        printf ("codigo de origem: ");
        scanf ("%d", &V[cont].origem);

        if ((V[cont].origem < 0) || (V[cont].origem > 4))
        {
            printf ("codigo invalido\n");
            cont--;
            continue;
        }
        
        printf ("codigo de destino: ");
        scanf ("%d", &V[cont].destino);

        if ((V[cont].destino < 0) || (V[cont].destino > 4))
        {
            printf ("codigo invalido\n");
            cont--;
            continue;
        }

        printf ("\n");
    }

    for (cont = 0; cont < 5; cont++)
    {
        A[cont].cod = cont;
        A[cont].sai = 0;
        A[cont].chega = 0;
    }

    for (cont = 0; cont < 5; cont++)
    {
        A[V[cont].origem].sai++;
        A[V[cont].destino].chega++;
    }

    printf ("\nfluxo de voos nos aeroportos:\n");
    for (cont = 0; cont < 5; cont++)
    {
        printf ("\ncodigo do aeroporto: %d", A[cont].cod);
        printf ("\nvoos de saida: %d", A[cont].sai);
        printf ("\nvoos de chegada: %d\n", A[cont].chega);
    }

    return 0;
}