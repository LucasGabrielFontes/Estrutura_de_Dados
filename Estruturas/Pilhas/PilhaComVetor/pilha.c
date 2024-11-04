#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define TAM 5

struct stack_body{
    int data[TAM];
    int size;
};

int is_empty (struct stack_body * );
int is_full (struct stack_body * );
int menu();
struct stack_body* new_pilha();
int pop(struct stack_body * );
int push(struct stack_body * );
void top(struct stack_body * , char * );

int main() {

    struct stack_body *pilha;

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
                pilha = new_pilha();
                if (pilha != NULL) {
                    strcpy(mensagem, "Pilha criada com sucesso!");
                } else {
                    strcpy(mensagem, "Nao foi possivel criar a pilha!");
                }
                
                system("cls");
                break;

            case 2:
                if (push(pilha)) {
                    strcpy(mensagem, "Elemento inserido com sucesso!");
                } else {
                    strcpy(mensagem, "A pilha esta cheia!");
                }
                system("cls");
                break;

            case 3:
                if (pop(pilha)){
                    strcpy(mensagem, "Elemento removido com sucesso!");
                } else {
                    strcpy(mensagem, "A pilha esta vazia!");
                }
                system("cls");
                break;

            case 4:
                top(pilha, mensagem);
                system("cls");
                break;

        }

    } while (escolha != 0);

    free(pilha);

    return 0;
}

int menu() {
    int escolha = 0;

    printf("\n\n=========== MENU ============\n\n");
    printf("0- Sair\n");
    printf("1- Criar pilha\n");
    printf("2- Inserir elemento na pilha\n");
    printf("3- Retirar elemento da pilha\n");
    printf("4- Verificar topo da pilha\n\n");
    printf("Informe sua escolha: ");
    scanf("%d", &escolha);

    return escolha;
}

struct stack_body* new_pilha() {
    struct stack_body *pilha = (struct stack_body*) malloc (sizeof(struct stack_body));
    pilha->size = 0;
    return pilha;
}

int is_full (struct stack_body *pilha) {
    if (pilha->size == TAM) return 1;
    return 0;
}

int is_empty (struct stack_body *pilha) {
    if (pilha->size == 0) return 1;
    return 0;
}

int push(struct stack_body *pilha) {

    if (is_full(pilha)) return 0;

    int num;
    printf("Digite o valor que deseja inserir na pilha: ");
    scanf("%d", &num);

    pilha->data[pilha->size] = num;
    pilha->size++;
    return 1;

}

int pop(struct stack_body *pilha){
    if (is_empty(pilha)) return 0;

    pilha->size--;
    return 1;
}

void top(struct stack_body *pilha, char *mensagem){
    if (is_empty(pilha)) {
        strcpy(mensagem, "A pilha esta vazia!");
        return;
    } 

    char strNum[10];
    sprintf(strNum, "%d", pilha->data[pilha->size-1]);
    strcpy(mensagem ,"Topo da pilha: ");
    strcat(mensagem, strNum);
}