#include "tad_matriz.h"

#include <stdio.h>
#include <stdlib.h>
#include <time.h>

struct matriz
{
    int i, j;
    float **mat;
};
typedef struct matriz matriz;

int main ( )
{
    matriz *mat1, *mat2, *matsoma;
    int linhas, colunas;
    float minimo, maximo;
    int a, b, c;

    printf ("criando a matriz 1 (M1)");

    do
    {
        printf ("\ndigite o numero de linhas: ");
        scanf ("%d", &linhas);

        if (linhas <= 0)
            printf ("\ntamanho invalido");

    } while (linhas <= 0);

    do
    {
        printf ("\ndigite o numero de colunas: ");
        scanf ("%d", &colunas);

        if (colunas <= 0)
            printf ("\ntamanho invalido");

    } while (colunas <= 0);

    mat1 = criar (linhas, colunas);
    if (mat1 == NULL)
    {
        printf ("\nerro na criacao da M1");
        return 0;
    }

    printf ("\ndigite o valor minimo de M1: ");
    scanf ("%f", &minimo);

    printf ("\ndigite o valor maximo de M1: ");
    scanf ("%f", &maximo);

    preencher (mat1, minimo, maximo);

    printf ("\nM1:\n");
    for (a = 0; a < mat1->i; a++)
    {
        for (b = 0; b < mat1->j; b++)
        {
            printf (" %.2f ", mat1->mat[a][b]);
        }

        printf ("\n");
    }

    printf ("\nacessando elementos de M1");
    while (1)
    {
        do
        {
            printf ("\ndigite a linha: ");
            scanf ("%d", &a);

            if ((a < 0) || (a > mat1->i))
                printf ("\nvalor invalido");

        } while ((a < 0) || (a > mat1->i));

        do
        {
            printf ("\ndigite a coluna: ");
            scanf ("%d", &b);

            if ((b < 0) || (b > mat1->j))
                printf ("\nvalor invalido");

        } while ((b < 0) || (b > mat1->j));

        printf ("\nM1[%d][%d] = %.2f\n", a, b, mat1->mat[a][b]);

        do
        {
            printf ("\ndeseja continuar?");
            printf ("\n0 - nao, 1 - sim\n");
            scanf ("%d", &c);

            if ((c != 0) && (c != 1))
                printf ("\nopcao invalida");

        } while ((c != 0) && (c != 1));

        if (c == 0)
            break;
    }

    printf ("\nnumero de linhas de M1: %d", numero_linhas(mat1));
    printf ("\nnumero de colunas de M1: %d", numero_colunas(mat1));

    printf ("\n\ncriando a matriz 2 (M2)");

    do
    {
        printf ("\ndigite o numero de linhas: ");
        scanf ("%d", &linhas);

        if (linhas <= 0)
            printf ("\ntamanho invalido");

    } while (linhas <= 0);

    do
    {
        printf ("\ndigite o numero de colunas: ");
        scanf ("%d", &colunas);

        if (colunas <= 0)
            printf ("\ntamanho invalido");

    } while (colunas <= 0);

    mat2 = criar (linhas, colunas);
    if (mat2 == NULL)
    {
        printf ("\nerro na criacao da M2");
        return 0;
    }

    printf ("\npreenchendo M2:");
    for (a = 0; a < mat2->i; a++)
    {
        for (b = 0; b < mat2->j; b++)
        {
            printf ("M2[%d][%d] = ", a, b);
            scanf ("%f", &mat2->mat[a][b]);
        }
    }

    printf ("\nM2:\n");
    for (a = 0; a < mat2->i; a++)
    {
        for (b = 0; b < mat2->j; b++)
        {
            printf (" %.2f ", mat2->mat[a][b]);
        }

        printf ("\n");
    }

    printf ("\nacessando elementos de M2");
    while (1)
    {
        do
        {
            printf ("\ndigite a linha: ");
            scanf ("%d", &a);

            if ((a < 0) || (a > mat2->i))
                printf ("\nvalor invalido");

        } while ((a < 0) || (a > mat2->i));

        do
        {
            printf ("\ndigite a coluna: ");
            scanf ("%d", &b);

            if ((b < 0) || (b > mat2->j))
                printf ("\nvalor invalido");

        } while ((b < 0) || (b > mat2->j));

        printf ("\nM2[%d][%d] = %.2f\n", a, b, mat2->mat[a][b]);

        do
        {
            printf ("\ndeseja continuar?");
            printf ("\n0 - nao, 1 - sim\n");
            scanf ("%d", &c);

            if ((c != 0) && (c != 1))
                printf ("\nopcao invalida");

        } while ((c != 0) && (c != 1));

        if (c == 0)
            break;
    }

    printf ("\nnumero de linhas de M2: %d", numero_linhas(mat2));
    printf ("\nnumero de colunas de M2: %d", numero_colunas(mat2));

    printf ("\n\nsomando M1 e M2");
    matsoma = somar (mat1, mat2);

    printf ("\nM1 + M2:\n");
    for (a = 0; a < matsoma->i; a++)
    {
        for (b = 0; b < matsoma->j; b++)
        {
            printf (" %.2f ", matsoma->mat[a][b]);
        }

        printf ("\n");
    }

    destruir (mat1);
    destruir (mat2);
    destruir (matsoma);

    return 0;
}
