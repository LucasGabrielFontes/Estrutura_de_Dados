#include <stdio.h>
#include <math.h>

int raizes(float , float , float , float *, float *);

int main() {

    float a, b, c; // Coeficientes da funcao do segundo grau
    float x1, x2; // Raizes da funcao
    int quant_raizes; // Quantidade de raizes da funcao

    printf("Informe o valor de a na equacao: ax^2 + bx + c: ");
    scanf("%f", &a);

    printf("\nInforme o valor de b na equacao: %.2fx^2 + bx + c: ", a);
    scanf("%f", &b);

    printf("\nInforme o valor de c na equacao: %.2fx^2 + %.2fx + c: ", a, b);
    scanf("%f", &c);

    quant_raizes = raizes(a, b, c, &x1, &x2);

    if (quant_raizes == 0) {
        printf("\nNao ha raizes reais para a funcao %.2fx^2 + %.2fx + %.2f\n", a, b, c);
    } else if (quant_raizes == 1) {
        printf("\n%.2f e a unica raiz para a funcao %.2fx^2 + %.2fx + %.2f\n", x1, a, b, c);
    } else {
        printf("\n%.2f e %.2f sao as duas raizes da funcao %.2fx^2 + %.2fx + %.2f\n", x1, x2, a, b, c);
    }

    return 0;

}

int raizes(float a, float b, float c, float *x1, float *x2) {

    float delta; // Valor de delta calcula a partir dos coeficientes da a, b, c da equacao

    delta = pow(b, 2) - 4*a*c;

    if (delta < 0) {
        return 0;
    } else {

        *x1 = (-b + sqrt(delta))/(2*a);
        *x2 = (-b - sqrt(delta))/(2*a);

        if (*x1 != *x2) {
            return 2;
        } else {
            return 1;
        }

    }

}