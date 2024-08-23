#include <stdio.h>
#include <stdlib.h>
#include <string.h>

////////////////////////// Structs ////////////////////////////////

struct listaDE{ // Lista duplamente encadeada: ponteiros para o início e para o fim da lista
    struct no *i;
    struct no *f;
};

struct no{ // No de uma lista duplamente encadeada: ponteiro para o elemento anterior, espaco para o dado e ponteiro para o elemento posterior
    struct no *ant;
    int dado;
    struct no *prox;
};

///////////////////////////// Prototipos //////////////////////////////////
void cria_lista(struct listaDE * );
void esvazia_lista(struct listaDE * );
int insere(struct listaDE * );
int lista_vazia(struct listaDE );
int menu();
void mostra_lista_PU(struct listaDE , char * );
void mostra_lista_UP(struct listaDE, char *);
int removeE(struct listaDE * );

int main() {

    struct listaDE lista;

    int escolha; // Armazena a escolha do usuario
    char mensagem[100]= "Bem-vindo!"; // Essa variavel e sempre modificada para informar ao usuario o que esta acontecendo no momento com a lista

    do {
        printf("%s", mensagem); // Mostra a atualizacao ao usuario
        escolha = menu(); // Exibe o menu de opcoes
        // Trata cada uma das escolhas do usuario apresentadas no menu()
        switch (escolha){
            case 0: // Sai do programa
                break;

            case 1: // Cria a lista
                cria_lista(&lista); 
                if(lista.i == NULL && lista.f == NULL) {
                    strcpy(mensagem, "Lista criada com sucesso, baby!");
                } else {
                    strcpy(mensagem, "Nao foi possivel criar a lista!");
                }
                system("cls");
                break;

            case 2:
                if(insere(&lista)) {
                    strcpy(mensagem, "Elemento inserido com sucesso!");
                } else {
                    strcpy(mensagem, "Indice invalido ou memoria cheia!");
                }
                system("cls");
                break;

            case 3:
                if(removeE(&lista)) {
                    strcpy(mensagem, "Elemento removido com sucesso!");
                } else {
                    strcpy(mensagem, "A lista ja esta vazia ou o valor digitado e invalido!");
                }
                system("cls");
                break;

            case 4:
                mostra_lista_PU(lista, mensagem);
                system("cls");
                break;

            case 5:
                mostra_lista_UP(lista, mensagem);
                system("cls");
                break;
        }

    } while (escolha != 0);

    esvazia_lista(&lista);

    return 0;
}

int menu() {
    int escolha = 0;

    printf("\n\n=========== MENU ============\n\n");
    printf("0- Sair\n");
    printf("1- Criar lista\n");
    printf("2- Adicionar elemento\n");
    printf("3- Remover elemento\n");
    printf("4- Mostrar lista do primeiro para o ultimo elemento\n");
    printf("5- Mostrar lista do ultimo para o primeiro elemento\n\n");
    printf("Insira a sua escolha: ");
    scanf("%d", &escolha);

    return escolha;
}

void mostra_lista_PU(struct listaDE lista, char *mensagem){

    strcpy(mensagem, "Lista: "); // Mensagem armazera todos os elementos da lista como string
    char strNum[10];

    for (struct no *atual = lista.i; atual != NULL; atual = atual->prox) {
        sprintf(strNum, "%d", atual->dado); // O dado do no e tranformado em uma string e armazenado em strNum
        strcat(mensagem, strNum); // O numero em formato de string e adicionado a mensagem
        strcat(mensagem, " "); // Um espaco tambem em adicionado para melhor visualizacao do usuario
    }
}

void mostra_lista_UP(struct listaDE lista, char *mensagem){

    strcpy(mensagem, "Lista: ");
    char strNum[10];

    for (struct no *atual = lista.f; atual != NULL; atual = atual->ant) {
        sprintf(strNum, "%d", atual->dado);
        strcat(mensagem, strNum);
        strcat(mensagem, " ");
    }
}

void cria_lista(struct listaDE *lista){
    lista->i = NULL;
    lista->f = NULL;
}

int lista_vazia(struct listaDE lista){
    if (lista.i == NULL && lista.f == NULL) {
        return 1;
    }
    return 0;
}

int insere(struct listaDE *lista){

    struct no *novo = (struct no *) malloc (sizeof(struct no));
    if (novo == NULL) return 0; 

    int num; // Numero que sera inserido na lista
    printf("\nDigite o valor do elemento que sera inserido: ");
    scanf("%d", &num);

    novo->dado = num;

    if (lista_vazia(*lista)) {
        novo->ant = NULL;
        novo->prox = NULL;

        lista->i = novo;
        lista->f = novo;

        return 1;
    }

    for (struct no *atual = lista->i; atual != NULL; atual = atual->prox) {
        if (novo->dado <= atual->dado) {
            novo->prox = atual;
            novo->ant = atual->ant;
            if (atual->ant == NULL){
                lista->i = novo;
            } else {
                atual->ant->prox = novo;
            }
            atual->ant = novo;
            return 1;
        }
    }

    // Se chegar aqui, ele e o maio elemento da lista e sera inserido no final
    novo->prox = lista->f->prox;
    novo->ant = lista->f;
    lista->f->prox = novo;
    lista->f = novo;
    return 1;
}

int removeE(struct listaDE *lista) {

    if (lista_vazia(*lista)) return 0;

    int num; // Numero que sera inserido na lista
    printf("\nDigite o valor do elemento que sera removido: ");
    scanf("%d", &num);

    if (lista->i == lista->f) { // So tem um elemento
        if (lista->i->dado == num) {
            struct no *aux = lista->i;
            lista->i = NULL;
            lista->f = NULL;
            free(aux);
            return 1;
        }
        return 0;
    }

    for (struct no *atual = lista->i; atual != NULL; atual = atual->prox) {
        if (atual->dado == num) {
            if (atual->ant == NULL) {
                lista->i = lista->i->prox;
                lista->i->ant = NULL;
            } else if (atual->prox == NULL) {
                lista->f = lista->f->ant;
                lista->f->prox = NULL;
            } else {
                atual->ant->prox = atual->prox;
                atual->prox->ant = atual->ant;
            }
            free(atual);
            return 1;
        }
    }
    return 0;
}

void esvazia_lista(struct listaDE *lista){

    struct no *aux = lista->i;
    while (aux != NULL) {
        struct no *temp = aux;
        aux = aux->prox;
        free(temp);
    }

    lista->i = NULL;
    lista->f = NULL;
}