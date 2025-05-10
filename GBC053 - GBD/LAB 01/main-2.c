#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>

char nomes[37][20] = {"Amanda","Ana","Bernardo","Breno","Carla","Carlos","Caua","Caue","Douglas","Eduardo","Enzo","Eugenio","Felipe","Gabriel","Giovanna","Guilherme","Gullit","Gustavo","Hugo","Isabela","Jean","Joao","Lazaro","Leandro","Lucas","Luis","Luiz","Marcos","Matheus","Murilo","Osvaldo","Paulo","Pedro","Vanessa","Vinícius","Vítor","Willian"};
char sobrenomes[37][20] = {"Andrade","Asevedo","Barbosa","Belchior","Beppler","Bessa","Biazi","Campos","Carvalho","Casa","Cavalcante","Dias","Eustaquio","Ferreira","Fonseca","Garcia","Graffunder","Jerse","Lacerda","Manhoso","Marins","Marques","Martins","Moreira","Neres","Oliveira","Otoni","Paula","Pereira","Pires","Porto","Prado","Saliba","Santana","Silva","Soares","Souza"};

void novo_nome(char *str) {
   int posicao = rand() % 37;
   strcpy(str,nomes[posicao]); // primeiro nome
   strcat(str," ");
   int segundonome = rand() % 2;
   if (segundonome == 1) {
       posicao = rand() % 37;
       strcat(str,nomes[posicao]); // segundo nome
       strcat(str," ");
   }
   int quantidade = rand() % 3 + 1;
   for (int i = 0; i < quantidade; i++) {
       posicao = rand() % 37;
       strcat(str,sobrenomes[posicao]); // sobrenomes
       if (i < quantidade-1)
           strcat(str," ");
   }
}

typedef struct registro { long long chave; char nome[100]; time_t nascimento; } registro;

// Função para a busca sequencial
void busca_sequencial(FILE *f, char *chave_busca) {
    registro r;
    int encontrados = 0;
    clock_t inicio = clock();
 
    rewind(f);
    while (fread(&r, sizeof(registro), 1, f)) {
        if (strstr(r.nome, chave_busca)) {
            struct tm *t = localtime(&r.nascimento);
            printf("Chave: %lld, Nome: %s, Nascimento: %d/%d/%d\n",
                   r.chave, r.nome, t->tm_mday, t->tm_mon + 1, t->tm_year + 1900);
            encontrados++;
        }
    }
 
    clock_t fim = clock();
    double tempo = ((double)(fim - inicio)) / CLOCKS_PER_SEC;
    printf("\nRegistros encontrados: %d\n", encontrados);
    printf("Tempo de busca sequencial: %.6f segundos\n\n", tempo);
}

// Função para a busca por posição 
void busca_posicao(FILE *f, long long posicao) {
    registro r;
    clock_t inicio = clock();
 
    fseek(f, (posicao - 1) * sizeof(registro), SEEK_SET);
    if (fread(&r, sizeof(registro), 1, f)) {
        struct tm *t = localtime(&r.nascimento);
        printf("Chave: %lld, Nome: %s, Nascimento: %d/%d/%d\n",
               r.chave, r.nome, t->tm_mday, t->tm_mon + 1, t->tm_year + 1900);
    } else {
        printf("Registro nao encontrado.\n\n");
    }
 
    clock_t fim = clock();
    double tempo = ((double)(fim - inicio)) / CLOCKS_PER_SEC;
    printf("Tempo de busca por posicao: %.6f segundos\n\n", tempo);
}

int main() {
    srand(time(NULL));
 
    char* nome;
    long long posicao;
    FILE *f = NULL;

    printf("Acessando o arquivo...\n");
    f = fopen("dados.bin", "rb");
    if(f == NULL) {
        printf("Erro ao abrir o arquivo.\n");
        return 1;
    }
    printf("Arquivo aberto com sucesso.\n\n");
    
    // Implementação da busca sequencial
    printf("Gerando o nome para busca sequencial...\n");
    novo_nome(nome);
    printf("Nome gerado: %s\n\n", nome);
    printf("Buscando nome no arquivo...\n\n");
    busca_sequencial(f, nome);
    
    // Implementação da busca por posição
    printf("Digite a posicao do registro: ");
    scanf("%lld", &posicao);
    printf("Buscando posicao no arquivo...\n\n");
    busca_posicao(f, posicao);

    return 0;
}
