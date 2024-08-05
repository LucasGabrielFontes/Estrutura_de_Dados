#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define COMP 100

int main() {

    int tam;
    printf("Digite a quantidade de strings que serao guardadas no vetor: ");
    scanf("%d", &tam);
    while (getchar() != '\n');

    char **vetor = (char**) malloc(tam*sizeof(char*));

    if (vetor == NULL) {
        printf("Alocacao dinamina falhou!\n");
        return 1;
    }

    for (int i = 0; i < tam; i++) {

        char string[COMP];
        printf("Digite a %da string: ", i+1);
        fgets(string, COMP, stdin);

        vetor[i] = (char*) malloc((strlen(string) + 1)*sizeof(char));

        if (vetor[i] == NULL) {
            printf("A alocacao dinamica falhou!\n");
            for (int aux = 0; aux <= i; aux++) {
                free(vetor[i]);
            }
            free(vetor);
            return 1;
        }

        strcpy(vetor[i], string);

    }

    printf("\n\nVetor criado: \n");
    for (int i = 0; i < tam; i++) {
        printf("%s", vetor[i]);
    }

    for (int i = 0; i < tam; i++) {
        free(vetor[i]);
    }

    free(vetor);

    return 0;

}