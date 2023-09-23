#include <stdio.h>
#include <string.h>

struct dados
{
    char nome[100], end[100], cid[100], cep[10], email[100];
    int dia, mes, ano;
};
typedef struct dados dados;

int verificar_data (int d, int m, int a);

int main ( )
{
    dados x;
    int cont, confere = 0, erro = 0;

    printf ("digite seu nome: ");
    fgets (x.nome, 100, stdin);
    x.nome[strcspn(x.nome, "\n")] = '\0';
    
    printf ("digite seu endereco: ");
    fgets (x.end, 100, stdin);
    x.end[strcspn(x.end, "\n")] = '\0';
    
    printf ("digite sua data de nascimento: ");
    scanf ("%d/%d/%d", &x.dia, &x.mes, &x.ano);

    setbuf (stdin, NULL);
    printf ("digite sua cidade: ");
    fgets (x.cid, 100, stdin);
    x.cid[strcspn(x.cid, "\n")] = '\0';
    
    printf ("digite seu CEP: ");
    fgets (x.cep, 10, stdin);
    x.cep[strcspn(x.cep, "\n")] = '\0';

    printf ("digite seu e-mail: ");
    fgets (x.email, 100, stdin);
    x.email[strcspn(x.email, "\n")] = '\0';

    if (verificar_data (x.dia, x.mes, x.ano))
    {
        printf ("\nerro: data de nascimento invalida");
        erro++;
    }

    if (strlen (x.cep) != 8)
    {
        printf ("\nerro: CEP invalido");
        erro++;
    }

    for (cont = 0; x.email[cont] != '\0'; cont++)
    {
        if (x.email[cont] == '@')
        {
            confere = 1;
            break;
        }
    }

    if (confere == 0)
    {
        printf ("\nerro: e-mail invalido");
        erro++;
    }

    if (erro == 0)
    {
        printf ("\ntodas as informacoes registradas estao corretas\n");
        printf ("\nnome: %s", x.nome);
        printf ("\nendereco: %s", x.end);
        printf ("\ndata de nascimento: %d/%d/%d", x.dia, x.mes, x.ano);
        printf ("\ncidade: %s", x.cid);
        printf ("\nCEP: %s", x.cep);
        printf ("\ne-mail: %s", x.email);
    }

    return 0;
}

int verificar_data (int d, int m, int a)
{
    switch (m)
    {
    case 1:
        if ((d >= 1) && (d <= 31))
        {
            if (a >= 0)
            {
                return 0;
            } else return 1;
        } else return 1;

    case 2:
        if ((a%400 == 0) || ((a%4 == 0) && (a%100 != 0)))
        {
            if ((d >= 1) && (d <= 29))
            {
                return 0;
            } else return 1;
        } else {
            if ((d >= 1) && (d <= 28))
            {
                return 0;
            } else return 1;
        }

    case 3:
        if ((d >= 1) && (d <= 31))
        {
            if (a >= 0)
            {
                return 0;
            } else return 1;
        } else return 1;

    case 4:
        if ((d >= 1) && (d <= 30))
        {
            if (a >= 0)
            {
                return 0;
            } else return 1;
        } else return 1;

    case 5:
        if ((d >= 1) && (d <= 31))
        {
            if (a >= 0)
            {
                return 0;
            } else return 1;
        } else return 1;

    case 6:
        if ((d >= 1) && (d <= 30))
        {
            if (a >= 0)
            {
                return 0;
            } else return 1;
        } else return 1;

    case 7:
        if ((d >= 1) && (d <= 31))
        {
            if (a >= 0)
            {
                return 0;
            } else return 1;
        } else return 1;

    case 8:
        if ((d >= 1) && (d <= 31))
        {
            if (a >= 0)
            {
                return 0;
            } else return 1;
        } else return 1;

    case 9:
        if ((d >= 1) && (d <= 30))
        {
            if (a >= 0)
            {
                return 0;
            } else return 1;
        } else return 1;

    case 10:
        if ((d >= 1) && (d <= 31))
        {
            if (a >= 0)
            {
                return 0;
            } else return 1;
        } else return 1;

    case 11:
        if ((d >= 1) && (d <= 30))
        {
            if (a >= 0)
            {
                return 0;
            } else return 1;
        } else return 1;

    case 12:
        if ((d >= 1) && (d <= 31))
        {
            if (a >= 0)
            {
                return 0;
            } else return 1;
        } else return 1;
    
    default: return 1;
    }
}