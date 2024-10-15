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
int conta_nos(struct no *);
struct no * cria_arvore();
struct no * cria_no(int , struct no *, struct no *);
struct no* free_arvore(struct no *);
struct no* insere (struct no *, int );
int max(int , int);
void mostra_arvore_in(struct no *);
void mostra_arvore_pre(struct no *);
void mostra_arvore_pos(struct no *);

int main() {

    struct no *arvore = cria_arvore();

    arvore = insere(arvore, 15);
    arvore = insere(arvore, 22);
    arvore = insere(arvore, 12);
    arvore = insere(arvore, 14);
    arvore = insere(arvore, 17);
    arvore = insere(arvore, 10);
    arvore = insere(arvore, 24);
    arvore = insere(arvore, 19);
    arvore = insere(arvore, 21);
    arvore = insere(arvore, 11);
    arvore = insere(arvore, 18);
    arvore = insere(arvore, 16);

    printf("Arvore infix: ");
    mostra_arvore_in(arvore);
    printf("\n");

    printf("Arvore prefix: ");
    mostra_arvore_pre(arvore);
    printf("\n");

    printf("Arvore posfix: ");
    mostra_arvore_pos(arvore);
    printf("\n");

    printf("\nAltura da arvore: %d\n", calcula_altura(arvore));
    printf("\nQuantidade de nos da arvore: %d\n", conta_nos(arvore));

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
    
    if (!arvore_vazia(arvore)) {
        
        int altura_esq = calcula_altura(arvore->esq);
        int altura_dir = calcula_altura(arvore->dir);
        int maior_altura = altura_esq >= altura_dir ? altura_esq : altura_dir;

        return 1 + maior_altura;

    } else {
        return 0;
    }

}

int conta_nos (struct no *raiz) {

    if (!arvore_vazia(raiz)) {

        int a = conta_nos(raiz->esq);
        int b = conta_nos(raiz->dir);
        return a + b + 1;

    } else {
        return 0;
    }

}

struct no* free_arvore(struct no *arvore) {
    if (!arvore_vazia(arvore)) {
        arvore->esq = free_arvore(arvore->esq);
        arvore->dir = free_arvore(arvore->dir);
        free(arvore);
    }
    return NULL;
}

void mostra_arvore_in(struct no *raiz) { // Percorre simetricamente
    if (!arvore_vazia(raiz)) {
        mostra_arvore_in(raiz->esq);
        printf("%d ", raiz->info);
        mostra_arvore_in(raiz->dir);
    }
}

void mostra_arvore_pre (struct no* raiz) {
    if (!arvore_vazia(raiz)) {
        printf("%d ", raiz->info);
        mostra_arvore_pre(raiz->esq);
        mostra_arvore_pre(raiz->dir);
    }
}

void mostra_arvore_pos (struct no *raiz) {
    if (!arvore_vazia(raiz)) {
        mostra_arvore_pos(raiz->esq);
        mostra_arvore_pos(raiz->dir);
        printf("%d ", raiz->info);
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