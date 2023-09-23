#include <stdio.h>

void data (int d, int m, int a);

int main ( )
{
    int dia, mes, ano;
    printf ("em formato DD/MM/AAAA, digite a data: ");
    scanf ("%d/%d/%d", &dia, &mes, &ano);

    data (dia, mes, ano);
    
    return 0;
}

void data (int d, int m, int a)
{
    switch (m)
    {
    case 1:
        if ((d >= 1) && (d <= 31))
        {
            if (a >= 0)
            {
                printf ("%d de janeiro de %d", d, a);
            } else printf ("data invalida");
        } else printf ("data invalida");
        break;
    case 2:
        if ((a%400 == 0) || ((a%4 == 0) && (a%100 != 0)))
            {
                if ((d >= 1) && (d <= 29))
                {
                    printf ("%d de fevereiro de %d", d, a);
                } else {
                    printf ("data invalida");
                }
            } else {
                if ((d >= 1) && (d <= 28))
                {
                    printf ("%d de fevereiro de %d", d, a);
                } else {
                    printf ("data invalida");
                }
            }
        break;
    case 3:
        if ((d >= 1) && (d <= 31))
        {
            if (a >= 0)
            {
                printf ("%d de marco de %d", d, a);
            } else printf ("data invalida");
        } else printf ("data invalida");
        break;
    case 4:
        if ((d >= 1) && (d <= 30))
        {
            if (a >= 0)
            {
                printf ("%d de abril de %d", d, a);
            } else printf ("data invalida");
        } else printf ("data invalida");
        break;
    case 5:
        if ((d >= 1) && (d <= 31))
        {
            if (a >= 0)
            {
                printf ("%d de maio de %d", d, a);
            } else printf ("data invalida");
        } else printf ("data invalida");
        break;
    case 6:
        if ((d >= 1) && (d <= 30))
        {
            if (a >= 0)
            {
                printf ("%d de junho de %d", d, a);
            } else printf ("data invalida");
        } else printf ("data invalida");
        break;
    case 7:
        if ((d >= 1) && (d <= 31))
        {
            if (a >= 0)
            {
                printf ("%d de julho de %d", d, a);
            } else printf ("data invalida");
        } else printf ("data invalida");
        break;
    case 8:
        if ((d >= 1) && (d <= 31))
        {
            if (a >= 0)
            {
                printf ("%d de agosto de %d", d, a);
            } else printf ("data invalida");
        } else printf ("data invalida");
        break;
    case 9:
        if ((d >= 1) && (d <= 30))
        {
            if (a >= 0)
            {
                printf ("%d de setembro de %d", d, a);
            } else printf ("data invalida");
        } else printf ("data invalida");
        break;
    case 10:
        if ((d >= 1) && (d <= 31))
        {
            if (a >= 0)
            {
                printf ("%d de outubro de %d", d, a);
            } else printf ("data invalida");
        } else printf ("data invalida");
        break;
    case 11:
        if ((d >= 1) && (d <= 30))
        {
            if (a >= 0)
            {
                printf ("%d de novembro de %d", d, a);
            } else printf ("data invalida");
        } else printf ("data invalida");
        break;
    case 12:
        if ((d >= 1) && (d <= 31))
        {
            if (a >= 0)
            {
                printf ("%d de dezembro de %d", d, a);
            } else printf ("data invalida");
        } else printf ("data invalida");
        break;
    
    default:
        printf ("data invalida");
        break;
    }
}