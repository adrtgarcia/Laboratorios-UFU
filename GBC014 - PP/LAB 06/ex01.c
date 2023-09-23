#include <stdio.h>

struct horario
{
    int hora, min, seg;
};
typedef struct horario horario;

struct data
{
    int dia, mes, ano;
};
typedef struct data data;

struct compromisso
{
    data d;
    horario h;
    char descricao[100];
};
typedef struct compromisso compromisso;

int main ( )
{
    //código

    return 0;
}