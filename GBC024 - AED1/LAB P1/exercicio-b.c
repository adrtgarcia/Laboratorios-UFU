#include <stdio.h>
#include <stdlib.h>

int main ( )
{
    int *vet, numero, tamanho;
    int i, opcao;

    do
    {
        vet = (int *) calloc (1, (sizeof(int)));
        if (vet == NULL)
        {
            printf ("erro na alocacao de memoria");
            return 0;
        }

        printf ("\ndigite os valores do vetor (-1 encerra):");
        tamanho = 0;

        while (1)
        {
            printf ("\nnumero %d: ", (tamanho + 1));
            scanf ("%d", &numero);

            if (numero == -1)
            {
                printf ("\nencerrando leitura...");
                break;
            }

            vet[tamanho] = numero;

            if (tamanho != 0)
            {
                if (vet[tamanho] == vet[tamanho - 1])
                {
                    printf ("\nvetor atualizado:");
                    printf ("\nvet[");
                    for (i = 0; i < tamanho; i++)
                    {
                        printf (" %d ", vet[i]);
                    }
                    printf ("]");
                    printf ("\ntamanho do vetor = %d\n", tamanho);
                    continue;
                }
            }

            tamanho++;

            vet = (int * ) realloc (vet, (tamanho * (sizeof(int))));
            if (vet == NULL)
            {
                printf ("\nerro na alocacao de memoria");
                return 0;
            }

            printf ("\n\nvetor atualizado:");
            printf ("\nvet[");
            for (i = 0; i < tamanho; i++)
            {
                printf (" %d ", vet[i]);
            }
            printf ("]");
            printf ("\ntamanho do vetor = %d\n", tamanho);
        }

        printf ("\n\nvetor final:");
        printf ("\nvet[");
        for (i = 0; i < tamanho; i++)
        {
            printf (" %d ", vet[i]);
        }
        printf ("]");
        printf ("\ntamanho do vetor = %d", tamanho);

        do
        {
            printf ("\n\npara criar outro vetor, digite 1");
            printf ("\npara encerrar o programa, digite 0\n");
            scanf ("%d", &opcao);

            if ((opcao != 1) && (opcao != 0))
            {
                printf ("opcao invalida");
            }
        } while ((opcao != 1) && (opcao != 0));

    } while (opcao == 1);

    free(vet);

    return 0;
}
