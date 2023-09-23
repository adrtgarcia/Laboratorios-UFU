#include <stdio.h>

int main()
{
    int dia, mes, ano, anobi;

    printf ("em DD/MM/AAAA, digite uma data: ");
    scanf ("%d/%d/%d", &dia, &mes, &ano);


    if (ano > 0)
    {
    if ((mes > 0) && (mes < 13))
    {
        if (mes == 2)
        {
            if ((ano%400 == 0) || ((ano%4 == 0) && (ano%100 != 0)))
            {
                if ((dia > 0) && (dia <= 29))
                {
                    printf ("data valida");
                } else {
                    printf ("data invalida");
                }
            } else {
                if ((dia > 0) && (dia <= 28))
                {
                    printf ("data valida");
                } else {
                    printf ("data invalida");
                }
            }
        } else {
            if ((mes == 4) || (mes == 6) || (mes == 9) || (mes == 11))
            {
                if ((dia > 0) && (dia <= 30))
                {
                    printf ("data valida");
                } else {
                    printf ("data invalida");
                }
            } else {
                if ((dia > 0) && (dia <= 31))
                {
                    printf ("data valida");
                } else {
                    printf ("data invalida");
                }
            }
        }
    } else {
        printf ("data invalida");
    }
    } else {
        printf ("data invalida");
    }    

    return 0;
}