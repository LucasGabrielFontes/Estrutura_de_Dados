#include <stdio.h>

int primo(int);

int main() {

    int n; // Numero a ser analisado

    printf("Digite o numero para a analise de primalidade: ");
    scanf("%d", &n);

    if (primo(n)) {
        printf("\nO numero %d e primo\n", n);
    } else {
        printf("\nO numero %d nao e primo\n", n);
    }

    return 0;

}

int primo(int n) {

    for (int i = 2; i*i <= n; i++) {
        if (n%i == 0) {
            return 0;
        }
    }

    return 1;

}