#include <stdio.h>
#include <stdlib.h>

#define N 3

struct lista{
    int dados[N];
    int contr;
};

void cria_lista(struct lista *);
void esvazia_lista(struct lista *);
void insere_elem(struct lista *);
int lista_cheia(struct lista);
int lista_vazia(struct lista);
void menu();
void mostra_lista(struct lista);
void ordena_lista(struct lista *);
void remove_elem(struct lista *);

int main() {

    int resp = 1;

    struct lista list;

    while (resp != 0) {

        menu();
        scanf("%d", &resp);
        printf("\n");

        switch (resp) {
            case 1:
                cria_lista(&list);
                break;

            case 2:
                esvazia_lista(&list);
                break;

            case 3:
                insere_elem(&list);
                break;

            case 4:
                remove_elem(&list);
                break;

            case 5:
                mostra_lista(list);
                break;

            case 6: 
                ordena_lista(&list);
                break;
            
            default:
                break;
        }

    }

}

void menu() {

    printf("\n\n===================================");
    printf("       Estudo de listas em C       ");
    printf("===================================\n\n");
    printf("Escolha uma das opcoes:\n\n");
    printf("1- Criar lista\n");
    printf("2- Esvaziar lista\n");
    printf("3- Inserir elemento\n");
    printf("4- Remover elemento\n");
    printf("5- Mostrar lista\n");
    printf("6- Ordenar lista\n");
    printf("0- Sair\n\n");
    printf("Escolha: ");

}

void cria_lista(struct lista *list){
    list->contr = -1; // Inicializa a lista totalmente vazia
    printf("Lista criada.\n");
}

void esvazia_lista(struct lista *list){
    list->contr = -1; // A lista e esvaziada
    printf("Lista esvaziada.\n");
}

int lista_cheia(struct lista list) {

    if (list.contr == N-1) { // Significa que toda a lista esta totalmente preenchida
        return 1;
    }

    return 0;

}

void insere_elem(struct lista *list){

    if (lista_cheia(*list)) { // Verifica se a lista ja esta cheia
        printf("Lista cheia!\n");
        return;
    }

    printf("Digite o numero que sera adicionado a lista: ");
    scanf("%d", &list->dados[list->contr +1]); // Adiciona o elemento ao final da lista
    list->contr = list->contr + 1; // Incrementa a variavel controladora
    printf("Elemento adicionado!\n");

}

int lista_vazia(struct lista list) {

    if (list.contr == -1) { // Significa que a lista esta totalmente vazia
        return 1;
    }

    return 0;

}

void remove_elem(struct lista *list) {

    if (lista_vazia(*list)){
        printf("Lista vazia!\n");
        return;
    }

    list->contr = list->contr - 1; // Decrementa a variavel controladora
    // Retirada do ultimo elemento a ser implementada
    printf("Elemento removido!\n");

}

void mostra_lista(struct lista list) {

    // Percorre por toda a lista - delimitada pela variavel controladora - e imprime seus elementos
    for (int i = 0; i <= list.contr; i++){
        printf("%d ", list.dados[i]);
    }

}

void ordena_lista(struct lista *list) {

    // Percorre todos os elementos da lista - delimitada pela variavel controladora - e os ordena
    for (int i = 0; i <= list->contr; i++) {
        for (int j = i+1; j <= list->contr; j++) {

            if (list->dados[i] > list->dados[j]) {
                int temp = list->dados[i];
                list->dados[i] = list->dados[j];
                list->dados[j] = temp;
            }

        }
    }

    printf("Lista ordenada!\n");

}
