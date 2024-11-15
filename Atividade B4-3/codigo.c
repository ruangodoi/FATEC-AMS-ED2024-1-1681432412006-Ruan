/*---------------------------------------------------------------*/
/*          FATEC-São Caetano do Sul Estrutura de Dados          */
/*                        Prof Veríssimo                         */
/*                       Atividade B3-1                          */
/*           Objetivo: Percurso em ordem de árvore binária       */
/*            Developers: Ruan Defavari Godoi                    */
/*                        Data:10/11/2024                        */
/*---------------------------------------------------------------*/
#include <stdio.h>
#include <stdlib.h>

// Definição da estrutura do nó
struct No {
    int dado;
    struct No* esquerda;
    struct No* direita;
};

// Função para criar um novo nó
struct No* criarNo(int dado) {
    struct No* novoNo = (struct No*)malloc(sizeof(struct No));
    novoNo->dado = dado;
    novoNo->esquerda = NULL;
    novoNo->direita = NULL;
    return novoNo;
}

// Função para inserir um novo nó na BST
struct No* inserir(struct No* raiz, int dado) {
    if (raiz == NULL) {
        return criarNo(dado);
    }
    if (dado < raiz->dado) {
        raiz->esquerda = inserir(raiz->esquerda, dado);
    } else if (dado > raiz->dado) {
        raiz->direita = inserir(raiz->direita, dado);
    }
    return raiz;
}

// Função para buscar um valor na BST
struct No* buscar(struct No* raiz, int dado) {
    if (raiz == NULL || raiz->dado == dado) {
        return raiz;
    }
    if (dado < raiz->dado) {
        return buscar(raiz->esquerda, dado);
    }
    return buscar(raiz->direita, dado);
}

// Função para encontrar o nó mínimo
struct No* encontrarMinimo(struct No* raiz) {
    while (raiz->esquerda != NULL) {
        raiz = raiz->esquerda;
    }
    return raiz;
}

// Função para remover um nó da BST
struct No* removerNo(struct No* raiz, int dado) {
    if (raiz == NULL) {
        return raiz;
    }
    if (dado < raiz->dado) {
        raiz->esquerda = removerNo(raiz->esquerda, dado);
    } else if (dado > raiz->dado) {
        raiz->direita = removerNo(raiz->direita, dado);
    } else {
        if (raiz->esquerda == NULL) {
            struct No* temp = raiz->direita;
            free(raiz);
            return temp;
        } else if (raiz->direita == NULL) {
            struct No* temp = raiz->esquerda;
            free(raiz);
            return temp;
        }
        struct No* temp = encontrarMinimo(raiz->direita);
        raiz->dado = temp->dado;
        raiz->direita = removerNo(raiz->direita, temp->dado);
    }
    return raiz;
}

// Função para imprimir a BST em ordem
void emOrdem(struct No* raiz) {
    if (raiz != NULL) {
        emOrdem(raiz->esquerda);
        printf("%d ", raiz->dado);
        emOrdem(raiz->direita);
    }
}

int main() {
    struct No* raiz = NULL;
    raiz = inserir(raiz, 8);
    raiz = inserir(raiz, 3);
    raiz = inserir(raiz, 10);
    raiz = inserir(raiz, 1);
    raiz = inserir(raiz, 6);
    raiz = inserir(raiz, 14);
    raiz = inserir(raiz, 4);
    raiz = inserir(raiz, 7);
    raiz = inserir(raiz, 13);

    printf("Percurso em ordem: ");
    emOrdem(raiz);
    printf("\n");

    raiz = removerNo(raiz, 10);
    printf("Percurso em ordem após remoção: ");
    emOrdem(raiz);
    printf("\n");

    return 0;
}