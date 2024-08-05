#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct corpo{
    int dado; // Campo para armazenar informacao
    struct corpo *prox; // Ponteiro para o proximo elemento do tipo struct no
};

typedef struct corpo no;

no* cria_lista();
int esvazia_lista(no **);
int insere_inicio(no ** );
int lista_vazia (no *);
int menu();
void mostra_lista(no * , char * );
int retira_elem(no ** );
no* tem(no *);

int main() {

    no *lista; // A lista propriamente dita e representada por um ponteiro para um struct no que 
    // aponta para o primeiro elemento

    int escolha;
    char mensagem[100]= "Bem-vindo!";

    do {
        printf("%s", mensagem);
        escolha = menu();
        // Trata cada uma das escolhas do usuario apresentadas no menu()
        switch (escolha){
            case 0:
                break;

            case 1:
                lista = cria_lista();
                if(lista == NULL) {
                    strcpy(mensagem, "Lista criada com sucesso, baby!");
                } else {
                    strcpy(mensagem, "Nao foi possivel criar a lista!");
                }
                system("cls");
                break;
            
            case 2:
                if(insere_inicio(&lista)) {
                    strcpy(mensagem, "Elemento inserido com sucesso!");
                } else {
                    strcpy(mensagem, "Memoria insuficiente!");
                }
                system("cls");
                break;

            case 3:
                if(retira_elem(&lista)) {
                    strcpy(mensagem, "Elemento removido com sucesso!");
                } else {
                    strcpy(mensagem, "A lista ja esta vazia!");
                }
                system("cls");
                break;
            
            case 4:
                mostra_lista(lista, mensagem);
                system("cls");
                break;

            case 5:
                if(tem(lista)) {
                    strcpy(mensagem, "O elemento pertence a lista!");
                } else {
                    strcpy(mensagem, "O elemento nao pertence a lista, ou a lista esta vazia!");
                }
                system("cls");
                break;

            case 6:
                if (esvazia_lista(&lista)) {
                    strcpy(mensagem, "Lista esvaziada com sucesso!");
                } else {
                    strcpy(mensagem, "Nao foi possivel esvaziar a lista!");
                }
                system("cls");
                break;

            default:
                printf("Escolha invalida! Tente novamente: ");
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
    printf("2- Inserir elemento no inicio\n");
    printf("3- Remover elemento\n");
    printf("4- Mostrar lista\n");
    printf("5- Verificar pertencimento de elemento na lista\n");
    printf("6- Esvaziar lista\n\n");
    printf("Insira a sua escolha: ");
    scanf("%d", &escolha);

    return escolha;
}

// Funcao para criacao de uma lista encadeade vazia
no* cria_lista() {
    return NULL;
}

int insere_inicio(no **pont_lista) { // Recebe um ponteiro de um ponteiro de struct no

    int num;
    printf("\nDigite o valor do elemento que sera inserido: ");
    scanf("%d", &num);

    no *novo = (no *) malloc(sizeof(no)); // 1- Cria a celula

    if (novo == NULL) return 0;

    novo->dado = num; // 2- Preenche a celula
    novo->prox = *pont_lista; // 3- Conecta a celula 'a lista
    *pont_lista = novo; // 4- Altera a lista; novo é o novo primeiro elemento da lista
    return 1;
}

void mostra_lista(no *pont_lista, char *mensagem) {

    strcpy(mensagem, "Lista: ");
    char strNum[10];

    // Variavel auxiliar para percerrer a lista
    no *aux = pont_lista;

    // Enquanto nao chegar ao final, mostra os elementos da lista
    while (aux != NULL) {
        sprintf(strNum, "%d", aux->dado);
        strcat(mensagem, strNum);
        strcat(mensagem, " ");
        aux = aux->prox; // O ponteiro para o proximo elemento e atualizado
    }
}

int lista_vazia (no *pont_lista) { // Recebe uma copia do que a lista esta apontando (primeiro elemento dele)
    if (pont_lista == NULL) return 1; 

    return 0;
}

no* tem(no *pont_lista) {

    int elem;
    printf("\nDigite o valor que voce deseja testar se esta na lista: ");
    scanf("%d", &elem);

    no *aux = pont_lista;

    while (aux != NULL) {
        if (aux->dado == elem) {
            return aux;
        }
        aux = aux->prox;
    }

    return NULL;
}

int retira_elem(no **pont_lista) {

    if (lista_vazia(*pont_lista)) return 0; 

    int elem;
    printf("\nDigite o valor que sera removido da lista: ");
    scanf("%d", &elem);

    if ((*pont_lista)->dado == elem) {
        no *aux = *pont_lista;
        *pont_lista = (*pont_lista)->prox;
        free(aux);
        return 1;
    } 
    
    no *atual = *pont_lista;
    while (atual != NULL) {
        if ((atual->prox != NULL) && (atual->prox)->dado == elem) {
            no *aux = atual->prox;
            atual->prox = (atual->prox)->prox;
            free(aux);
            return 1;
        }
        atual = atual->prox;
    }

    return 0;
}

int esvazia_lista(no **pont_lista){

    while (*pont_lista != NULL) {
        no *aux = *pont_lista;
        *pont_lista = (*pont_lista)->prox;
        free(aux);
    }

    return 1;

}