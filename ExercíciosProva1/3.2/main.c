#include <stdio.h>
#include <stdlib.h>

int pares(int n, int *vet);

int main() {

    int n;
    printf("Digite o tamanho do vetor: ");
    scanf("%d", &n);
    while(n <= 0){
        printf("\nO tamanho do vetor deve ser positivo. Tente novamente: ");
        scanf("%d", &n);
    }

    int *vetor = (int *) malloc(sizeof(int));
    for (int i = 0; i < n; i++) {
        printf("\nDigite o valor de vetor[%d]: ", i);
        scanf("%d", &vetor[i]);
    }

    int quant_pares = pares(n, vetor);

    printf("\nO vetor informado tem %d elementos pares.\n", quant_pares);

    free(vetor);
    return 0;
}

int pares(int n, int *vet){
    int par = 0;
    for (int i = 0; i < n; i++){
        if (vet[i]%2 == 0) {
            par++;
        }
    }

    return par;
}