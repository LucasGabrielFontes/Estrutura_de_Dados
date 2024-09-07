#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define TAM 10001

struct no {
    struct no *next;
    char carac;
};

struct Pilha {
    struct no *top;
};

int esta_vazia(struct Pilha);
void free_pilha(struct Pilha *);
struct Pilha new_pilha();
void pop(struct Pilha *); 
void push(struct Pilha *, char);
void retira_enter(char *);
char top (struct Pilha *);

void mostra_pilha(struct Pilha *);

int main() {

    char entrada[TAM];
    fgets(entrada, TAM, stdin);
    retira_enter(entrada);
    
    struct Pilha pilha = new_pilha();

    int i = 0;
    for (; entrada[i] != '\0' && i < TAM; i++) {

        switch (entrada[i]){

            case '{':
                push(&pilha, '{');
                break;
            
            case '[':
                push(&pilha, '[');
                break;

            case '(':
                push(&pilha, '(');
                break;

            case '}':
                if (top(&pilha) == '{'){
                    pop(&pilha);
                } else {
                    printf("false\n");
                    i = TAM;
                }
                break;

            case ']':
                if (top(&pilha) == '['){
                    pop(&pilha);
                } else {
                    printf("false\n");
                    i = TAM;
                }
                break;

            case ')':
                if (top(&pilha) == '('){
                    pop(&pilha);
                } else {
                    printf("false\n");
                    i = TAM;
                }
                break;

        }

    }

    if (esta_vazia(pilha)) {
        printf("true\n");
    } else {
        printf("false\n");
    }

    free_pilha(&pilha);

}

char top (struct Pilha *pilha) {
    if (esta_vazia(*pilha)) return '\0';

    return (pilha->top->carac);
}

void pop(struct Pilha *pilha) {
    if (esta_vazia(*pilha)) return;
    struct no *aux = pilha->top;
    pilha->top = pilha->top->next;
    free(aux);
}

void push(struct Pilha *pilha, char carac) {

    struct no *novo = (struct no *) malloc(sizeof(struct no));
    if (novo == NULL) return;

    novo->carac = carac;

    if (esta_vazia(*pilha)) {
        novo->next = NULL;
        pilha->top = novo;
        return;
    }

    novo->next = pilha->top;
    pilha->top = novo;

}

int esta_vazia(struct Pilha pilha) {
    if (pilha.top == NULL) return 1;
    return 0;
}

void free_pilha(struct Pilha *pilha){

    if (pilha == NULL) return;

    struct no *aux = pilha->top;

    while (aux != NULL) {
        struct no *prox = aux->next;
        free(aux);
        aux = prox;
    }

    pilha->top = NULL;

}

struct Pilha new_pilha(){
    struct Pilha pilha;
    pilha.top = NULL;
    return pilha;
}

void retira_enter(char *string){
    unsigned int last = strlen(string)-1;
    if (string[last] == '\n')
        string[last] = '\0';
}