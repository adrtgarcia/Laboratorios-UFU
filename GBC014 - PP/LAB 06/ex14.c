#include <stdio.h>
#include <string.h>

struct carro
{
    char marca[15];
    int ano;
    float preco;
};
typedef struct carro carro;

int main ( )
{
    carro c[5];
    int cont, tamanho;
    float p;

    for (cont = 0; cont < 5; cont++)
    {
        setbuf (stdin, NULL);

        printf ("digite a marca: ");
        fgets (c[cont].marca, 15, stdin);
        c[cont].marca[strcspn(c[cont].marca, "\n")] = '\0';

        printf ("digite o ano: ");
        scanf ("%d", &c[cont].ano);

        printf ("digite o preco: R$ ");
        scanf ("%f", &c[cont].preco);

        printf ("\n");
    }

    do
    {
        printf ("\ndigite um valor padrao: R$ ");
        scanf ("%f", &p);

        if (p > 0)
        {
            for (cont = 0; cont < 5; cont++)
            {
                if (c[cont].preco < p)
                {
                    printf ("\no modelo %s, ano %d e preco R$ %.2f esta abaixo desse valor", c[cont].marca, c[cont].ano, c[cont].preco);
                } else continue;
            }
        } else break;

    } while (p > 0);
    
    return 0;
}