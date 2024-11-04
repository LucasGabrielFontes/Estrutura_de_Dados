#include "funcoes_arvore.c"
#include "no.h"
#include <stdio.h>

int main() {

    struct no *arvore = cria_arvore();

    arvore = insere(arvore, 1);
    arvore = insere(arvore, 2);
    arvore = insere(arvore, 3);
    arvore = insere(arvore, 4);
    arvore = insere(arvore, 5);

    mostra_arvore_pre(arvore);

    cria_arquivo_dot(arvore);

    arvore = free_arvore(arvore);

    return 0;
}