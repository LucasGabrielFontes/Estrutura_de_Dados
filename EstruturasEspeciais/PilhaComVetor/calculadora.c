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
int push(struct stack_body * , int );
int tamString(char *);
int top(struct stack_body * );

int main() {

    struct stack_body *pilha;
    pilha = new_pilha();

    if (pilha == NULL) return 1;

    char expressao[100];
    printf("Digite a expressao: ");
    fgets(expressao, 100, stdin);

    int tamExpressao = tamString(expressao);

    for (int i = 0; i < tamExpressao; i++) {
        if (expressao[i] != '+' && expressao[i] != '-' && expressao[i] != '*' && expressao[i] != '/') {
            push(pilha, expressao[i] - '0');
        } else {
            int result;
            int num2 = top(pilha);
            pop(pilha);
            int num1 = top(pilha);
            pop(pilha);
            
            switch (expressao[i]) {
            case '+':
                result = num1 + num2;
                break;
            
            case '-':
                result = num1 - num2;
                break;

            case '*':
                result = num1 * num2;
                break;    
            
            case '/':
                result = num1 / num2;
                break;
            }

            push(pilha, result);
        }
    }

    pop(pilha);
    printf("\nResultado: %d\n\n", top(pilha));

    free(pilha);

    return 0;
}

int tamString(char *string) {
    int i = 0;

    while (string[i] != '\0') {
        i++;
    }

    return i;
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

int push(struct stack_body *pilha, int num) {

    pilha->data[pilha->size] = num;
    pilha->size++;
    return 1;

}

int pop(struct stack_body *pilha){
    if (is_empty(pilha)) return 0;

    pilha->size--;
    return 1;
}

int top(struct stack_body *pilha){
    
    return pilha->data[pilha->size-1];

}