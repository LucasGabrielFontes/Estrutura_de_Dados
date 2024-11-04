#include <stdio.h>
#include <stdlib.h>

#define TAM 5

struct Fila {
    int ext1;
    int dados[TAM];
    int ext2;
};

struct Fila *cria_fila();
int fila_cheia(struct Fila );
int fila_vazia(struct Fila );
void insere_inicio(struct Fila *, int );
void insere_fim(struct Fila *, int );
void libera_fila(struct Fila * );
void mostra_fila(struct Fila );
void retira_inicio(struct Fila *);
void retira_fim(struct Fila *);

int main() {

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

void mostra_fila(struct Fila fila) {

    if (fila_vazia(fila)) {
        printf("A lista esta vazia!\n");
        return;
    }

    int i = fila.ext1;
    while (1) {
        printf("%d ", fila.dados[i]);
        if (i == fila.ext2) {
            printf("\n");
            return;
        }
        i = (i+1)%TAM;
    }

}

void insere_inicio(struct Fila *fila, int num) {
    if (fila_cheia(*fila)) {
        printf("A fila esta cheia!\n");
        return;
    }

    if (fila_vazia(*fila)) {
        fila->dados[0] = num;
        fila->ext1++;
        fila->ext2++;
        return;
    }

    int indice = fila->ext1 - 1;
    if (indice < 0) 
        indice = TAM-1;

    fila->dados[indice] = num;
    fila->ext1 = indice;
}

void insere_fim(struct Fila *fila, int num) {

    if(fila_cheia(*fila)) {
        printf("A fila esta cheia!\n");
        return;
    }

    if (fila_vazia(*fila)) {
        fila->dados[0] = num;
        fila->ext1++;
        fila->ext2++;
        return;
    }

    int indice = (fila->ext2+1)%TAM;
    fila->dados[indice] = num;
    fila->ext2 = indice;

}

void retira_inicio(struct Fila *fila) {
    if (fila_vazia(*fila)) {
        printf("A fila esta vazia!\n");
        return;
    }

    if (fila->ext1 == fila->ext2) { // So acontece se a lista tiver apenas um elemento, apos a verificacao de lista vazia
        fila->ext1 = -1;
        fila->ext2 = -1;
        return;
    }

    fila->ext1 = (fila->ext1+1)%TAM;
}

void retira_fim(struct Fila *fila) {

    if(fila_vazia(*fila)) {
        printf("A fila esta vazia!\n");
        return;
    }

    if (fila->ext1 == fila->ext2) {
        fila->ext1 = -1;
        fila->ext2 = -1;
        return;
    }

    fila->ext2 = fila->ext2-1;
    if (fila->ext2 < 0)
        fila->ext2 = TAM-1;

}

struct Fila *cria_fila(){
    struct Fila* fila = (struct Fila *) malloc(sizeof(struct Fila));
    if (fila == NULL) return NULL;
    fila->ext1= -1;
    fila->ext2 = -1;
    return fila;
}

int fila_vazia(struct Fila fila) {
    if (fila.ext1 == -1 && fila.ext2 == -1) return 1;
    return 0;
}

int fila_cheia(struct Fila fila) {
    if ((fila.ext2 + 1)%TAM == fila.ext1) return 1;
    return 0;
}

void libera_fila(struct Fila *fila) {
    free(fila);
}