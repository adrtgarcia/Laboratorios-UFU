#include <stdio.h>
#include <stdlib.h>

int main ( ) 
{
    int *memoria = NULL, tamanho = 0, elementos, opcao, posicao, valor, i;
    
    printf ("digite o tamanho da memoria: ");
    scanf ("%d", &tamanho);
    
    if ((tamanho <= 0) || ((tamanho % (sizeof(int))) != 0)) 
    {
        printf ("\nerro: tamanho invalido");
        exit(1);
    }
    
    elementos = tamanho / (sizeof(int));
    
    memoria = (int*) calloc (elementos, (sizeof(int)));
    
    if (memoria == NULL) 
    {
        printf ("\nerro: memoria insuficiente");
        exit(1);
    }

    for (i = 0; i < tamanho; i++)
    {
        memoria[i] = 0;
    }

    do 
    {
        printf ("\nescolha uma opcao abaixo:");
        printf ("\n(1) inserir valor");
        printf ("\n(2) consultar valor\n");
        
        printf ("\nopcao escolhida: ");
        scanf("%d", &opcao);

        if ((opcao < 1) || (opcao > 2))
        {
            printf ("\nopcao invalida\n");
        }

    } while ((opcao < 1) || (opcao > 2));

    switch (opcao)
    {
        case 1:
            do
            {
                printf ("\nem qual posicao deseja inserir um novo valor?");
                printf ("\nposicao: ");
                scanf ("%d", &posicao);

                if ((posicao < 0) || (posicao > elementos))
                {
                    printf ("\nerro: posicao invalida\n");
                }

            } while ((posicao < 0) || (posicao > elementos));
            
            printf ("\nnovo valor: ");
            scanf ("%d", &valor);

            memoria[posicao] = valor;
            printf ("valor armazenado: memoria[%d] = %d", posicao, valor);

            break;
        
        case 2:
            do
            {
                printf ("\ndeseja consultar o valor de qual posicao?");
                printf ("\nposicao: ");
                scanf ("%d", &posicao);

                if ((posicao < 0) || (posicao > elementos))
                {
                    printf ("\nerro: posicao invallida\n");
                }

            } while ((posicao < 0) || (posicao > elementos));
            
            printf ("\nvalor armazenado: memoria[%d] = %d", posicao, memoria[posicao]);

            break;
        
    }
    
    free(memoria);
    
    return 0;
}