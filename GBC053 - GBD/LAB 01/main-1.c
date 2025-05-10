#include <stdio.h>
#include <stdlib.h>
#include <time.h>

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

void novo_nascimento(time_t *data) {
    time(data); // data corrente
    int dia = rand() % 18250; // um dia nos últimos 50 anos
    *data -= (dia * 24 * 60 * 60);
}

typedef struct registro { long long chave; char nome[100]; time_t nascimento; } registro;

int main() {
    srand(time(NULL));

    long long numregistros = 100000000;
    printf("Tamanho do registro: %d bytes\n", sizeof(registro));
    printf("Numero de registros: %d\n", numregistros);
    printf("Tamanho do arquivo: %.1f GB\n\n", (sizeof(registro) * numregistros) / (float)(1024*1024*1024));

    registro r;
    FILE *f = fopen("dados.bin","wb+");
    for (long long i = 1; i <= numregistros; i++) {
        r.chave = i;
        novo_nome(r.nome);
        novo_nascimento(&r.nascimento);
        fwrite(&r, sizeof(r), 1, f);
        if ((i + 1) % (numregistros/10) == 0) printf("%.0f%%\n",((i + 1)/(float)numregistros)*100.0);

        if (i % 1000000 == 0) { struct tm * t = localtime(&r.nascimento); printf("%lld %s %d/%d/%d %s", r.chave, r.nome, t->tm_mday, t->tm_mon+1, t->tm_year+1900, ctime(&r.nascimento)); }
    }
    fclose(f);
    printf("\n\nThat's all, folks!\n\n");
    return 0;
}
