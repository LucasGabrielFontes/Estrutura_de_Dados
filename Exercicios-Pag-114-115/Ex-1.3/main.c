#include <stdio.h>

int fibonacci(int n);

int main() {

    int n; // Indice no numero da sequencia de Fibonacci
    int num; // n-esimo numero da sequencia de Fibonacci

    printf("Digite o indice do numero desejado da sequencia de Fibonacci: ");
    scanf("%d", &n);

    num = fibonacci(n);

    printf("\n%do numero da sequencia de Fibonacci: %d\n", n, num);

    return 0;

}

int fibonacci(int n) {

    int a = 1;
    int b = 1;

    for (int i = 2; i < n; i++) {
        int c = a + b;
        a = b;
        b = c;
    }

    return b;

}