#include <stdio.h>
#include <stdlib.h>

struct produto 
{
    int cod, quant;
    char nome[50];
    float preco;
};
typedef struct produto produto;

int main ( ) 
{
    int i, numprod, maxpreco = 0, maxquant = 0;
    produto *estoque = NULL;

    printf ("digite o numero de produtos: ");
    scanf ("%d", &numprod);

    estoque = (produto *) calloc (numprod, (sizeof(produto)));
    if (estoque == NULL)
    {
        printf ("\nerro: memoria insuficiente");
    }

    for (i = 0; i < numprod; i++) 
    {
        printf("\n\n");
        printf ("produto %d:\n", (i + 1));
        printf ("código: ");
        scanf ("%d", &estoque[i].cod);
        
        setbuf (stdin, NULL);
        printf ("nome: ");
        fgets (estoque[i].nome, 50, stdin);

        printf ("quantidade: ");
        scanf ("%d", &estoque[i].quant);
        
        printf ("preco: ");
        scanf ("%f", &estoque[i].preco);


        if (estoque[i].preco > estoque[maxpreco].preco) 
        {
            maxpreco = i;
        }

        if (estoque[i].quant > estoque[maxquant].quant) 
        {
            maxquant = i;
        }
    }

    printf ("\nprodutos cadastrados:\n");
    for (i = 0; i < numprod; i++) 
    {
        printf ("\nproduto %d:", (i + 1));
        printf ("\ncodigo: %d", estoque[i].cod);
        printf ("\nnome: %s", estoque[i].nome);
        printf ("\nquantidade: %d", estoque[i].quant);
        printf ("\npreco: %.2f", estoque[i].preco);
    }

    printf ("\n\nproduto com o maior preco:");
    printf ("\ncodigo: %d", estoque[maxpreco].cod);
    printf ("\nnome: %s", estoque[maxpreco].nome);
    printf ("\nquantidade: %d", estoque[maxpreco].quant);
    printf ("\npreco: %.2f", estoque[maxpreco].preco);

    printf ("\n\nproduto com a maior quantidade disponível:");
    printf ("\ncodigo: %d", estoque[maxquant].cod);
    printf ("\nnome: %s", estoque[maxquant].nome);
    printf ("\nquantidade: %d", estoque[maxquant].quant);
    printf ("\npreco: %.2f", estoque[maxquant].preco);

    free(estoque);

    return 0;
}