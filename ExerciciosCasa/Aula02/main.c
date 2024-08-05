/* 
 * Passo 1) Ler “primeiro nome” e “idade” de n pessoas; Guardar dados em um arquivo texto;
 * Passo 2) Mostrar o nome das pessoas maiores de 18 anos;
 * Passo 3) Ordenar alfabeticamente os nomes (com idades respectivas); Salvar em um novo arquivo.
 */

#include <stdio.h>
#include <string.h>
#include <ctype.h>

#define tamString 51

typedef struct{
    char nome[tamString];
    int idade;
} Pessoa;

void ordenaVetorPessoas(Pessoa [], int );
void trocaElementos(Pessoa * , Pessoa * );

int main() {

    FILE *arquivo; // Arquivo principal
    FILE *arquivoOrdenado; // Arquivo ordenado alfabeticamente
    int p; // Quantidade de pessoas que terao seus dados armazenados no arquivo 

    arquivo = fopen("arquivo.txt", "w");

    if (arquivo == NULL) {
        printf("Nao foi possivel abrir o arquivo!\n");
    } else {

        printf("Informe a quantidade de pessoas que terao seus dados armazenados no arquivo: ");
        scanf("%d", &p);

        while (p < 0) {
            printf("\nQuantidade de pessoas invalida. Tente novamente: ");
            scanf("%d", &p);
        }

        // Vetor do struct tipo Pessoa que armazera os dados das pessoas para comparacao
        Pessoa pessoas[p];

        // Limpa o buffer de entrada para nao atrapalhar na aquisicao das informacoes das pessoas
        while (getchar() != '\n');

        // Recebe os dados de todas as pessoas, armazenando-os no arquivo .txt e no vetor pessoas
        for (int i = 0; i < p; i++) {

            char nome[tamString];
            int idade;
            printf("\nDigite o primeiro nome e a idade da %da pessoa separados por um espaco apenas: ", i+1);
            scanf("%s %d", nome, &idade);

            // Salva as informacoes no vetor pessoas, no seu respectivo espaco
            strcpy(pessoas[i].nome, nome);
            pessoas[i].idade = idade;

            // Salva as informacoes no arquivo .txt
            fprintf(arquivo, "%s %d\n", nome, idade);

        }

        fclose(arquivo);

        printf("\nPessoas com idade maior que 18 anos: \n\n");

        for (int i = 0; i < p; i++) {

            if (pessoas[i].idade > 18) {
                printf("%s %d\n", pessoas[i].nome, pessoas[i].idade);
            }

        }

        ordenaVetorPessoas(pessoas, p);

        arquivoOrdenado = fopen("arquivoOrdenado.txt", "w");

        if (arquivoOrdenado == NULL) {
            printf("Nao foi possivel abrir o arquivo!\n");
        } else {

            for (int i = 0; i < p; i++) {
                fprintf(arquivoOrdenado, "%s %d\n", pessoas[i].nome, pessoas[i].idade);
            }

            fclose(arquivoOrdenado);

        }

    }

    return 0;

}

void trocaElementos(Pessoa *pessoa1, Pessoa *pessoa2) {

    char nomeTemp[tamString];
    int idadeTemp;

    strcpy(nomeTemp, pessoa1->nome);
    idadeTemp = pessoa1->idade;

    strcpy(pessoa1->nome, pessoa2->nome);
    pessoa1->idade = pessoa2->idade;

    strcpy(pessoa2->nome, nomeTemp);
    pessoa2->idade = idadeTemp;

}

void ordenaVetorPessoas(Pessoa pessoas[], int p) {

    for (int i = 0; i < p; i++) {

            // Variaveis que armazenarao os nomes a serem comparados alfabeticamente
            char nome1[tamString];
            char nome2[tamString];

            for (int j = i+1; j < p; j++) {

                strcpy(nome1, pessoas[i].nome);
                strcpy(nome2, pessoas[j].nome);

                int c = 0; // Variavel usada para percorrer os nomes e compara-los caractere a caractere
                while (nome1[c] >= nome2[c]) {

                    if (toupper(nome1[c]) > toupper(nome2[c])) {
                        trocaElementos(&pessoas[i], &pessoas[j]);
                        break;
                    } 

                    c++;

                }

            }

        }

}