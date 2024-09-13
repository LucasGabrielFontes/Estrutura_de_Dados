#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct Fila {
    struct no *head;
    struct no *tail;
};

struct no {
    int dado;
    struct no *prox;
};

struct Fila cria_fila();
int esta_vazia(struct Fila );
void free_fila(struct Fila *);
int insere(struct Fila * );
int menu();
void mostra_fila(struct Fila , char *);
int retira(struct  Fila *);

int main() {

    struct Fila fila;
    fila = cria_fila();

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
                if (insere(&fila)) {
                    strcpy(mensagem, "Ultimo elemento inserido com sucesso!");
                } else {
                    strcpy(mensagem, "A fila esta cheia!");
                }
                system("cls");
                break;

            case 2:
                if (retira(&fila)) {
                    strcpy(mensagem, "Primeiro elemento removido com sucesso!");
                } else {
                    strcpy(mensagem, "Nao foi possivel remover o primeiro elemento!");
                }
                system("cls");
                break;

            case 3:
                mostra_fila(fila, mensagem);
                system("cls");
                break;
                
        }

    } while (escolha != 0);

    free_fila(&fila);

    return 0;
}

void mostra_fila(struct Fila fila, char *mensagem) { 

    strcpy(mensagem, "Lista: "); // Mensagem armazera todos os elementos da lista como string
    char strNum[10];

    for (struct no *aux = fila.head; aux != NULL; aux = aux->prox) {
        sprintf(strNum, "%d", aux->dado); // O dado do no e tranformado em uma string e armazenado em strNum
        strcat(mensagem, strNum); // O numero em formato de string e adicionado a mensagem
        strcat(mensagem, " "); // Um espaco tambem em adicionado para melhor visualizacao do usuario
    }
}

int menu() {
    int escolha = 0;

    printf("\n\n=========== MENU ============\n\n");
    printf("0- Sair\n");
    printf("1- Inserir elemento\n");
    printf("2- Retirar elemento\n");
    printf("3- 'Mostrar' fila\n\n");
    printf("Insira a sua escolha: ");
    scanf("%d", &escolha);

    return escolha;
}

struct Fila cria_fila() {
    struct Fila *fila = (struct Fila *) malloc(sizeof(struct Fila));
    fila->head = NULL;
    fila->tail = NULL;
    return *fila;
}

int esta_vazia (struct Fila fila) {
    if (fila.head == NULL && fila.tail == NULL) return 1;
    return 0;
}

int insere(struct Fila *fila) {

    struct no *novo = (struct no *) malloc (sizeof(struct no));

    if (novo == NULL) return 0;

    int num; // Numero que sera inserido na fila
    printf("\nDigite o valor do elemento que sera inserido: ");
    scanf("%d", &num); 

    novo->dado = num;
    novo->prox = NULL;

    if (esta_vazia(*fila)) {
        fila->head = novo;
        fila->tail = novo;
        return 1;
    }

    fila->tail->prox = novo;
    fila->tail = novo;
    return 1;

}

int retira (struct Fila *fila) {
    if (esta_vazia(*fila)) return 0;

    if (fila->head->prox == NULL) { // Fila com apenas um elemento
        struct no *aux = fila->head;
        fila->head = NULL;
        fila->tail = NULL;
        free(aux);
        return 1;
    }

    struct no *aux = fila->head;
    fila->head = fila->head->prox;
    free(aux);
    return 1;
}

void free_fila (struct Fila *fila) {
    for (struct no *aux = fila->head; aux != NULL; ) {
        struct no *atual = aux;
        aux = aux->prox;
        free(atual);
    }
    fila->head = NULL;
    fila->tail = NULL;
}