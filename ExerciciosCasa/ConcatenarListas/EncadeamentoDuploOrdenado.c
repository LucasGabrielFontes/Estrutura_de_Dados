#include <stdio.h>
#include <stdlib.h>

struct no{
    struct no *ant;
    int dado;
    struct no *prox;
};

struct Lista{
    struct no *i;
    struct no *f;
};

void concatena(struct Lista *lista1, struct Lista *lista2);
void free_lista(struct Lista *lista);
int insere(struct Lista *lista, int num);
int lista_vazia(struct Lista lista);
void mostra_lista(struct Lista lista);
struct Lista new_lista();

int main(){

    struct Lista lista1 = new_lista();
    struct Lista lista2 = new_lista();

    insere(&lista1, 5);
    insere(&lista1, 1);
    insere(&lista1, 3);
    insere(&lista1, 9);
    insere(&lista1, 7);

    insere(&lista2, 10);
    insere(&lista2, 2);
    insere(&lista2, 6);
    insere(&lista2, 8);
    insere(&lista2, 4);

    printf("Lista 1: ");
    mostra_lista(lista1);
    printf("Lista 2: ");
    mostra_lista(lista2);

    printf("\nConcatenando...\n\n");
    concatena(&lista1, &lista2);
    printf("Lista concatenada: ");
    mostra_lista(lista1);

    free_lista(&lista1);
    free_lista(&lista2);

    return 0;
}

struct Lista new_lista() {
    struct Lista lista;
    lista.i = NULL;
    lista.f = NULL;
    return lista;
}

int insere (struct Lista *lista, int num) {

    struct no *novo = (struct no *) malloc (sizeof(struct no));
    if (novo == NULL) return 0;
    novo->dado = num;

    if (lista_vazia(*lista)) {
        novo->prox = NULL;
        novo->ant = NULL;
        lista->i = novo;
        lista->f = novo;
        return 1;
    }

    if (num <= lista->i->dado) { // O no sera inserido no inicio
        novo->prox = lista->i;
        novo->ant = NULL;
        lista->i->ant = novo;
        lista->i = novo;
        return 1;
    }

    for (struct no *aux = lista->i; aux != NULL; aux = aux->prox) { // O no sera inserido no meio
        if (num <= aux->dado) {
            novo->prox = aux;
            novo->ant = aux->ant;
            aux->ant->prox = novo;
            aux->ant = novo;
            return 1;
        }
    }

    // Se chegou aqui, o no sera inserido no fim da lista
    novo->prox = NULL;
    novo->ant = lista->f;
    lista->f->prox = novo;
    lista->f = novo;
    return 1;
}

void concatena(struct Lista *lista1, struct Lista *lista2) {

    if (lista_vazia(*lista2)) return;
    if (lista_vazia(*lista1)) {
        lista1->i = lista2->i;
        lista1->f = lista2->f;
        lista2->i = NULL;
        lista2->f = NULL;
        return;
    }

    struct no *aux2 = lista2->i;

    while (aux2 != NULL) {
        insere(lista1, aux2->dado);
        aux2 = aux2->prox;
    }

    // for (struct no *aux1 = lista1->i; aux1 != NULL && aux2 != NULL; aux1 = aux1->prox) {

    //     if (aux2->dado <= aux1->dado) {

    //         struct no *prox = aux2->prox;

    //         if (lista1->i == aux1) {
    //             aux2->prox = aux1;
    //             aux2->ant = aux1->ant;
    //             aux1->ant = aux2;
    //             lista1->i = aux2;
    //         } else {
    //             aux2->prox = aux1;
    //             aux2->ant = aux1->ant;
    //             aux1->ant->prox = aux2;
    //             aux1->ant = aux2;
    //         }

    //         aux2 = prox;
    //         aux2->ant = NULL;
    //     }
    // }

    // // Se chegou aqui, deve-se apenas inserir ordenadamente os elementos da lista 2 no fim da lista 1
    // while (aux2 != NULL) {
    //     struct no *prox = aux2->prox;
    //     aux2->ant = lista1->f;
    //     aux2->prox = NULL;
    //     lista1->f->prox = aux2;
    //     lista1->f = aux2;
    //     aux2 = prox;
    // }

}

void mostra_lista(struct Lista lista) {
    for (struct no *aux = lista.i; aux != NULL; aux = aux->prox) {
        printf("%d ", aux->dado);
    }
    printf("\n");
}

int lista_vazia(struct Lista lista) {
    if (lista.i == NULL && lista.f == NULL) return 1;
    return 0;
}

void free_lista(struct Lista *lista) {
    if (lista == NULL) return;
    for (struct no *atual = lista->i; atual != NULL; ) {
        struct no *aux = atual->prox;
        free(atual);
        atual = aux;
    }
    lista->i = NULL;
    lista->f = NULL;
}
