#include <stdio.h>
#include <stdlib.h>

struct no {
    struct no *esq;
    int info;
    struct no *dir;
};

int arvore_vazia(struct no *);
int calcula_altura(struct no *);
void cria_arquivo_dot(struct no *);
struct no * cria_arvore();
struct no * cria_no(int , struct no *, struct no *);
int fator_balanceamento(struct no *);
struct no* free_arvore(struct no *);
void gera_dot (struct no *, FILE *);
struct no* insere (struct no *, int );
int max(int , int);
void mostra_arvore_in(struct no *);
void mostra_arvore_pre(struct no *);
void mostra_arvore_pos(struct no *);
struct no* rotacao_a_esquerda(struct no *);
struct no* rotacao_a_direita(struct no *);

int main() {

    struct no *arvore = cria_arvore();

    arvore = insere(arvore, 6);
    arvore = insere(arvore, 5);
    arvore = insere(arvore, 3);
    arvore = insere(arvore, 7);
    arvore = insere(arvore, 4);
    arvore = insere(arvore, 2);

    cria_arquivo_dot(arvore);

    arvore = free_arvore(arvore);

    return 0;
}

// Ao gerar o arquivo .dot, rode no terminal: dot -Tpng NOMEDOARQUIVO.dot -o NOMEDOARQUIVO.png
void cria_arquivo_dot(struct no *raiz) {

    FILE *file = fopen("arvore.dot", "w");
    if (file == NULL) {
        printf("Erro ao criar o arquivo!");
        return;
    }

    fprintf(file, "digraph G {\n");
    gera_dot(raiz, file);
    fprintf(file, "}\n");

    fclose(file);

}

void gera_dot (struct no *raiz, FILE *file) {

    if (!arvore_vazia(raiz)) {

        if (raiz->esq != NULL) {
            fprintf(file, "    %d -> %d;\n", raiz->info, raiz->esq->info);
            gera_dot(raiz->esq, file);
        }

        if (raiz->dir != NULL) {
            fprintf(file, "    %d -> %d;\n", raiz->info, raiz->dir->info);
            gera_dot(raiz->dir, file);
        } 

    }

}

struct no* insere (struct no *raiz, int num) { // Insere ordenadamente na arvore

    if (arvore_vazia(raiz)) {
        struct no *novo = (struct no *) malloc (sizeof(struct no));
        if (novo == NULL) return NULL;
        novo->info = num;
        novo->esq = NULL;
        novo->dir = NULL;
        return novo;
    }

    if (num < raiz->info) {
        raiz->esq = insere(raiz->esq, num);
    } else {
        raiz->dir = insere(raiz->dir, num);
    }

    int balanceamento = fator_balanceamento(raiz);

    if (balanceamento > 1) {
        return rotacao_a_direita(raiz);
    } 

    if (balanceamento < -1) {
        return rotacao_a_esquerda(raiz);
    }

    return raiz;
}

struct no* rotacao_a_esquerda(struct no *raiz) {

    struct no *no;

    no = raiz->dir;
    raiz->dir = no->esq;
    no->esq = raiz;
    raiz = no;
    return raiz;

}

struct no* rotacao_a_direita(struct no *raiz) {

    struct no *no;

    no = raiz->esq;
    raiz->esq = no->dir;
    no->dir = raiz;
    raiz = no;
    return raiz;

}

int fator_balanceamento(struct no *raiz) {

    if (!arvore_vazia(raiz)) {
        return calcula_altura(raiz->esq) - calcula_altura(raiz->dir);
    } else {
        return 0;
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

struct no *cria_arvore() {
    return NULL;
}

int arvore_vazia(struct no *arvore) {
    if (arvore == NULL) return 1;
    return 0;
}