/*

ALUNOS: Amanda Duarte Garcia - 12221BCC031
        Caua de Paula Dias - 12211BCC045

EX03: Índice Ordenado e Busca Binária

*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct registro { long long chave; char nome[100]; time_t nascimento; } registro;

// Função para busca binária
int busca_binaria(long long numregistros, char *nome_busca) {
    FILE *fd = NULL, *fi = NULL;
    registro r;
    long long posicao;
    int encontrado = 0;

    fi = fopen(indices, "rb");
    if (fi == NULL) {
        printf("Erro ao abrir arquivo.\n");
        return 1;
    }

    fd = fopen(arquivo_dados, "rb");
    if (fd == NULL) {
        printf("Erro ao abrir arquivo.\n");
        fclose(fi);
        return 1;
    }

    long long inicio = 0;
    long long fim = numregistros - 1;
    long long meio;

    while (inicio <= fim) {
        meio = (inicio + fim) / 2;
        fseek(fi, meio * sizeof(long long), SEEK_SET);

        if (fread(&posicao, sizeof(long long), 1, fi) != 1) {
            printf("Erro na leitura do indice.\n");
            fclose(fi);
            fclose(fd);
            return 1;
        }

        fseek(fd, (posicao - 1) * sizeof(registro), SEEK_SET);
        if (fread(&r, sizeof(registro), 1, fd) != 1) {
            printf("Erro na leitura do registro.\n");
            fclose(fi);
            fclose(fd);
            return 1;
        }

        int resultado = strcmp(nome_busca, r.nome);

        if (resultado == 0) {
            // Encontrou
            encontrado = 1;
            printf("Registro encontrado.\n");
            printf("Chave: %lld\n", r.chave);
            printf("Nome: %s\n", r.nome);
            printf("Nascimento: %s\n\n", ctime(&r.nascimento));
            break;
        } else if (resultado < 0) {
            // Nome buscado vem antes
            fim = meio - 1;
        } else {
            // Nome buscado vem depois
            inicio = meio + 1;
        }
    }

    if (!encontrado) {
        printf("Registro nao encontrado.\n\n");
    }

    fclose(fi);
    fclose(fd);
    return encontrado;
}

int main() {
    long long numregistros = 100000000;
    registro r, temp;
    char nome_busca[100];
    registro* registros = (registro*) calloc (numregistros, (sizeof(registro)));
    FILE *fd = NULL, *fi = NULL;

    printf("Iniciando leitura do arquivo de dados...\n");
    fd = fopen("dados.bin", "rb");
    if(fd == NULL) {
        printf("Erro ao abrir o arquivo.\n");
        return 1;
    }
    printf("Leitura concluida.\n\n");

    // Ordenando os nomes em ordem alfabética
    printf("\nIniciando ordenacao...\n");
    for(long long i = 0; i < numregistros; i++) {
        fread(&r, sizeof(registro), 1, f);
        registros[i] = r;
        for(long long j = i; j > 0; j--) {
            if(strcmp(registros[j-1].nome, r.nome) > 0) {
                temp = registros[j-1];
                registros[j-1] = r;
                registros[j] = temp;
            }
        }
    }
    fclose(fd);
    printf("Ordenacao concluida.\n\n");

    printf("Criando arquivo de indices...\n");
    fi = fopen("indices.bin", "wb+");
    if(fi == NULL) {
        printf("Erro ao abrir o arquivo.\n");
        return 1;
    }

    // Escrevendo o arquivo indices.bin a partir da ordenação feita
    printf("Adicionando indices no arquivo...\n");
    for(long long i = 0; i < numregistros; i++) {
        fwrite(&registros[i].chave, sizeof(long long), 1, f);
    }
    free(registros);
    fclose(fi);
    printf("Arquivo de indices pronto.\n\n");

    // Chamando a busca binária
    printf("Digite o nome a ser buscado: ");
    fgets(nome_busca, 100, stdin);
    nome_busca[strcspn(nome_busca, "\n")] = '\0';
    printf("Iniciando busca binaria...\n\n");
    busca_binaria(numregistros, nome_busca);

    return 0;
}
