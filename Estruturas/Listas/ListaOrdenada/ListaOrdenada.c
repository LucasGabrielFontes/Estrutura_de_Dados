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
int exclui_lista(lista * );
int insere(lista * );
int limpa_lista(lista * );
int lista_cheia(lista );
int lista_vazia(lista );
int menu();
void mostra_lista(lista , char *);
int tira(lista *);

int main() {

    lista list;
    int escolha;
    char mensagem[50]= "Bem-vindo!";
    do {
        printf("%s", mensagem);
        // Trata cada uma das escolhas do usuario apresentadas no menu()
        switch (escolha = menu()){
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
                if(insere(&list)) {
                    strcpy(mensagem, "Elemento inserido com sucesso!");
                } else {
                    strcpy(mensagem, "A lista ja esta cheia!");
                }
                system("cls");
                break;

            case 3:
                if(tira(&list)) {
                    strcpy(mensagem, "Elemento removido com sucesso!");
                } else {
                    strcpy(mensagem, "A lista ja esta vazia ou o elemento nao foi encontrado na lista!");
                }
                system("cls");
                break;

            case 4:
                if(esvazia_lista(&list)) {
                    strcpy(mensagem, "Lista esvaziada com sucesso!");
                } else {
                    strcpy(mensagem, "Nao foi possivel esvaziar a lista!");
                }
                system("cls");
                break;

            case 5:
                if(exclui_lista(&list)) {
                    strcpy(mensagem, "Lista exluida com sucesso!");
                } else {
                    strcpy(mensagem, "Nao foi possivel excluir a lista!");
                }
                system("cls");
                break;
            
            case 6:
                mostra_lista(list, mensagem);
                system("cls");
                break;

            default:
                strcpy(mensagem, "Escolha invalida! Tente novamente:");
                system("cls");
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
    printf("2- Inserir elemento\n");
    printf("3- Remover elemento\n");
    printf("4- Esvaziar lista\n");
    printf("5- Excluir lista\n");
    printf("6- Mostrar lista\n\n");
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
int insere(lista *list) {
    
    if (lista_cheia(*list)) {
        return 0;
    }

    int n;
    printf("\nDigite o elemento que sera adicionado na lista: ");
    scanf("%d", &n);

    if (list->cont == -1) {
        list->dados[0] = n;
        list->cont++;

        return 1;
    } 

    if (n > list->dados[list->cont]) {
        list->dados[list->cont+1] = n; 
        list->cont++;

        return 1;
    }

    for (int i = 0; i <= list->cont; i++) {
        if (n <= list->dados[i]) {
            for (int aux = list->cont+1; aux > i; aux--) {
                list->dados[aux] = list->dados[aux-1];
            }

            list->dados[i] = n;
            list->cont++;
            break;
        }
    }

    return 1;
}

// Remove o utlimo elemento da lista, caso nao esteja vazia
int tira(lista *list) {

    if(lista_vazia(*list)) {
        return 0;
    }

    int num;
    printf("\nDigite o numero que voce deseja retirar da lista: ");
    scanf("%d", &num);

    for (int i = 0; i < list->cont; i++) {
        if (list->dados[i] == num) {
            for (int aux = i; aux < list->cont; aux++) {
                list->dados[aux] = list->dados[aux+1];
            }
            list->cont--;
            return 1;
        }
    }

    return 0;
}

// Modifica a lista para ficar vazia
int esvazia_lista(lista *list){
    list->cont = -1;

    return 1;
}

// Exclui a lista, dando um free no vetor que foi alocado dinamicamente no momento de sua criacao
int exclui_lista(lista *list) {
    list->cont = -1;
    free(list->dados);

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