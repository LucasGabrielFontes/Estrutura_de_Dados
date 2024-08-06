#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define TAM 5

struct lista {
    int dados[TAM];
    int i;
    int f;
};

int menu();
int insere_inicio (struct lista * );
int insere_fim (struct lista * );
int decrementa_inicio (int  );
int incrementa_fim(int  );
int lista_cheia(struct lista  );
int lista_vazia(struct lista  );
void cria_lista(struct lista * );
void mostra_lista(struct lista  , char * );

int main() {

    struct lista lista_c;
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
                cria_lista(&lista_c); 
                strcpy(mensagem, "Lista criada com sucesso, baby!");
                system("cls");
                break;
            
            case 2: // Insere um elemento no inicio da lista
                if(insere_inicio(&lista_c)) { 
                    strcpy(mensagem, "Elemento inserido com sucesso!");
                } else {
                    strcpy(mensagem, "Memoria insuficiente!");
                }
                system("cls");
                break;

            case 3: // Insere um elemento no meio da lista
                if(insere_fim(&lista_c)) { 
                    strcpy(mensagem, "Elemento inserido com sucesso!");
                } else {
                    strcpy(mensagem, "Memoria insuficiente ou o indice inserido e invalido!");
                }
                system("cls");
                break;
            
            case 4: // Mostra todos os elementos da lista
                mostra_lista(lista_c, mensagem); 
                system("cls");
                break;

            default: // Usuario digitou uma opcao invalida
                printf("Escolha invalida! Tente novamente: ");
            break;
        }

    } while (escolha != 0);

    return 0;
}

int menu() {
    int escolha = 0;

    printf("\n\n=========== MENU ============\n\n");
    printf("0- Sair\n");
    printf("1- Criar lista\n");
    printf("2- Inserir elemento no inicio\n");
    printf("3- Inserir elemento no fim\n");
    printf("4- Mostrar lista\n\n");
    printf("Insira a sua escolha: ");
    scanf("%d", &escolha);

    return escolha;
}

int insere_inicio (struct lista *lista_c) {
    if (lista_cheia(*lista_c)) return 0;

    int num;
    printf("\nDigite o numero que sera inserido na lista: ");
    scanf("%d", &num);
    
    if (lista_vazia(*lista_c)) {
        lista_c->dados[(lista_c->i)+1] = num;
        lista_c->i++;
        lista_c->f++;
        return 1;
    }

    lista_c->dados[decrementa_inicio(lista_c->i)] = num;
    lista_c->i = decrementa_inicio(lista_c->i);
    return 1;
}

int insere_fim (struct lista *lista_c) {
    if (lista_cheia(*lista_c)) return 0;

    int num;
    printf("\nDigite o numero que sera inserido na lista: ");
    scanf("%d", &num);
    
    if (lista_vazia(*lista_c)) {
        lista_c->dados[lista_c->i+1] = num;
        lista_c->i++;
        lista_c->f++;
        return 1;
    }

    lista_c->dados[incrementa_fim(lista_c->f)] = num;
    lista_c->f = incrementa_fim(lista_c->f);
    return 1;
}

int decrementa_inicio (int inicio) {
    if (inicio-1 == -1) return TAM-1;
    return inicio-1;
}

int incrementa_fim(int fim) {
    if (fim+1 > TAM-1) return 0;
    return fim+1;
}

int lista_cheia(struct lista lista_c) {
    if (lista_c.i == incrementa_fim(lista_c.f)) return 1;
    return 0;
}

int lista_vazia(struct lista lista_c) {
    if (lista_c.i == -1 && lista_c.f == -1) return 1;
    return 0;
}

void cria_lista(struct lista *lista_c) {
    lista_c->i = -1;
    lista_c->f = -1;
}

void mostra_lista(struct lista lista_c, char *mensagem) {

    strcpy(mensagem, "Lista: "); // Mensagem armazera todos os elementos da lista como string
    char strNum[10];

    if (lista_vazia(lista_c)) return;

    if (lista_c.i == lista_c.f) {
        sprintf(strNum, "%d", lista_c.dados[lista_c.i]); // O dado do no e tranformado em uma string e armazenado em strNum
        strcat(mensagem, strNum); // O numero em formato de string e adicionado a mensagem
        strcat(mensagem, " ");
        return;
    }

    if (lista_c.f > lista_c.i) {
        for (int i = lista_c.i; i-1 != lista_c.f; i = incrementa_fim(i)) {
            sprintf(strNum, "%d", lista_c.dados[i]); // O dado do no e tranformado em uma string e armazenado em strNum
            strcat(mensagem, strNum); // O numero em formato de string e adicionado a mensagem
            strcat(mensagem, " ");
        }
        return;
    }

    int i = lista_c.i;
    do {
        sprintf(strNum, "%d", lista_c.dados[i]); // O dado do no e tranformado em uma string e armazenado em strNum
        strcat(mensagem, strNum); // O numero em formato de string e adicionado a mensagem
        strcat(mensagem, " ");
        i = incrementa_fim(i);
    } while(i-1 != lista_c.f);  
}