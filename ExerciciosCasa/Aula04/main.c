#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define TAM 51

void retiraNovaLinha(char * );

int main() {

    char **nomes = (char**) malloc(10*sizeof(char*)); // Aloca 10 posicoes de memoria que apontarao, cada uma, para um vetor de caracteres

    if (nomes == NULL) {
        printf("Alocacao dinamica falhou!\n");
        return 0;
    }

    // Aloca dinamicamente cada posicao do vetor 'nomes' e as preenche com os nomes digitados pelo usuario
    for (int i = 0; i < 10; i++) {

        char nome[TAM];
        printf("Digite o %do nome: ", i+1);
        fgets(nome, TAM, stdin);
        retiraNovaLinha(nome);

        // Aloca dinamicamente um vetor de char de tamanho TAM (51) para cada posicao do vetor 'nomes'
        nomes[i] = (char*) malloc((strlen(nome) + 1)*sizeof(char));

        // Se a alocacao falhar, toda a memoria sera devidamente liberada antes do programa ser encerrado
        if (nomes[i] == NULL) {

            for (int j = 0; j <= i; j++) {
                free(nomes[j]);
            }

            free(nomes);
            printf("Alocacao dinamica falhou!\n");
            return 0;

        }

        strcpy(nomes[i], nome);

    }

    // Os nomes armazenados no vetor 'nomes' sao mostrados na tela
    for (int i = 0; i < 10; i++) {

        printf("%p\n", &nomes[i]);
        printf("%s\n", nomes[i]);
        printf("%d\n", strlen(nomes[i]));
        free(nomes[i]);

    }

    free(nomes);

    return 0;

}

void retiraNovaLinha(char *palavra) {

    int i = 0;
    while (palavra[i] != '\0') {
        if (palavra[i] == '\n') {
            palavra[i] = '\0';
            return;
        }
        i++;
    }

}