#include <stdio.h>

int soma_impares(int );

int main() {

    int n; // n primeiros numeros impares naturais que entrarao na soma
    int soma; // Soma dos n primeiros numeros naturais impares

    printf("Informe o valor n para que a soma dos n primeiros numeros naturais impares seja calculada: ");
    scanf("%d", &n);

    soma = soma_impares(n);

    printf("\nSoma dos %d primeiros numeros naturais impares: %d\n", n, soma);

    return 0;

}

int soma_impares(int n) {

    int num = 1; // Variavel que percorrera os numeros naturais impares
    int soma = 0; // Armazena a soma dos numeros impares
    for (int i = 0; i < n; i++) {
        soma += num;
        num += 2;
    }

    return soma;

}