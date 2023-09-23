#ifndef TAD_AEROPORTO_H_INCLUDED
#define TAD_AEROPORTO_H_INCLUDED

struct cidade
{
    char nome[100];
    char sigla[5];
};
typedef struct cidade cidade;

struct rota
{
    char origem[5];
    char destino[5];
    float preco;
};
typedef struct rota rota;

typedef struct no_cidade no_cidade;
typedef struct lista_cidade lista_cidade;
typedef struct no_rota no_rota;
typedef struct lista_rota lista_rota;

lista_cidade *criar_lc ( );

lista_rota *criar_lr ( );

int lr_vazia (lista_rota *lr);

int adicionar_cidade (lista_cidade *lc, cidade c);

int adicionar_rota (lista_rota *lr, rota r);

int analisar_preco (lista_rota *lr, rota *cara, rota *barata);

int preco_trecho (lista_rota *lr, rota *r);

#endif // TAD_AEROPORTO_H_INCLUDED
