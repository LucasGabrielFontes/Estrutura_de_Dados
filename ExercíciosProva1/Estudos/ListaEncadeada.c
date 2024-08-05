// Implementacao das principais funcoes aplicadas em uma lista encadeada
// Autor: Lucas Gabriel Fontes da Silva

// Bibliotecas
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Struct que define a lista
struct corpo{
    int dado; // Campo para armazenar informacao
    struct corpo *prox; // Ponteiro para o proximo elemento do tipo struct no
};

// Definicao de um tipo: no
typedef struct corpo no;

no* cria_lista(); // Retorna NULL que sera o "primeiro" elemento da lista
int esvazia_lista(no **); // Libera a memoria alocada dinamicamente de toda a lista
int insere_inicio(no ** ); // Insere um elemento no inicio da lista
int insere_meio(no ** ); // Insere um elemento em qualquer posicao valida da lista: inclusive acrescentar um elemento ao final da lista
int lista_vazia (no * ); // Verifica se a lista esta vazia
int menu(); // Mostra o menu de opcoes para o usuario
void mostra_lista(no * , char * ); // Mostra todos os elementos da lista
int ordena_lista(no ** ); // Ordena a lista em ordem crescente
int retira_elem(no ** ); // Retira um elemento da lista pelo seu indice
no* tem(no *); // Verifica se um determinado elemento pertence a lista

int main() {

    no *lista; // A lista propriamente dita e representada por um ponteiro para um struct 'no' que 
    // aponta para o primeiro elemento

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
                lista = cria_lista(); 
                if(lista == NULL) {
                    strcpy(mensagem, "Lista criada com sucesso, baby!");
                } else {
                    strcpy(mensagem, "Nao foi possivel criar a lista!");
                }
                system("cls");
                break;
            
            case 2: // Insere um elemento no inicio da lista
                if(insere_inicio(&lista)) { 
                    strcpy(mensagem, "Elemento inserido com sucesso!");
                } else {
                    strcpy(mensagem, "Memoria insuficiente!");
                }
                system("cls");
                break;

            case 3: // Insere um elemento no meio da lista
                if(insere_meio(&lista)) { 
                    strcpy(mensagem, "Elemento inserido com sucesso!");
                } else {
                    strcpy(mensagem, "Memoria insuficiente ou o indice inserido e invalido!");
                }
                system("cls");
                break;

            case 4: // Retira um elemento pelo indice
                if(retira_elem(&lista)) { 
                    strcpy(mensagem, "Elemento removido com sucesso!");
                } else {
                    strcpy(mensagem, "A lista ja esta vazia ou o indice e invalido!");
                }
                system("cls");
                break;
            
            case 5: // Mostra todos os elementos da lista
                mostra_lista(lista, mensagem); 
                system("cls");
                break;

            case 6: // Ordena a lista em ordem crescente
                if(ordena_lista(&lista)) {
                    strcpy(mensagem, "Lista ordenada com sucesso!");
                } else {
                    strcpy(mensagem, "Nao foi possivel ordenar a lista!");
                }
                system("cls");
                break;
                
            case 7: // Verifica o pertencimento de um elemento na lista
                if(tem(lista)) {
                    strcpy(mensagem, "O elemento pertence a lista!");
                } else {
                    strcpy(mensagem, "O elemento nao pertence a lista, ou a lista esta vazia!");
                }
                system("cls");
                break;

            case 8: // Esvazia a lista
                if (esvazia_lista(&lista)) {
                    strcpy(mensagem, "Lista esvaziada com sucesso!");
                } else {
                    strcpy(mensagem, "Nao foi possivel esvaziar a lista!");
                }
                system("cls");
                break;

            default: // Usuario digitou uma opcao invalida
                printf("Escolha invalida! Tente novamente: ");
            break;
        }

    } while (escolha != 0);

    esvazia_lista(&lista); // Garante que toda a memoria alocada dinamicamente durante a execucao do codigo seja liberada antes do termino do programa

    return 0;
}

int menu() {
    int escolha = 0;

    printf("\n\n=========== MENU ============\n\n");
    printf("0- Sair\n");
    printf("1- Criar lista\n");
    printf("2- Inserir elemento no inicio\n");
    printf("3- Inserir elemento no meio\n");
    printf("4- Remover elemento\n");
    printf("5- Mostrar lista\n");
    printf("6- Ordenar lista\n");
    printf("7- Verificar pertencimento de elemento na lista\n");
    printf("8- Esvaziar lista\n\n");
    printf("Insira a sua escolha: ");
    scanf("%d", &escolha);

    return escolha;
}

// Cria uma lista encadeada vazia
no* cria_lista() {
    return NULL;
}

int insere_inicio(no **pont_lista) { // Recebe um ponteiro de um ponteiro de struct 'no'

    int num; // Numero que sera inserido na lista
    printf("\nDigite o valor do elemento que sera inserido: ");
    scanf("%d", &num);

    no *novo = (no *) malloc(sizeof(no)); // 1- Cria a celula

    if (novo == NULL) return 0;

    novo->dado = num; // 2- Preenche a celula
    novo->prox = *pont_lista; // 3- Conecta a celula 'a lista
    *pont_lista = novo; // 4- Altera a lista; novo é o novo primeiro elemento da lista
    return 1;
}

int insere_meio(no **pont_lista) {

    int num; // Valor que sera adicionado na lista
    int ind; // Indice que indica a posicao que o elemento ocupara na lista (se for valido)
    no *novo = (no *) malloc(sizeof(no)); // Novo no que sera devidamente preenchido e adicionado 'a lista

    if (novo == NULL) return 0; // Memoria cheia

    printf("\nDigite o VALOR a ser inserido na lista: "); 
    scanf("%d", &num);
    printf("\nDigite o INDICE que o valor sera inserido: ");
    scanf("%d", &ind);

    novo->dado = num; // Preenchimento da nova celula
    int cont = -1; // Variavel auxiliar que armazena o indice atual do elemento da lista

    if (ind == 0) { // O valor sera inserido no inicio da lista
        no *temp = *pont_lista; // No temporario para armazenar o primeiro elemento atual
        *pont_lista = novo; // 'novo' e agora o novo primeiro elemento da lista
        novo->prox = temp; // O antigo primeiro elemento se torna o segundo
        return 1;
    } 

    for (no *lista = *pont_lista; lista != NULL; lista = lista->prox) {
        cont++; // Indice atual e atualizado
        if (cont+1 == ind) { // Proximo elemento tera sua posicao alterada
            novo->prox = lista->prox; // Novo toma o lugar do elemento do indice escolhido
            lista->prox = novo; // Alteracao para a lista ser de fato modificada
            return 1;
        }
    } 

    return 0;
}

void mostra_lista(no *pont_lista, char *mensagem) {

    strcpy(mensagem, "Lista: "); // Mensagem armazera todos os elementos da lista como string
    char strNum[10];

    no *aux = pont_lista; // Variavel auxiliar para percerrer a lista

    while (aux != NULL) { // Enquanto nao chegar ao final, mostra os elementos da lista
        sprintf(strNum, "%d", aux->dado); // O dado do no e tranformado em uma string e armazenado em strNum
        strcat(mensagem, strNum); // O numero em formato de string e adicionado a mensagem
        strcat(mensagem, " "); // Um espaco tambem em adicionado para melhor visualizacao do usuario
        aux = aux->prox; // O ponteiro para o proximo elemento e atualizado
    }
}

int lista_vazia (no *pont_lista) { // Recebe uma copia do que a lista esta apontando (primeiro elemento dele)
    if (pont_lista == NULL) return 1; // Lista vazia

    return 0; // Lista nao vazia
}

no* tem(no *pont_lista) {

    int elem; // Elemento que sera testado se pertence ou nao a lista
    printf("\nDigite o valor que voce deseja testar se esta na lista: ");
    scanf("%d", &elem);

    no *aux = pont_lista; // Variavel auxiliar para percorrer a lista

    while (aux != NULL) {
        if (aux->dado == elem) { // Elemento encontrado
            return aux; // Retorna o endereco do elemento encontrado na lista; já que aux e um ponteiro, ele contem um endereco
        }
        aux = aux->prox; // Aux e atualizado para o proximo elemento da lista
    }

    return NULL; // Elemento nao encontrado. Ponteiro nulo e retornado
}

int retira_elem(no **pont_lista) {

    if (lista_vazia(*pont_lista)) return 0; // Se a lista esta vazia, nao ha o que retirar

    int elem; // Elemento que sera retirado da lista, caso pertenca a ela
    printf("\nDigite o valor que sera removido da lista: ");
    scanf("%d", &elem);

    if ((*pont_lista)->dado == elem) { // Situacao onde o primeiro elemento da lista sera removido
        no *aux = *pont_lista; // no auxiliar para guardar o endereco do elemento, a fim de liberar a memoria depois
        *pont_lista = (*pont_lista)->prox; // O elemento e retirado da lista
        free(aux); // Memoria liberada
        return 1;
    } 
    
    no *atual = *pont_lista; // Variavel auxiliar para percorrer a lista
    while (atual != NULL) {
        if ((atual->prox != NULL) && (atual->prox)->dado == elem) { // O proximo elemento sera removido
            no *aux = atual->prox; // no auxiliar para guardar o endereco do elemento, a fim de liberar a memoria depois
            atual->prox = (atual->prox)->prox; // O elemento e retirado da lista
            free(aux); // Memoria liberada
            return 1;
        }
        atual = atual->prox;
    }

    return 0;
}

int ordena_lista(no **pont_lista) {

    // Utiliza o metodo bubble sort para ordenar a lista
    for (no *lista1 = *pont_lista; lista1 != NULL; lista1 = lista1->prox) {
        for (no *lista2 = lista1->prox; lista2 != NULL; lista2 = lista2->prox) {
            if (lista1->dado > lista2->dado) {
                int temp = lista1->dado;
                lista1->dado = lista2->dado;
                lista2->dado = temp;
            }
        }
    } 

    return 1;
}

int esvazia_lista(no **pont_lista){

    while (*pont_lista != NULL) {
        no *aux = *pont_lista; // No auxiliar para o proximo elemento nao ser perdido
        *pont_lista = (*pont_lista)->prox; // Proximo elemento atualizado
        free(aux); // Memoria liberada
    }

    return 1;
}