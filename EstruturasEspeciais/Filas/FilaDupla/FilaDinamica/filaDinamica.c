#include "filaDinamica.h"
#include <stdio.h>
#include <stdlib.h>

int main(){
    struct Fila *filaDupla;
    filaDupla = cria_fila();
    if (filaDupla == NULL) {
        printf("A alocacao dinamica falhou!\n");
        return 1;
    }

    insere_fim(filaDupla, 2);
    insere_inicio(filaDupla, 1);
    insere_fim(filaDupla, 3);
    insere_inicio(filaDupla, 0);
    insere_fim(filaDupla, 4);

    mostra_fila(*filaDupla);

    retira_inicio(filaDupla);

    mostra_fila(*filaDupla);

    retira_fim(filaDupla);

    mostra_fila(*filaDupla);

    retira_inicio(filaDupla);

    mostra_fila(*filaDupla);

    retira_fim(filaDupla);

    mostra_fila(*filaDupla);

    retira_fim(filaDupla);

    mostra_fila(*filaDupla);

    libera_fila(filaDupla);

    return 0;
}

void insere_inicio(struct Fila *fila, int num) {
    struct no *novo = (struct no *) malloc(sizeof(struct no));
    if (novo == NULL) return;

    novo->dado = num;

    if (fila_vazia(*fila)) {
        novo->ant = NULL;
        novo->prox = NULL;
        fila->ext1 = novo;
        fila->ext2 = novo;
        return;
    }

    novo->prox = fila->ext1;
    novo->ant = NULL;
    fila->ext1->ant = novo;
    fila->ext1 = novo;
}

void insere_fim(struct Fila *fila, int num) {

    struct no *novo = (struct no *) malloc(sizeof(struct no));
    if(novo == NULL) return;
    
    novo->dado = num;

    if (fila_vazia(*fila)) {
        novo->ant = NULL;
        novo->prox = NULL;
        fila->ext1 = novo;
        fila->ext2 = novo;
        return;
    }

    novo->prox = NULL;
    novo->ant = fila->ext2;
    fila->ext2->prox = novo;
    fila->ext2 = novo;

}

void retira_fim(struct Fila *fila) {

    if (fila_vazia(*fila)) {
        printf("A fila esta vazia!\n");
        return;
    }

    if (fila->ext1 == fila->ext2) {
        struct no *aux = fila->ext1;
        fila->ext1 = NULL;
        fila->ext2 = NULL;
        free(aux);
        return;
    }

    struct no *aux = fila->ext2;
    fila->ext2->ant->prox = NULL;
    fila->ext2 = fila->ext2->ant;
    free(aux);

}

void retira_inicio(struct Fila *fila) {

    if(fila_vazia(*fila)) {
        printf("A fila esta vazia!\n");
        return;
    }

    if (fila->ext1 == fila->ext2) {
        struct no *aux = fila->ext1;
        fila->ext1 = NULL;
        fila->ext2 = NULL;
        free(aux);
        return;
    }

    struct no *aux = fila->ext1;
    fila->ext1->prox->ant = NULL;
    fila->ext1 = fila->ext1->prox;
    free(aux);

}

void mostra_fila(struct Fila fila) {
    if (fila_vazia(fila)) {
        printf("A fila esta vazia!\n");
        return;
    }

    for (struct no *aux = fila.ext1; aux != NULL; aux = aux->prox) {
        printf("%d ", aux->dado);
    }

    printf("\n");
}

void libera_fila(struct Fila *fila) {

    for (struct no *aux = fila->ext1; aux != NULL; aux = aux->prox) {
        struct no *atual = aux->prox;
        free(aux);
        aux = atual;
    }

    fila->ext1 = NULL;
    fila->ext2 = NULL;
    free(fila);

}

struct Fila *cria_fila() {
    struct Fila *fila = (struct Fila *) malloc(sizeof(struct Fila));
    if (fila == NULL) return NULL;
    fila->ext1 = NULL;
    fila->ext2 = NULL;
    return fila;
}

int fila_vazia(struct Fila fila){
    if (fila.ext1 == NULL && fila.ext2 == NULL) return 1;
    return 0;
}