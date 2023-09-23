#include <stdio.h>
#include <string.h>

int main ( )
{
    char S1[20], S2[20], C1, C2;
    int op, tamanho, cont, qnts_c, posicao;

    do
    {
        printf ("\nmenu de opcoes:\n");
        printf ("\n(1) ler string S1");
        printf ("\n(2) imprimir tamanho de S1");
        printf ("\n(3) comparar S1 e S2");
        printf ("\n(4) concatenar S1 e S2");
        printf ("\n(5) imprimir S1 reversa");
        printf ("\n(6) contar caractere em S1");
        printf ("\n(7) substituir C1 de S1 por C2");
        printf ("\n(8) verificar se S2 eh substring de S1");
        printf ("\n(9) retornar substring de S1\n");

        printf ("\nescolha uma opcao: ");
        scanf ("%d", &op);
    } while ((op < 1) || (op > 9));
    
    switch (op)
    {
    case 1:
        setbuf(stdin, NULL);
        printf ("digite S1: ");
        fgets (S1, 20, stdin);

        printf ("string lida: %s", S1);
        break;
    
    case 2:
        setbuf(stdin, NULL);
        printf ("digite S1: ");
        fgets (S1, 20, stdin);

        tamanho = strlen(S1);
        printf ("tamanho de S1: %d", tamanho);
        break;
    
    case 3:
        setbuf(stdin, NULL);
        printf ("digite S1: ");
        fgets (S1, 20, stdin);
        printf ("digite S2: ");
        fgets (S2, 20, stdin);

        if (strcmp (S1, S2) == 0)
        {
            printf ("\nas strings sao iguais");
        } else printf ("\nas strings nao sao iguais");
        break;
    
    case 4:
        setbuf(stdin, NULL);
        printf ("digite S1: ");
        fgets (S1, 20, stdin);
        printf ("digite S2: ");
        fgets (S2, 20, stdin);

        tamanho = strlen (S1);
        S1[strcspn(S1, "\n")] = 0;
        S2[strcspn(S2, "\n")] = 0;

        printf ("%s", strncat(S1, S2, (20 - tamanho)));
        break;
    
    case 5:
        setbuf(stdin, NULL);
        printf ("digite S1: ");
        fgets (S1, 20, stdin);
        tamanho = strlen(S1);

        printf ("S1 ao contrario: ");
        for (cont = (tamanho - 1); cont >= 0; cont--)
        {
            printf ("%c", S1[cont]);
        }
        break;
    
    case 6:
        setbuf(stdin, NULL);
        printf ("digite S1: ");
        fgets (S1, 20, stdin);
        tamanho = strlen(S1);
        printf ("digite um caractere: ");
        scanf (" %c", &C1);

        for (cont = 0, qnts_c = 0; cont < tamanho; cont++)
        {
            if (S1[cont] == C1)
            {
                qnts_c++;
            }
        }
        printf ("%c aparece %dx em S1", C1, qnts_c);
        break;
    
    case 7:
        setbuf(stdin, NULL);
        printf ("digite S1: ");
        fgets (S1, 20, stdin);
        tamanho = strlen(S1);
        printf ("digite C1: ");
        scanf (" %c", &C1);
        printf ("digite C2: ");
        scanf (" %c", &C2);

        for (cont = 0; cont < tamanho; cont++)
        {
            if (S1[cont] == C1)
            {
                S1[cont] = C2;
                break;
            }
        }
        printf ("S1 alterada: %s", S1);
        break;
    
    case 8:
        setbuf(stdin, NULL);
        printf ("digite S1: ");
        fgets (S1, 20, stdin);
        printf ("digite S2: ");
        fgets (S2, 20, stdin);

        S1[strcspn(S1, "\n")] = 0;
        S2[strcspn(S2, "\n")] = 0;

        if (strstr(S1, S2) != NULL)
        {
            printf ("S2 eh substring de S1");
        } else printf ("S2 nao eh substring de S1");
        break;

    case 9:
        setbuf(stdin, NULL);
        printf ("digite S1: ");
        fgets (S1, 20, stdin);
        S1[strcspn(S1, "\n")] = 0;
        
        printf ("digite a posicao: ");
        scanf ("%d", &posicao);
        printf ("digite o tamanho da substring: ");
        scanf ("%d", &tamanho);

        strncpy (S2, (S1 + posicao), tamanho);
        S2[tamanho] = '\0';
        printf ("substring correspondente: %s", S2);
        break;
    }

    return 0;
}