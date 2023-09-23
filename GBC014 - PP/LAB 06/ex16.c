#include <stdio.h>

struct data
{
    int dia, mes, ano;
};
typedef struct data data;

struct agenda
{
    char compromisso[60];
    data d;
};
typedef struct agenda agenda;

int main ( )
{
    agenda a[5];
    int cont, confere, M, A;

    printf ("registre os compromissos\n");
    for (cont = 0; cont < 5; cont++)
    {
        setbuf (stdin, NULL);

        printf ("digite o compromisso: ");
        fgets (a[cont].compromisso, 60, stdin);
        a[cont].compromisso[strcspn(a[cont].compromisso, "\n")] = '\0';

        printf ("digite a data, no formato DD/MM/AAAA: ");
        scanf ("%d/%d/%d", &a[cont].d.dia, &a[cont].d.mes, &a[cont].d.ano);
    }

    do
    {
        printf ("\ndigite o parametro M (mes), ou 0 para sair: ");
        scanf ("%d", &M);
        if (M <= 0) break;

        printf ("digite o parametro A (ano): ");
        scanf ("%d", &A);
        
        confere = 0;

        printf ("\ncompromissos encontrados:\n");
        
        for (cont = 0; cont < 5; cont++)
        {
            if ((A == a[cont].d.ano) && (M == a[cont].d.mes))
            {
                printf ("%d/%d/%d : %s", a[cont].d.dia, a[cont].d.mes, a[cont].d.ano, a[cont].compromisso);
                confere++;
            }
        }

        if (confere == 0)
        {
            printf ("\nnao foi possivel filtrar nenhum compromisso\n");
        }
    } while (M > 0);
       
    return 0;
}