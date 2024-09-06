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

void concatena_listas(struct Lista * , struct Lista * );
int insere_fim(struct Lista * , int );
void libera_lista(struct Lista *);
int lista_vazia (struct Lista );
void mostra_lista_frente_para_tras(struct Lista );
void mostra_lista_tras_para_frente(struct Lista );
struct Lista new_lista();

int main(){

    struct Lista lista1 = new_lista();
    struct Lista lista2 = new_lista();

    insere_fim(&lista1, 1);
    insere_fim(&lista1, 2);
    insere_fim(&lista1, 3);
    insere_fim(&lista1, 4);
    insere_fim(&lista1, 5);

    insere_fim(&lista2, 6);
    insere_fim(&lista2, 7);
    insere_fim(&lista2, 8);
    insere_fim(&lista2, 9);
    insere_fim(&lista2, 10);

    printf("Lista 1: ");
    mostra_lista_frente_para_tras(lista1);
    printf("Lista 2: ");
    mostra_lista_frente_para_tras(lista2);

    printf("\nConcatenando...\n\n");

    concatena_listas(&lista1, &lista2);
    printf("Lista 1: ");
    mostra_lista_frente_para_tras(lista1);
    printf("Lista 2: ");
    mostra_lista_frente_para_tras(lista2);
    printf("Lista concatenada: ");
    mostra_lista_frente_para_tras(lista1);

    libera_lista(&lista1);
    libera_lista(&lista2);

    return 0;
}

struct Lista new_lista(){
    struct Lista lista;
    lista.i = NULL;
    lista.f = NULL;
    return lista;
}

void mostra_lista_frente_para_tras(struct Lista lista) {
    for (struct no *aux = lista.i; aux != NULL; aux = aux->prox) {
        printf("%d ", aux->dado);
    }
    printf("\n");
}

void mostra_lista_tras_para_frente(struct Lista lista){
    for (struct no *aux = lista.f; aux != NULL; aux = aux->ant) {
        printf("%d ", aux->dado);
    }
    printf("\n");
}

int insere_fim(struct Lista *lista, int num) {

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

    lista->f->prox = novo;
    novo->ant = lista->f;
    novo->prox = NULL;
    lista->f = novo;
    return 1;
}

void concatena_listas(struct Lista *lista1, struct Lista *lista2) {
    lista1->f->prox = lista2->i;
    lista2->i->ant = lista1->f;
    lista1->f = lista2->f;
    lista2->i = lista1->i;
}

void libera_lista (struct Lista *lista){
    if (lista == NULL) return;

    for (struct no *atual = lista->i; atual != NULL;) {
        struct no *aux = atual;
        atual = atual->prox;
        free(aux);
    }
    lista->i = NULL;
    lista->f = NULL;
}

int lista_vazia (struct Lista lista) {
    if (lista.i == NULL && lista.f == NULL) return 1;
    return 0;
}