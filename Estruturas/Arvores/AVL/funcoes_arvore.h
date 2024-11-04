#include "no.h"
#include <stdio.h>

#ifndef FUNCOES_ARVORE_H
#define FUNCOES_ARVORE_H

int arvore_vazia(struct no *);
struct no* balanceia(struct no *, int);
struct no* busca (struct no *, int);
int calcula_altura(struct no *);
int conta_nos(struct no *);
void cria_arquivo_dot(struct no *);
struct no * cria_arvore();
int fator_balanceamento(struct no *);
struct no* free_arvore(struct no *);
void gera_dot (struct no *, FILE *);
struct no* insere (struct no *, int);
void mostra_arvore_in(struct no *);
void mostra_arvore_pos(struct no *);
void mostra_arvore_pre(struct no *);
struct no* rotacao_a_esquerda(struct no *);
struct no* rotacao_a_direita(struct no *);

#endif