// Autor: Lucas Gabriel Fontes da Silva
// Proposito: praticar estruturas de listas

///////////////////////////////////////////// IMPORTACOES /////////////////////////////////////////////////////

#include <stdio.h> 
#include <string.h>
#include <stdlib.h>

//////////////////////////////////////////// STRUCTS //////////////////////////////////////////////////////////

struct no {
    struct no *ant;
    int dado;
    struct no *prox;
};

struct listaDEOC {
    struct no *i; // A lista sera percorrida ate voltar para o inicio
};

//////////////////////////////////////////// PROTOTIPOS ///////////////////////////////////////////////////////

void cria_lista(struct listaDEOC * );                 // Cria a lista. Tornano ponteiro de inicio igual a NULL
void esvazia_lista(struct listaDEOC * );              // Libera toda a memoria alocada da lista
int lista_vazia(struct listaDEOC );                   // Informa se a lista esta vazia
int menu();                                           // Menu de opcoes para o usuario
void mostra_listaPU(struct listaDEOC , char * );      // Mostra a lista do primeiro ao ultimo elemento
int insere(struct listaDEOC * );                      // Insere um elemento mantendo a lista ordenada
int removeE(struct listaDEOC * );                     // Remove um elemento - pelo valor

//////////////////////////////////////////// MAIN ////////////////////////////////////////////////////////////

int main(){
    struct listaDEOC lista;

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
                if(lista.i == NULL)
                    strcpy(mensagem, "Lista criada com sucesso, baby!");
                else 
                    strcpy(mensagem, "Nao foi possivel criar a lista!");
                system("cls");
                break;

            case 2: // Insere um elemento na lista
                if (insere(&lista)) 
                    strcpy(mensagem, "Elemento inserido com sucesso!");
                else 
                    strcpy(mensagem, "Memoria cheia!");
                system("cls");
                break;

            case 3: // Remove um elemento da lista
                if (removeE(&lista))
                    strcpy(mensagem, "Elemento removido com sucesso!");
                else 
                    strcpy(mensagem, "A lista esta vazia ou o elemento nao foi encontrado!");
                system("cls");
                break;

            case 4: // Mostra a lista do primeiro para o ultimo elemento
                mostra_listaPU(lista, mensagem);
                system("cls");
                break;

        }

    } while (escolha != 0);

    esvazia_lista(&lista);

    return 0;
}

//////////////////////////////////////////////// FUNCOES ////////////////////////////////////////////////////////

int menu() {
    int escolha = 0;

    printf("\n\n=========== MENU ============\n\n");
    printf("0- Sair\n");
    printf("1- Criar lista\n");
    printf("2- Inserir elemento\n");
    printf("3- Remover elemento\n");
    printf("4- Mostrar lista\n\n");
    printf("Insira a sua escolha: ");
    scanf("%d", &escolha);

    return escolha;
}

void cria_lista(struct listaDEOC *lista) {
    lista->i = NULL;
}

int lista_vazia(struct listaDEOC lista) {
    if (lista.i == NULL) return 1;
    return 0;
}

void mostra_listaPU(struct listaDEOC lista, char *mensagem){

    strcpy(mensagem, "Lista: ");
    char strNum[10];
    if (lista_vazia(lista)) return;

    struct no *atual = lista.i;

    do {
        sprintf(strNum, "%d", atual->dado);
        strcat(mensagem, strNum);
        strcat(mensagem, " ");

        atual = atual->prox;
    } while (atual != lista.i);

}

int insere(struct listaDEOC *lista) {

    struct no *novo = (struct no *) malloc(sizeof(struct no));
    if (novo == NULL) return 0;

    int num; // Numero que sera inserido na lista
    printf("\nDigite o valor do elemento que sera inserido: ");
    scanf("%d", &num); 

    novo->dado = num;

    if (lista_vazia(*lista)) {
        lista->i = novo;
        novo->prox = novo;
        novo->ant = novo;
        return 1;
    }

    struct no *atual = lista->i;
    do {
        if (novo->dado <= atual->dado) { // novo deve ser inserido antes do no atual
            novo->prox = atual;
            novo->ant = atual->ant;
            if (atual == lista->i) {  // O inicio da lista precisa ser modificado
                lista->i = novo;
                if (atual->prox == atual) { // A lista só tinha um elemento: o fim da lista precisa ser modificado
                    atual->prox = novo;
                }
            } 
            novo->ant->prox = novo;
            atual->ant = novo;
            return 1;
        }

        atual = atual->prox;
    } while (atual != lista->i);

    atual = atual->ant; // Se chegou ate aqui, o elemento sera inserido no final da lista
    novo->ant = atual;
    novo->prox = lista->i;
    lista->i->ant = novo;
    atual->prox = novo;
    return 1;
}

int removeE(struct listaDEOC *lista){

    if (lista_vazia(*lista)) return 0;

    int num; // Numero que sera inserido na lista
    printf("\nDigite o valor do elemento que sera removido: ");
    scanf("%d", &num); 

    struct no *atual = lista->i;

    do {

        if (atual->dado == num) { // No que sera removido foi encontrado

            if (atual->prox == atual) {
                lista->i = NULL;
                free(atual);
                return 1;
            } 

            if (lista->i == atual) {
                lista->i = atual->prox;
                lista->i->ant = atual->ant;
                atual->ant->prox = lista->i;
                free(atual);
                return 1;
            }

            atual->prox->ant = atual->ant;
            atual->ant->prox = atual->prox;
            free(atual);
            return 1;

        }

        atual = atual->prox;
    } while (atual != lista->i);

    return 0;

}

void esvazia_lista(struct listaDEOC *lista) {

    if (lista_vazia(*lista)) return;

    struct no *atual = lista->i;
    do {
        struct no *temp = atual;
        atual = atual->prox;
        free(temp);
    } while (atual != lista->i);

    lista->i = NULL;

}