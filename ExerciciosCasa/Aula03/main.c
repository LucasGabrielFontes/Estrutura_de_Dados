/*
 * Proposito do codigo: fazer uma funcao que conta todas as vogais de um vetor 
 * de caracteres local à main()
 */

#include <stdio.h>
#include <string.h>
#include <ctype.h>

#define TAM 51

int isVogal(char );
int contaVogais(char *);

int main() {

    char palavra[TAM];
    int vogais = 0; // Armazena a quantidade de vogais na palavra

    printf("Digite a palavra e finaliza-a com um '.': ");

    int i;
    for (i = 0; palavra[i-1] != '.' && i < TAM; i++) {
        scanf(" %c", &palavra[i]);
    }
    palavra[i-1] = '\0'; // Determina o fim da string

    vogais = contaVogais(palavra);

    printf("\nA palavra %s possui %d vogais.\n", palavra, vogais);

    return 0;

}

int isVogal(char carac) {
    if (tolower(carac) == 'a' || tolower(carac) == 'e' || tolower(carac) == 'i' || tolower(carac) == 'o' || tolower(carac) == 'u') {
        return 1;
    }

    return 0;
}

int contaVogais(char *palavra) {

    int vogais = 0;
    int i = 0;
    while (palavra[i] != '\0') {
        if (isVogal(palavra[i])) {
            vogais++;
        }
        i++;
    }

    return vogais;

}