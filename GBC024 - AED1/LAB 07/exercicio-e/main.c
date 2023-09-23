#include "tad_aeroporto.h"

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main ( )
{
    lista_cidade *lc;
    lista_rota *lr;

    cidade c;
    rota r, cara, barata;

    int opcao, retorno;

    lc = criar_lc ( );
    lr = criar_lr ( );

    while (1)
    {
        printf ("\n\nMENU\n");
        printf ("\n(1) cadastrar cidades");
        printf ("\n(2) cadastrar rotas");
        printf ("\n(3) mostrar as rotas mais barata e mais cara");
        printf ("\n(4) consultar preco");
        printf ("\n(5) sair");

        printf ("\n\nopcao escolhida: ");
        scanf ("%d", &opcao);

        if (opcao == 5)
        {
            printf ("encerrando o programa...");
            free (lc);
            free (lr);
            break;
        }

        switch (opcao)
        {
            case 1:
                setbuf (stdin, NULL);
                printf ("\ndigite o nome da cidade: ");
                fgets (c.nome, 100, stdin);
                c.nome[strcspn("\n", c.nome)] = '\0';

                printf ("digite a sigla do aeroporto da cidade: ");
                fgets (c.sigla, 5, stdin);
                c.nome[4] = '\0';

                retorno = adicionar_cidade (lc, c);
                if (retorno == 2)
                    printf ("\nerro: lista nao alocada");
                if (retorno == -2)
                    printf ("\nerro: no nao alocado");
                if (retorno == 0)
                    printf ("\ncidade cadastrada");

                break;

            case 2:
                setbuf (stdin, NULL);
                printf ("\ndigite a sigla do aeroporto de origem: ");
                fgets (r.origem, 5, stdin);
                r.origem[4] = '\0';

                printf ("digite a sigla do aeroporto de destino: ");
                fgets (r.destino, 5, stdin);
                r.destino[4] = '\0';

                printf ("digite o preco: ");
                scanf ("%f", &r.preco);

                retorno = adicionar_rota (lr, r);
                if (retorno == 2)
                    printf ("\nerro: lista nao alocada");
                if (retorno == -2)
                    printf ("\nerro: no nao alocado");
                if (retorno == 0)
                    printf ("\nrota cadastrada");

                break;

            case 3:
                printf ("\nanalisando precos...\n");
                retorno = analisar_preco (lr, &cara, &barata);
                if (retorno == 2)
                    printf ("\nerro: lista nao alocada");
                if (retorno == 1)
                    printf ("\nerro: lista vazia");
                if (retorno == -2)
                    printf ("\nerro: no nao alocado");
                if (retorno == 0)
                {
                    printf ("\nanalise concluida");
                    printf ("\nrota mais cara: %s -> %s ($ %.2f)", cara.origem, cara.destino, cara.preco);
                    printf ("\nrota mais barata: %s -> %s ($ %.2f)", barata.origem, barata.destino, barata.preco);
                }

                break;

            case 4:
                setbuf (stdin, NULL);
                printf ("\ndigite a sigla do aeroporto de origem: ");
                fgets (r.origem, 5, stdin);
                r.origem[4] = '\0';

                printf ("digite a sigla do aeroporto de destino: ");
                fgets (r.destino, 5, stdin);
                r.destino[4] = '\0';

                printf ("\nbuscando rota...\n");

                retorno = preco_trecho (lr, &r);
                if (retorno == 2)
                    printf ("\nerro: lista nao alocada");
                if (retorno == 1)
                    printf ("\nerro: lista vazia");
                if (retorno == -2)
                    printf ("\nerro: no nao alocado");
                if (retorno == -1)
                    printf ("\nrota nao encontrada");
                if (retorno == 0)
                {
                    printf ("\nrota encontrada");
                    printf ("\n%s -> %s", r.origem, r.destino);
                    printf ("\n valor: $ %.2f", r.preco);
                }

                break;

            default:
                printf ("\nopcao invalida, tente novamente");
        }
    }

    return 0;
}
