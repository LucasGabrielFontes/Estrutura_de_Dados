#include <stdio.h>
#include <math.h>

double calcula_pi (int );

int main() {

    int n; // Quantidade de números do somatorio que serao utilizados para o calculo aproximado do valor de pi
    double pi; // Valor aproximado de PI

    printf("Insira a quantidade de numeros que serao utilizados no somatorio para o calculo aproximado de pi: ");
    scanf("%d", &n);

    pi = calcula_pi(n);

    printf("Valor aproximado de pi com o somatorio de %d termos: %.2f", n, pi);

    return 0;

}

double calcula_pi (int n) {

    double somatorio = 0;

    for (int i = 0; i < n; i++) {
        somatorio += (1*(pow(-1, i)))/(2*i + 1);
    }

    return 4*somatorio;

}