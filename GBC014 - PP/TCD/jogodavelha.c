#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>

//estrutura para salvar os dados dos jogadores
struct jogador {
    char nome[15];
    int numvitorias;
    int numderrotas;
};
typedef struct jogador jogador;

//protótipos
void imprimir(char tabuleiro[]);
int verificarganhador(char tabuleiro[]);
int menu(jogador ranking[], int *numjogadores);
int jogodavelha(jogador ranking[], int *numjogadores, char nomejogador[], char tabuleiro[], int posicao, int rodadas, char jogador, int i);
void salvarranking(jogador ranking[], int numjogadores);
void carregarranking(jogador ranking[], int *numjogadores);

int main ( ) 
{
    jogador ranking[100];
    int numjogadores = 0;

    carregarranking(ranking, &numjogadores);
    menu(ranking, &numjogadores);

    return 0;
}

//função que imprime o tabuleiro utilizando vetores
void imprimir(char tabuleiro[]) 
{
    printf("0. %c | 1. %c | 2. %c\n", tabuleiro[0], tabuleiro[1], tabuleiro[2]);
    printf("------------------\n");
    printf("3. %c | 4. %c | 5. %c\n", tabuleiro[3], tabuleiro[4], tabuleiro[5]);
    printf("------------------\n");
    printf("6. %c | 7. %c | 8. %c\n", tabuleiro[6], tabuleiro[7], tabuleiro[8]);
}

//função que verifica se algum jogador ganhou a partida
int verificarganhador(char tabuleiro[]) 
{
    int i;
    //verificando as linhas
    for (i = 0; i <= 6; i += 3)
    {
        if ((tabuleiro[i] == tabuleiro[i + 1]) && (tabuleiro[i + 1] == tabuleiro[i + 2]) && (tabuleiro[i] != ' ')) 
        {
            return 1;
        }
    }
    //verificando as colunas
    for (i = 0; i <= 2; i++)
    {
        if ((tabuleiro[i] == tabuleiro[i + 3]) && (tabuleiro[i + 3] == tabuleiro[i + 6]) && (tabuleiro[i] != ' ')) 
        {
            return 1;
        }
    }
    //verificando as diagonais
    if (((tabuleiro[0] == tabuleiro[4]) && (tabuleiro[4] == tabuleiro[8]) && (tabuleiro[0] != ' ')) || ((tabuleiro[2] == tabuleiro[4]) && (tabuleiro[4] == tabuleiro[6]) && (tabuleiro[2] != ' '))) 
    {
        return 1;
    }
    
    return 0;
}

//função do jogo
int jogodavelha(jogador ranking[], int *numjogadores, char nomejogador[], char tabuleiro[], int posicao, int rodadas, char jogador, int i) 
{
    char loop;
    //leitura do nome do jogador
    printf("Digite o seu nome:\n");
    setbuf(stdin, NULL);
    fgets(nomejogador, 15, stdin);
    nomejogador[strcspn(nomejogador, "\n")] = '\0';
    printf("\n");

    do 
    {
        //limpa o tabuleiro
        for (i = 0; i < 9; i++) 
        {
            tabuleiro[i] = ' ';
        }
        
        imprimir(tabuleiro);
        printf("\n\n");

        srand(time(NULL));

        for (rodadas = 1; rodadas <= 9; rodadas++) 
        {
            if (jogador == 'O')
            {
                do 
                {
                    posicao = rand() % 9;
                } while (tabuleiro[posicao] != ' ');

                tabuleiro[posicao] = jogador;
                imprimir(tabuleiro);
                printf("\n\n");

                if (verificarganhador(tabuleiro) == 1) 
                {
                    printf("O jogador %c venceu!\n\n", jogador);

                    for (i = 0; i < *numjogadores; i++) 
                    {
                        if (strcmp(ranking[i].nome, nomejogador) == 0) 
                        {
                            ranking[i].numderrotas++;
                            break;
                        }
                    }

                    if (i == *numjogadores) 
                    {
                        strcpy(ranking[*numjogadores].nome, nomejogador);
                        ranking[*numjogadores].numvitorias = 0;
                        ranking[*numjogadores].numderrotas = 1;
                        (*numjogadores)++;
                    }

                    break;
                }

                jogador = (jogador == 'O') ? 'X' : 'O';
            } else {
                printf("Digite um numero da posicao de 0 a 8:\n");
                scanf("%d", &posicao);

                if (tabuleiro[posicao] == ' ') 
                {
                    tabuleiro[posicao] = jogador;
                    imprimir(tabuleiro);
                    printf("\n\n");

                    if (verificarganhador(tabuleiro) == 1) 
                    {
                        printf("O jogador %c venceu!\n", jogador);

                        for (i = 0; i < *numjogadores; i++) 
                        {
                            if (strcmp(ranking[i].nome, nomejogador) == 0) 
                            {
                                ranking[i].numvitorias++;
                                break;
                            }
                        }

                        if (i == *numjogadores) 
                        {
                            strcpy(ranking[*numjogadores].nome, nomejogador);
                            ranking[*numjogadores].numvitorias = 1;
                            ranking[*numjogadores].numderrotas = 0;
                            (*numjogadores)++;
                        }

                        break;
                    }

                    jogador = (jogador == 'X') ? 'O' : 'X';
                } else {
                    printf("Posicao invalida!\n");
                }
            }
        }

        printf("Digite X se deseja jogar novamente\n");
        printf("Digite qualquer coisa para voltar ao menu\n");
        printf("---> ");
        scanf(" %c", &loop);

    } while ((loop == 'X') || (loop == 'x'));

    menu(ranking, numjogadores);
}

//função que atualiza o ranking
void salvarranking(jogador ranking[], int numjogadores) 
{
    int i;

    FILE *arquivo;
    arquivo = fopen("ranking.txt", "w");    //w cria um arquivo para o ranking e escreve

    if (arquivo == NULL) 
    {
        printf("Erro ao abrir o arquivo de ranking.\n");
        exit(1);
    }

    for (i = 0; i < numjogadores; i++) 
    {
        fprintf(arquivo, "%s %d %d\n", ranking[i].nome, ranking[i].numvitorias, ranking[i].numderrotas);
    }

    fclose(arquivo);
}

//função que imprime o ranking
void carregarranking(jogador ranking[], int *numjogadores) 
{
    int i = 0;
    
    FILE *arquivo;
    arquivo = fopen("ranking.txt", "r");    //r lê o arquivo

    if (arquivo == NULL) 
    {
        printf("Arquivo de ranking nao encontrado. Criando novo arquivo...\n");

        arquivo = fopen("ranking.txt", "w");    //cria um arquivo novo caso não exista
        if (arquivo == NULL)
        {
            printf("Erro na criacao do novo arquivo.\n");
            exit(1);
        }
    }

    while (fscanf(arquivo, "%s %d %d", &ranking[i].nome, &ranking[i].numvitorias, &ranking[i].numderrotas) != EOF) 
    {
        i++;
    }

    *numjogadores = i;

    fclose(arquivo);
}

//função do menu do jogo
int menu(jogador ranking[], int *numjogadores) 
{
    int op;

    do 
    {
        printf("\n\n--- JOGO DA VELHA ---\n\n");
        printf("\n(1) Jogar");
        printf("\n(2) Ranking");
        printf("\n(3) Sobre");
        printf("\n(4) Sair\n");
        printf("\nSelecione uma opcao: ");
        scanf("%d", &op);

    } while ((op < 1) || (op > 4));

    switch (op) 
    {
        case 1: {
            char nomejogador[15];
            char tabuleiro[9];
            int posicao = 0, rodadas = 0;
            char jogador = 'X';
            int i = 0;

            jogodavelha(ranking, numjogadores, nomejogador, tabuleiro, posicao, rodadas, jogador, i);

            break;
        }

        case 2: {
            int i;
            printf("\n--- RANKING ---\n\n");
            
            if (*numjogadores == 0) 
            {
                printf("Nenhum jogador registrado.\n");
            } else {
                printf("Posicao\tNome\t\tVitorias\tDerrotas\n");

                for (i = 0; i < *numjogadores; i++) 
                {
                    printf("%d\t%s\t\t%d\t\t%d\n", (i + 1), ranking[i].nome, ranking[i].numvitorias, ranking[i].numderrotas);
                }
            }

            break;
        }

        case 3: {
            printf("\nNome do jogo: Jogo da Velha\n");
            printf("Versao: 1.5.2\n");
            printf("Autores: Amanda Duarte, Caike Araujo e Matheus Saliba :)\n");
            printf("\nAproveite o jogo!\n");
            
            break;
        }

        case 4: {
            printf("Salvando ranking...\n");
            salvarranking(ranking, *numjogadores);
            
            printf("Jogo encerrado.\n");
            exit(1);
        
        }
    }

    menu(ranking, numjogadores);
}
