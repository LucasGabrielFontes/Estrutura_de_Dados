#include <stdio.h>
#include <stdlib.h>

struct no {
    struct no *esq;
    int info;
    struct no *dir;
};

int arvore_vazia(struct no *);
struct no* busca (struct no *arvore, int num);
int calcula_altura(struct no *);
struct no * cria_arvore();
struct no * cria_no(int , struct no *, struct no *);
struct no* free_arvore(struct no *);
struct no* insere (struct no *, int );
int max(int , int);
void mostra_arvore(struct no *);

int main() {

    struct no *arvore = cria_arvore();

    arvore = insere(arvore, 6);
    arvore = insere(arvore, 5);
    arvore = insere(arvore, 3);
    arvore = insere(arvore, 7);
    arvore = insere(arvore, 4);

    mostra_arvore(arvore);

    arvore = free_arvore(arvore);

    return 0;
}

struct no* insere (struct no *arvore, int num) { // Insere ordenadamente na arvore

    if (arvore_vazia(arvore)) {
        struct no *novo = (struct no *) malloc (sizeof(struct no));
        if (novo == NULL) return NULL;
        novo->info = num;
        novo->esq = NULL;
        novo->dir = NULL;
        return novo;
    }

    if (num < arvore->info) {
        arvore->esq = insere(arvore->esq, num);
    } else {
        arvore->dir = insere(arvore->dir, num);
    }

    return arvore;
}

struct no* busca (struct no *arvore, int num) {

    if (arvore == NULL) return NULL;

    if (num < arvore->info) {
        return busca(arvore->esq, num);
    } else if (num > arvore->info) {
        return busca(arvore->dir, num);
    } else {
        return arvore;
    }
}

int calcula_altura(struct no *arvore) {
    if (arvore_vazia(arvore)) {
        return -1;
    } else {
        return (1 + max(calcula_altura(arvore->esq), calcula_altura(arvore->dir)));
    }
}

int max(int a, int b) {
    return (a > b) ? a : b;
}

struct no* free_arvore(struct no *arvore) {
    if (!arvore_vazia(arvore)) {
        arvore->esq = free_arvore(arvore->esq);
        arvore->dir = free_arvore(arvore->dir);
        free(arvore);
    }
    return NULL;
}

void mostra_arvore(struct no *arvore) { // Percorre simetricamente
    if (!arvore_vazia(arvore)) {
        mostra_arvore(arvore->esq);
        printf("%d ", arvore->info);
        mostra_arvore(arvore->dir);
    }
}

struct no *cria_arvore() {
    return NULL;
}

struct no *cria_no(int info, struct no *esq, struct no *dir) {

    struct no *novo = (struct no *) malloc(sizeof(struct no));
    if (novo == NULL) return NULL;

    novo->info = info;
    novo->esq = esq;
    novo->dir = dir;

    return novo;
}

int arvore_vazia(struct no *arvore) {
    if (arvore == NULL) return 1;
    return 0;
}