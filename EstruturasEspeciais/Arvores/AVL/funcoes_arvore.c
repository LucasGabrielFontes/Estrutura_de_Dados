#include "funcoes_arvore.h"
#include "no.h"
#include <stdio.h>
#include <stdlib.h>

int arvore_vazia(struct no *arvore) {
    if (arvore == NULL) return 1;
    return 0;
}

struct no* balanceia(struct no *raiz, int FB) {

    if (FB > 1) { // Eh necessario fazer uma rotacao a direita na raiz

        int FB_filho = fator_balanceamento(raiz->esq);

        if (FB_filho < 0) { // Sinais diferentes. Nesse caso: rotacao a esquerda em raiz->esq e depois rotacao a direita na raiz
            raiz->esq = rotacao_a_esquerda(raiz->esq);
            return rotacao_a_direita(raiz);
        } else { // Apenas uma rotacao simples a direita na raiz
            return rotacao_a_direita(raiz);
        }

    } else if (FB < -1) { // Eh necessario fazer uma rotacao a esquerda na raiz

        int FB_filho = fator_balanceamento(raiz->dir);

        if (FB_filho >= 0) { // Sinais diferentes. Nesse caso: rotacao a direita em raiz->dir e depois rotacao a esquerda em na raiz
            raiz->dir = rotacao_a_direita(raiz->dir);
            return rotacao_a_esquerda(raiz);
        } else { // Apenas uma rotacao simples a esquerda na raiz
            return rotacao_a_esquerda(raiz);
        }
    }
    return raiz;
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

struct no *cria_arvore() {
    return NULL;
}

int fator_balanceamento(struct no *raiz) {
    if (!arvore_vazia(raiz)) {
        return calcula_altura(raiz->esq) - calcula_altura(raiz->dir);
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

    if (abs(balanceamento) > 1) {
        raiz = balanceia(raiz, balanceamento);
    }
    return raiz;
}

void mostra_arvore_in(struct no *raiz) { // Percorre simetricamente
    if (!arvore_vazia(raiz)) {
        mostra_arvore_in(raiz->esq);
        printf("%d ", raiz->info);
        mostra_arvore_in(raiz->dir);
    }
}

void mostra_arvore_pos(struct no *raiz) { // Percorre simetricamente
    if (!arvore_vazia(raiz)) {
        mostra_arvore_pos(raiz->esq);
        mostra_arvore_pos(raiz->dir);
        printf("%d ", raiz->info);
    }
}

void mostra_arvore_pre(struct no *raiz) { // Percorre simetricamente
    if (!arvore_vazia(raiz)) {
        printf("%d ", raiz->info);
        mostra_arvore_pre(raiz->esq);
        mostra_arvore_pre(raiz->dir);
    }
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
