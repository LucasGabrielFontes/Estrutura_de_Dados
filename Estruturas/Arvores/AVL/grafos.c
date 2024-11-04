#include <stdio.h>

struct no_adj{
    char nome;
    float peso;
    struct no_adj *prox_adj;
};

struct no{
    char nome;
    struct no *prox;
    struct no_adj *prox_adj;
};

int main(){

    struct no *lista_adj;

    struct no no1;
    no1.nome = 'A';

    lista_adj = &no1;

    return 0;
}