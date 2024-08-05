#include <stdio.h>
#include <stdlib.h>

int negativos(int n, float *vet);

int main() {

    int n;
    printf("Digite o tamanho do vetor: ");
    scanf("%d", &n);
    while (n <= 0) {
        printf("\nO tamanho do vetor deve ser positivo. Tente novamente: ");
        scanf("%d", &n);
    }

    float *vetor = (float *) malloc(sizeof(float));

    for (int i = 0; i < n; i++){
        printf("\nDigite o valor de vetor[%d]: ", i);
        scanf("%f", &vetor[i]);
    }

    int quant_neg = negativos(n, vetor);

    printf("\nO vetor [");
    for (int i = 0; i < n; i++) {
        printf("%.2f ", vetor[i]);
    }
    printf("] tem %d elementos negativos\n", quant_neg);

    free(vetor);

    return 0;
}

int negativos(int n, float *vet) {

    int negs = 0;

    for (int i = 0; i < n; i++) {
        if (vet[i] < 0) {
            negs++;
        }
    }

    return negs;

}