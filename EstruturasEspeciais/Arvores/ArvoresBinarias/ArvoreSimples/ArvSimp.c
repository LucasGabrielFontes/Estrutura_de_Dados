#include <stdio.h>
#include <stdlib.h>

struct no {
    struct no *esq;
    int info;
    struct no *dir;
};

int arvore_vazia(struct no *);
int calcula_altura(struct no *);
struct no * cria_arvore();
struct no * cria_no(int , struct no *, struct no *);
struct no* free_arvore(struct no *);
int max(int , int);
void mostra_arvore(struct no *);

int main() {

    struct no *arvore = cria_arvore();

    arvore = cria_no(1, NULL, NULL);
    arvore->esq = cria_no(2, NULL, NULL);
    arvore->esq->esq = cria_no(4, NULL, NULL);
    arvore->dir = cria_no(3, NULL, NULL);
    arvore->dir->esq = cria_no(5, NULL, NULL);
    arvore->dir->dir = cria_no(6, NULL, NULL);

    mostra_arvore(arvore);

    printf("\nAltura da arvore: %d\n", calcula_altura(arvore));

    arvore = free_arvore(arvore);

    return 0;
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

void mostra_arvore(struct no *arvore) {
    if (!arvore_vazia(arvore)) {
        printf("%d ", arvore->info);
        mostra_arvore(arvore->esq);
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