// Esse codigo foi feito um dia antes da prova, apenas para fins de revisao rapida

#include <stdio.h>
#include <stdlib.h>

struct no {
    int dado;
    struct no *prox;
};

struct no* cria_lista();
int insere_inicio(struct no **pont_lista);
int insere_fim(struct no **pont_lista);
int insere_meio(struct no **pont_lista);
int lista_vazia(struct no *pont_lista);
void mostra_lista(struct no *pont_lista);

int main() {

    struct no *lista;

    lista = cria_lista();

    if (lista_vazia(lista)) {
        printf("A lista esta vazia!\n");
    } else {
        printf("A lista NAO esta vazia!\n");
    }

    insere_fim(&lista);
    insere_fim(&lista);
    insere_fim(&lista);
    insere_fim(&lista);
    insere_inicio(&lista);
    insere_inicio(&lista);
    insere_inicio(&lista);
    insere_meio(&lista);

    mostra_lista(lista);

    return 0;
}

void mostra_lista(struct no *pont_lista) {
    for (struct no *l = pont_lista; l != NULL; l = l->prox) {
        printf("%d ", l->dado);
    }
}

int insere_meio(struct no **pont_lista) {

    struct no *novo = (struct no*) malloc(sizeof(struct no));

    if (novo == NULL) {
        printf("A memoria ta cheia, rapaz!\n");
        return 0;
    }

    int i = 8;
    int num = 666;
    novo->dado = num;

    int cont = -1;

    if (i == 0) {
        struct no *temp = *pont_lista;
        *pont_lista = novo;
        novo->prox = temp;
        printf("Elemento inserido com sucesso!\n");
        return 1;
    }

    for (struct no *l = *pont_lista; l != NULL; l = l->prox) {

        cont++;

        if (cont == i-1) {
            struct no *temp = l->prox;
            l->prox = novo;
            novo->prox = temp;
            printf("Elemento inserido com sucesso!\n");
            return 1;
        }

    }

    printf("Indice invalido!\n");
    return 0;

}

int insere_inicio(struct no **pont_lista) {
    struct no *novo = (struct no*) malloc(sizeof(struct no));

    if (novo == NULL) {
        printf("A memoria ta cheia, rapaz!\n");
        return 0;
    }

    int num = 999;
    novo->dado = num;

    if (*pont_lista == NULL) { // Lista vazia
        *pont_lista = novo;
        novo->prox = NULL;
        printf("Elemento inserido com sucesso!\n");
        return 1;
    }

    struct no *temp = *pont_lista;
    *pont_lista = novo;
    novo->prox = temp;
    printf("Elemento inserido com sucesso!\n");
    return 1;
}

int insere_fim(struct no **pont_lista) {

    int num = 777;

    struct no *novo = (struct no*) malloc(sizeof(struct no));
    if (novo == NULL) {
        printf("Lista cheia!\n");
        return 0;
    }

    novo->dado = num;

    if (*pont_lista == NULL) {
        *pont_lista = novo;
        novo->prox = NULL;
        printf("Elemento inserido!\n");
        return 1;
    }

    for (struct no *l = *pont_lista; l != NULL; l = l->prox) {
        if (l->prox == NULL) {
            l->prox = novo;
            novo->prox = NULL;
            printf("Elemento inserido!\n");
            return 1;
        }
    }
    return 0;
}

int lista_vazia(struct no *pont_lista) {
    if (pont_lista == NULL) return 1;
    return 0;
}

struct no* cria_lista() {
    return NULL;
}