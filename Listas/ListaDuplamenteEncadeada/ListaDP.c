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
int insere_fim(struct listaDE * );
int insere_inicio(struct listaDE * );
int insere_meio(struct listaDE * );
int lista_vazia(struct listaDE );
int menu();
void mostra_lista_PU(struct listaDE , char * );
void mostra_lista_UP(struct listaDE, char *);
int remove_fim(struct listaDE *);
int remove_inicio(struct listaDE *);
int remove_meio(struct listaDE *);

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
                if (insere_inicio(&lista)){
                   strcpy(mensagem, "Elemento inserido com sucesso!");
                } else {
                    strcpy(mensagem, "Nao foi possivel inserir o elemento na lista!");
                }
                system("cls");
                break;

            case 3:
                if(insere_fim(&lista)) {
                    strcpy(mensagem, "Elemento inserido com sucesso!");
                } else {
                    strcpy(mensagem, "Nao foi possivel inserir o elemento na lista!");
                }
                system("cls");
                break;

            case 4:
                if(insere_meio(&lista)) {
                    strcpy(mensagem, "Elemento inserido com sucesso!");
                } else {
                    strcpy(mensagem, "Indice invalido ou memoria cheia!");
                }
                system("cls");
                break;

            case 5:
                if(remove_inicio(&lista)) {
                    strcpy(mensagem, "Elemento removido com sucesso!");
                } else {
                    strcpy(mensagem, "Lista vazia!");
                }
                system("cls");
                break;

            case 6:
                if(remove_fim(&lista)) {
                    strcpy(mensagem, "Elemento removido com sucesso!");
                } else {
                    strcpy(mensagem, "Lista vazia!");
                }
                system("cls");
                break;

            case 7:
                if(remove_meio(&lista)) {
                    strcpy(mensagem, "Elemento removido com sucesso!");
                } else {
                    strcpy(mensagem, "Lista vazia ou indice invalido!");
                }
                system("cls");
                break;

            case 8:
                mostra_lista_PU(lista, mensagem);
                system("cls");
                break;

            case 9:
                mostra_lista_UP(lista, mensagem);
                system("cls");
                break;
        }

    } while (escolha != 0);

    // Esvaziar lista

    return 0;
}

int menu() {
    int escolha = 0;

    printf("\n\n=========== MENU ============\n\n");
    printf("0- Sair\n");
    printf("1- Criar lista\n");
    printf("2- Adicionar elemento no inicio\n");
    printf("3- Adicionar elemento no final\n");
    printf("4- Adicionar elemento no meio\n");
    printf("5- Remover elemento do inicio\n");
    printf("6- Remover elemento do fim\n");
    printf("7- Remover elemento do meio\n");
    printf("8- Mostrar lista do primeiro para o ultimo elemento\n");
    printf("9- Mostrar lista do ultimo para o primeiro elemento\n\n");
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

int insere_fim(struct listaDE *lista){

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

    novo->ant = lista->f;
    novo->prox = NULL;
    lista->f->prox = novo;
    lista->f = novo;

    return 1;
}

int insere_inicio(struct listaDE *lista){

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

    novo->prox = lista->i;
    novo->ant = NULL;
    lista->i->ant = novo;
    lista->i = novo;

    return 1;
}

int insere_meio(struct listaDE *lista){

    struct no *novo = (struct no *) malloc(sizeof(struct no)); // Novo no que sera devidamente preenchido e adicionado 'a lista
    if (novo == NULL) return 0; // Memoria cheia

    int num; // Valor que sera adicionado na lista
    int ind; // Indice que indica a posicao que o elemento ocupara na lista (se for valido)

    printf("\nDigite o INDICE (contando do inicio para o fim) que o valor sera inserido: ");
    scanf("%d", &ind);
    printf("\nDigite o VALOR que sera inserido na lista: ");
    scanf("%d", &num);

    novo->dado = num;

    if (ind == 0) return 0;

    int i = -1;
    struct no *aux = lista->i;
    while(aux != NULL){
        i++;
        if (i == ind) {

            novo->ant = aux->ant;
            novo->prox = aux;
            aux->ant->prox = novo;
            aux->ant = novo;
            return 1;
        }
        aux = aux->prox;
    }

    return 0;
}

int remove_inicio(struct listaDE *lista){

    if(lista_vazia(*lista)) return 0;

    struct no *aux = lista->i;

    if (lista->i->prox == NULL) {
        lista->i = NULL;
        lista->f = NULL;
        free(aux);
        return 1;
    }

    lista->i->prox->ant = NULL;
    lista->i = lista->i->prox;
    free(aux);
    return 1;
}

int remove_fim(struct listaDE *lista){

    if (lista_vazia(*lista)) return 0;

    struct no *aux = lista->f;

    if (lista->i->prox == NULL) {
        lista->i = NULL;
        lista->f = NULL;
        free(aux);
        return 1;
    }

    lista->f->ant->prox = NULL;
    lista->f = lista->f->ant;
    free(aux);
    return 1;
}

int remove_meio(struct listaDE *lista) {

    if (lista_vazia(*lista)) return 0;

    int ind; // Indice que indica a posicao que o elemento ocupara na lista (se for valido)

    printf("\nDigite o indice (contando do inicio para o fim) do valor que sera removido: ");
    scanf("%d", &ind);
    
    if (ind == 0) return 0;

    struct no *atual = lista->i;
    for (int i = 0; atual->prox != NULL; i++) { // Nao permite remover no inicio e nem no fim

        if (i == ind) {
            atual->ant->prox = atual->prox;
            atual->prox->ant = atual->ant;
            free(atual);
            return 1;
        }

        atual = atual->prox;
    } 

    return 0;
}