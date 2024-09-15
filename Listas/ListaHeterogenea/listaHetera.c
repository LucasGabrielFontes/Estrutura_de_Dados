#include <stdio.h>
#include <stdlib.h>
#include <math.h>

#define TRI 1
#define RET 2
#define CIR 3

#define PI 3.14159

struct no {
    int tipo;
    void *info;
    struct no *prox;
};

struct triangulo {
    float base;
    float altura;
};

struct retangulo {
    float base;
    float altura;
};

struct circulo {
    float raio;
};

float calcula_area (struct no * );
struct no* cria_cir (float raio);
struct no* cria_ret (float , float );
struct no* cria_tri (float , float );
void libera_lista(struct no *lista);

int main() {

    struct no *lista = cria_tri(5, 5);

    lista->prox = cria_ret(10, 10);

    lista->prox->prox = cria_cir(4);

    printf("Area do triangulo: %.2f\n", calcula_area(lista));
    printf("Area do retangulo: %.2f\n", calcula_area(lista->prox));
    printf("Area do circulo: %.2f\n", calcula_area(lista->prox->prox));

    libera_lista(lista);

    return 0;
}

void libera_lista(struct no *lista) {

    struct no *aux = lista;
    while (aux != NULL) {
        struct no *atual = aux->prox;

        free(aux->info);
        free(aux);

        aux = atual;
    }

    lista = NULL;
}

float calcula_area (struct no *estrutura) {

    float area = 0.0;
    struct triangulo *tri;
    struct retangulo *ret;
    struct circulo *cir;

    switch (estrutura->tipo) {
        case TRI:
            tri = (struct triangulo *) estrutura->info;
            area = (tri->base*tri->altura)/2;
            break;

        case RET:
            ret = (struct retangulo *) estrutura->info;
            area = ret->base*ret->altura;
            break;

        case CIR:
            cir = (struct circulo *) estrutura->info;
            area = (PI*pow(cir->raio, 2));
            break;
    }

    return area;
}

struct no* cria_tri (float base, float altura) {

    struct no *novo = (struct no*) malloc(sizeof(struct no));
    novo->tipo = TRI;

    struct triangulo *tri = (struct triangulo *) malloc(sizeof(struct triangulo));
    tri->base = base;
    tri->altura = altura;

    novo->info = tri;
    novo->prox = NULL;
    return novo;

}

struct no* cria_ret (float base, float altura) {
    struct no *novo = (struct no*) malloc(sizeof(struct no)); // Aloca memoria para o novo no da lista
    novo->tipo = RET; // Preenche o campo tipo do novo no, informando que apontara para uma estrutura do tipo retangulo

    struct retangulo *ret = (struct retangulo *) malloc(sizeof(struct retangulo)); // Aloca memoria para o retangulo, que sera apontado pelo novo no
    ret->base = base; // Preenche o campo da base do retangulo
    ret->altura = altura; // Preenche o campo da altura do triangulo

    novo->prox = NULL; // O novo no sera inserido no fim da lista. Assim, seu proximo elemento e NULL
    novo->info = ret; // Preenche o campo de informacao do no: aponta para o retangulo
    return novo;
}

struct no* cria_cir (float raio) {

    struct no *novo = (struct no*) malloc(sizeof(struct no));
    novo->tipo = CIR;

    struct circulo *cir = (struct circulo*) malloc(sizeof(struct circulo));
    cir->raio = raio;

    novo->info = cir;
    novo->prox = NULL;
    return novo;

}