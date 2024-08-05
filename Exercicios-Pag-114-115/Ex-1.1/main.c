#include <stdio.h>

int dentro_ret(int , int , int , int , int , int );

int main() {

    int x0, y0; // Vertice inferior esquerdo do retangulo
    int x1, y1; // Vertice superior direito do retangulo
    int x, y; // Coordenadas do ponto
    int resultado; // Armazena o valor de retorno da funcao dentro_ret(), mostrando se o ponto pertence ao retangulo (1), nao pertence (0) ou se os valores dos vertices sao invalidos (-1)

    printf("Insira a coordenada (x0, y0) do vertice inferior esquerdo do retangulo com os valores separados por um espaco: ");
    scanf("%d %d", &x0, &y0);

    printf("\nInsira a coordenada (x1, y1) do vertice superior direito do retangulo com os valores separados por um espaco: ");
    scanf("%d %d", &x1, &y1);

    printf("\nInsira a coordenada (x, y) do ponto com os valores separados por um espaco: ");
    scanf("%d %d", &x, &y);

    resultado = dentro_ret(x0, y0, x1, y1, x, y);

    if (resultado == 1) {
        printf("\nO ponto (%d, %d) ESTA contido no retangulo de vertice inferior esquerdo (%d, %d) e vertice superior direito (%d, %d).\n", x, y, x0, y0, x1, y1);
    } else if (resultado == 0) {
        printf("\nO ponto (%d, %d) NAO ESTA contido no retangulo de vertice inferior esquerdo (%d, %d) e vertice superior direito (%d, %d).\n", x, y, x0, y0, x1, y1);
    } else {
        printf("O vertice inferior esquerdo (%d, %d) e o vertice superior direito (%d, %d) nao sao validos para a formacao de um retangulo.\n", x0, y0, x1, y1);
    }

    return 0;

}

int dentro_ret(int x0, int y0, int x1, int y1, int x, int y) {

    if (x0 == x1 || y0 == y1) {
        return -1;
    } else if (x1 < x0 || y1 < y0) {
        return -1;
    }

    if ((x >= x0 && x <= x1) && (y >= y0 && y <= y1)) {
        return 1;
    } else {
        return 0;
    }

}