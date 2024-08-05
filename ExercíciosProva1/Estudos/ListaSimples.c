// Implementacao de todas as funcoes de lista simples com vetor trabalhadas em sala 
// na disciplina de Estrutura de Dados

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct{
    int *dados;
    int cont;
} lista;

#define TAM 5

int cria_lista(lista * );
int esvazia_lista(lista * );
int excluir_lista(lista * );
int insere_fim(lista * );
int insere_inicio(lista * );
int insere_meio(lista * );
int limpa_lista(lista * );
int lista_cheia(lista );
int lista_vazia(lista );
int menu();
void mostra_lista(lista , char *);
int ordena_lista(lista *);
int remove_fim(lista * );
int remove_inicio(lista * );
int remove_meio(lista * );

int main() {

    lista list;
    int escolha;
    char mensagem[50]= "Bem-vindo!";
    do {
        printf("%s", mensagem);
        escolha = menu();
        // Trata cada uma das escolhas do usuario apresentadas no menu()
        switch (escolha){
            case 0:
                break;

            case 1:
                if(cria_lista(&list)) {
                    strcpy(mensagem, "Lista criada com sucesso, baby!");
                } else {
                    strcpy(mensagem, "Nao foi possivel criar a lista!");
                }
                system("cls");
                break;
            
            case 2:
                if(insere_fim(&list)) {
                    strcpy(mensagem, "Elemento inserido com sucesso!");
                } else {
                    strcpy(mensagem, "A lista ja esta cheia!");
                }
                system("cls");
                break;

            case 3:
                if(insere_inicio(&list)) {
                    strcpy(mensagem, "Elemento inserido com sucesso!");
                } else {
                    strcpy(mensagem, "A lista ja esta cheia!");
                }
                system("cls");
                break;

            case 4:
                if(insere_meio(&list)) {
                    strcpy(mensagem, "Elemento inserido com sucesso!");
                } else {
                    strcpy(mensagem, "A lista ja esta cheia!");
                }
                system("cls");
                break;

            case 5:
                if(remove_fim(&list)) {
                    strcpy(mensagem, "Elemento removido com sucesso!");
                } else {
                    strcpy(mensagem, "A lista ja esta vazia!");
                }
                system("cls");
                break;

            case 6:
                if(remove_inicio(&list)) {
                    strcpy(mensagem, "Elemento removido com sucesso!");
                } else {
                    strcpy(mensagem, "A lista ja esta vazia!");
                }
                system("cls");
                break;

            case 7:
                if(remove_meio(&list)) {
                    strcpy(mensagem, "Elemento removido com sucesso!");
                } else {
                    strcpy(mensagem, "A lista ja esta vazia!");
                }
                system("cls");
                break;

            case 8:
                if(esvazia_lista(&list)) {
                    strcpy(mensagem, "Lista esvaziada com sucesso!");
                } else {
                    strcpy(mensagem, "Nao foi possivel esvaziar a lista!");
                }
                system("cls");
                break;

            case 9:
                if(excluir_lista(&list)) {
                    strcpy(mensagem, "Lista exluida com sucesso!");
                } else {
                    strcpy(mensagem, "Nao foi possivel excluir a lista!");
                }
                system("cls");
                break;

            case 10:
                if(ordena_lista(&list)) {
                    strcpy(mensagem, "Lista ordenada com sucesso!");
                } else {
                    strcpy(mensagem, "Nao foi possivel ordenar a lista!");
                }
                system("cls");
                break;
            
            case 11:
                mostra_lista(list, mensagem);
                system("cls");
                break;

            default:
                printf("Escolha invalida! Tente novamente: ");
            break;
        }

    } while (escolha != 0);

    free(list.dados);

    return 0;
}

// Mostra todas as escolhas disponiveis para o usuario
int menu() {
    int escolha = 0;

    printf("\n\n=========== MENU ============\n\n");
    printf("0- Sair\n");
    printf("1- Criar lista\n");
    printf("2- Inserir elemento no fim\n");
    printf("3- Inserir elemento no inicio\n");
    printf("4- Inserir elemento no meio\n");
    printf("5- Remover elemento no fim\n");
    printf("6- Remover elemento no inicio\n");
    printf("7- Remover elemento no meio\n");
    printf("8- Esvaziar lista\n");
    printf("9- Excluir lista\n");
    printf("10- Ordenar lista\n");
    printf("11- Mostrar lista\n\n");
    printf("Insira a sua escolha: ");
    scanf("%d", &escolha);

    return escolha;
}

// Verifica se a lista esta cheia
int lista_cheia(lista list){
    if (list.cont == TAM-1) return 1;

    return 0;
}

int lista_vazia(lista list) {
    if (list.cont == -1) return 1;

    return 0;
}

// Insere um elemento no final da lista, se houve espaco
int insere_fim(lista *list) {
    
    if (lista_cheia(*list)) {
        return 0;
    }

    int n;
    printf("\nDigite o elemento que sera adicionado na lista: ");
    scanf("%d", &n);

    // O valor e inserido na ultima posicao e a lista e alterada
    list->dados[list->cont+1] = n;
    list->cont = list->cont+1;

    return 1;
}

// Insere um elemento no inicio da lista, se houver espaco
int insere_inicio(lista *list) {

    if (lista_cheia(*list)) {
        return 0;
    }

    int n;
    printf("\nDigite o elemento que sera adicionado na lista: ");
    scanf("%d", &n);

    // "Empurra" todos os elementos para o lado direito, a fim de comportar o elemento no inicio
    for (int i = list->cont+1; i > 0; i--) {
        list->dados[i] = list->dados[i-1];
    }
     
    // Adiciona o elemento no indice 0
    list->dados[0] = n;

    // Modifica a lista
    list->cont = list->cont+1;

    return 1;
}

// Insere algum elemento no meio da lista, informado pelo usuario
int insere_meio(lista *list) {

    if (lista_cheia(*list)) {
        return 0;
    }

    int n;
    printf("\nDigite o elemento que sera adicionado na lista: ");
    scanf("%d", &n);

    int i;
    printf("\nDigite o indice da posicao que voce deseja inserir o valor: ");
    scanf("%d", &i);
    if (i < 0 || i > list->cont) {
        printf("\nIndice invalido");
        return 0;
    }

    // Todos o elementos a partir da posicao que o novo sera inserido sao realocados uma casa para a direita
    for (int aux = list->cont+1; aux > i; aux--){
        list->dados[aux] = list->dados[aux-1];
    }

    // O vetor recebe o valor no local desejado
    list->dados[i] = n;

    // A lista e modificada
    list->cont = list->cont + 1;

    return 1;
}

// Remove o utlimo elemento da lista, caso nao esteja vazia
int remove_fim(lista *list) {

    if(lista_vazia(*list)) {
        return 0;
    }

    // Altera a lista
    list->cont = list->cont - 1;
    return 1;
}

// Remove o primeiro elemento da lista, caso nao esteja vazia
int remove_inicio(lista *list) {

    if (lista_vazia(*list)) {
        return 0;
    }

    // Realoca todos os valores para a esquerda, sobrepondo o primeiro
    for (int i = 0; i < list->cont; i++) {
        list->dados[i] = list->dados[i+1];
    }

    // Modifica a lista
    list->cont = list->cont - 1;

    return 1;
}

// Remove algum elemento do meio da lista, informado pelo usuario
int remove_meio(lista *list) {

    if (lista_vazia(*list)){
        return 0;
    }

    int i;
    printf("\nDigite o indice da posicao do elemento que sera retirado: ");
    scanf("%d", &i);
    while (i < 0 || i > list->cont) {
        printf("\nIndice invalido! Tente novamente: ");
        scanf("%d", &i);
    }

    // Realoca todos os elementos a esquerda do valor escolhido, sobrepondo-o
    for (int aux = i; aux < list->cont; aux++) {
        list->dados[aux] = list->dados[aux+1];
    }

    // Modifica a lista
    list->cont = list->cont - 1;

    return 1;
}

// Modifica a lista para ficar vazia
int esvazia_lista(lista *list){
    list->cont = -1;

    return 1;
}

// Exclui a lista, dando um free no vetor que foi alocado dinamicamente no momento de sua criacao
int excluir_lista(lista *list) {
    list->cont = -1;
    free(list->dados);

    return 1;
}

// Ordena todos os elementos da lista em ordem crescente, caso nao esteja vazia
int ordena_lista(lista *list) {

    if (lista_vazia(*list)) {
        return 0;
    }

    // Bubble sort
    for (int i = 0; i <= list->cont; i++) {
        for (int j = i+1; j <= list->cont; j++) {
            if (list->dados[i] > list->dados[j]) {
                int temp = list->dados[i];
                list->dados[i] = list->dados[j];
                list->dados[j] = temp;
            }
        }
    }

    return 1;
}

// Mostra a lista para o usuario
void mostra_lista(lista list, char *mensagem) {
    strcpy(mensagem, "Lista: ");
    char strNum[10];
    for (int i = 0; i <= list.cont; i++) {
        sprintf(strNum, "%d", list.dados[i]);
        strcat(mensagem, strNum);
        strcat(mensagem, " ");
    }
}

// Cria a lista vazia utilizando alocacao dinamica
int cria_lista(lista *list){

    list->dados = (int *) malloc(TAM*sizeof(int)); // Cria o vetor dinamicamente
    if (list->dados == NULL){
        return 0;
    }
    list->cont = -1; // Inicia a lista vazia

    return 1;
}