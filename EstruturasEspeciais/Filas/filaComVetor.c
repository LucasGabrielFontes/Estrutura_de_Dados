#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define TAM 5

struct Fila {
    int i;
    int elementos;
    int dados[TAM];
};

struct Fila cria_fila();
int esta_cheia(struct Fila fila);
int esta_vazia(struct Fila fila);
int insere(struct Fila *fila);
int menu();
void mostra_fila(struct Fila fila, char *mensagem);
int retira(struct Fila *fila);

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

    return 0;
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

void mostra_fila(struct Fila fila, char *mensagem) {

    strcpy(mensagem, "Lista: ");
    char strNum[10];

    if (esta_vazia(fila)) return;

    int i = fila.i;
    int cont = 0;
    while (cont != fila.elementos) {
        sprintf(strNum, "%d", fila.dados[i]);
        strcat(mensagem, strNum);
        strcat(mensagem, " ");
        cont++;
        i = (i+1)%TAM;
    }
}

int esta_vazia(struct Fila fila) {
    if (fila.elementos == 0) return 1;
    return 0; 
}

int esta_cheia(struct Fila fila) {
    if (fila.elementos == TAM) return 1;
    return 0;
}

struct Fila cria_fila() {
    struct Fila *fila = (struct Fila *) malloc(sizeof(struct Fila));
    fila->i = 0;
    fila->elementos = 0;
    return *fila;
}

int insere(struct Fila *fila) {
    if (esta_cheia(*fila)) return 0;

    int num; // Numero que sera inserido na fila
    printf("\nDigite o valor do elemento que sera inserido: ");
    scanf("%d", &num); 

    fila->dados[((fila->i)+(fila->elementos))%TAM] = num;
    fila->elementos++;
    return 1;
}

int retira(struct Fila *fila) {
    if (esta_vazia(*fila)) return 0;

    fila->i = (fila->i + 1)%TAM;
    fila->elementos--;
    return 1;
}
