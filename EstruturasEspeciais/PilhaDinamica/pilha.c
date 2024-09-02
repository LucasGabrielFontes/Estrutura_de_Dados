#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct no {
    int data;
    struct no *next;
};

struct stack {
    struct no *top;
};

void free_stack(struct stack * );
int is_empty(struct stack );
int menu();
struct stack new_stack();
int top(struct stack * );
int pop(struct stack * );
int push(struct stack * );

int main() {

    struct stack pilha;
    pilha = new_stack();

    int escolha; // Armazena a escolha do usuario
    char mensagem[100]= "Bem-vindo!"; // Essa variavel e sempre modificada para informar ao usuario o que esta acontecendo no momento com a lista

    do {

        printf("%s", mensagem); // Mostra a atualizacao ao usuario
        escolha = menu(); // Exibe o menu de opcoes
        // Trata cada uma das escolhas do usuario apresentadas no menu()

        switch (escolha){

            case 0: // Sai do programa
                break;

            case 1: 
                if (push(&pilha)) {
                    strcpy(mensagem, "Elemento inserido com sucesso!");
                } else {
                    strcpy(mensagem, "Memoria cheia!");
                }
                system("cls");
                break;

            case 2:
                if (pop(&pilha)) {
                    strcpy(mensagem, "Topo retirado com sucesso!");
                } else {
                    strcpy(mensagem, "Nao foi possivel retirar o topo");
                }
                system("cls");
                break;

            case 3:
                if (is_empty(pilha)) {
                    strcpy(mensagem, "A pilha esta vazia!");
                } else {
                    char strNum[10];
                    sprintf(strNum, "%d", top(&pilha));
                    strcpy(mensagem, "Topo da pilha: ");
                    strcat(mensagem, strNum);
                }
                system("cls");
                break;
                
        }

    } while (escolha != 0);

    free_stack(&pilha);

    return 0;
}

int menu() {
    int escolha = 0;

    printf("\n\n=========== MENU ============\n\n");
    printf("0- Sair\n");
    printf("1- Inserir elemento\n");
    printf("2- Remover o topo\n");
    printf("3- Verificar topo da pilha\n\n");
    printf("Insira a sua escolha: ");
    scanf("%d", &escolha);

    return escolha;
}

struct stack new_stack() {
    struct stack new;
    new.top = NULL;
    return new;
}

int is_empty(struct stack pilha){
    if (pilha.top == NULL) return 1;
    return 0;
}

int push(struct stack *pilha) {

    struct no *novo = (struct no *) malloc(sizeof(struct no));
    if (novo == NULL) return 0;

    int num; // Numero que sera inserido na lista
    printf("\nDigite o valor do elemento que sera inserido: ");
    scanf("%d", &num); 

    novo->data = num;

    if (is_empty(*pilha)){
        pilha->top = novo;
        novo->next = NULL;
        return 1;
    }

    novo->next = pilha->top;
    pilha->top = novo;
    return 1;
}

int pop(struct stack *pilha) {

    if (is_empty(*pilha)) return 0;

    struct no *aux = pilha->top;
    pilha->top = pilha->top->next;
    free(aux);
    return 1;

}

int top(struct stack *pilha) {
    return pilha->top->data;
}

void free_stack(struct stack *pilha){

    if (is_empty(*pilha)) return;

    struct no *aux = pilha->top;
    do {
        struct no *temp = aux;
        aux = aux->next;
        free(temp);
    } while (aux != NULL);

}