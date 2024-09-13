#ifndef FILA_H
#define FILA_H

struct no {
    struct no *ant;
    int dado;
    struct no *prox;
};

struct Fila {
    struct no *ext1;
    struct no *ext2;
};

struct Fila *cria_fila();
int fila_vazia(struct Fila );
void insere_fim(struct Fila *, int );
void insere_inicio(struct Fila *, int );
void libera_fila(struct Fila *);
void mostra_fila(struct Fila );
void retira_fim(struct Fila *);
void retira_inicio(struct Fila *);

#endif