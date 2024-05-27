/*---------------------------------------------------------------*/
/*          FATEC-São Caetano do Sul Estrutura de Dados          */
/*                        Prof Veríssimo                         */
/*                       Atividade B2-6                          */
/*           Objetivo: Lista ordenada - Inserir dados            */
/*            Developers: Bianca Soares & Ruan Defavari          */
/*                        Data:28/05/2024                        */
/*---------------------------------------------------------------*/

#include <stdio.h>
#include <stdlib.h>
#include <time.h>

struct Node {
    int data;
    struct Node* next;
};

void inserirNaListaLigada(struct Node** head_ref, int valor, int posicao) {
    struct Node* new_node = (struct Node*) malloc(sizeof(struct Node));
    new_node->data = valor;

    struct Node* current = *head_ref;
    struct Node* previous = NULL;

    for (int i = 0; i < posicao; i++) {
        previous = current;
        current = current->next;
    }

    if (previous == NULL) {
        new_node->next = *head_ref;
        *head_ref = new_node;
    } else {
        previous->next = new_node;
        new_node->next = current;
    }
}

void imprimirLista(struct Node* node) {
    while (node != NULL) {
        printf("%d ", node->data);
        node = node->next;
    }
    printf("\n");
}

int main() {
    struct Node* head = NULL;
    struct Node* second = NULL;
    struct Node* third = NULL;
    struct Node* fourth = NULL;

    head = (struct Node*) malloc(sizeof(struct Node));
    second = (struct Node*) malloc(sizeof(struct Node));
    third = (struct Node*) malloc(sizeof(struct Node));
    fourth = (struct Node*) malloc(sizeof(struct Node));

    head->data = 10;
    head->next = second;

    second->data = 25;
    second->next = third;

    third->data = 40;
    third->next = fourth;

    fourth->data = 80;
    fourth->next = NULL;

    int valor = 30;
    int posicao = 2;

    clock_t inicio, fim;
    double tempo_gasto;

    inicio = clock();

    inserirNaListaLigada(&head, valor, posicao);

    fim = clock();

    tempo_gasto = ((double) (fim - inicio)) / CLOCKS_PER_SEC;

    printf("Lista ligada após inserção: ");
    imprimirLista(head);
    printf("Tempo de processamento: %f segundos\n", tempo_gasto);

    return 0;
}
