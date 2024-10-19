/*---------------------------------------------------------------*/
/*          FATEC-São Caetano do Sul Estrutura de Dados          */
/*                        Prof Veríssimo                         */
/*                        Atividade B4-1                         */
/*             Objetivo: Bubble Sort - Implementação             */
/*                     Developer: Ruan Defavari Godoi            */
/*                        Data:15/10/2024                        */
/*---------------------------------------------------------------*/
#include <stdio.h>

void bubbleSort(int arr[], int n) {
    int i, j, temp;
    int trocou; 
    for (i = 0; i < n-1; i++) {
        trocou = 0; 
        for (j = 0; j < n-i-1; j++) {
            if (arr[j] > arr[j+1]) {

                temp = arr[j];
                arr[j] = arr[j+1];
                arr[j+1] = temp;
                trocou = 1; 
            }
        }
        
        if (trocou == 0)
            break; 
    }
}

void printArray(int arr[], int size) {
    int i;
    for (i = 0; i < size; i++) {
        printf("Índice %d: %d\n", i, arr[i]);
    }
    printf("\n");
}

int main() {
    int n;

    printf("Quantos números você deseja ordenar? ");
    scanf("%d", &n);

    int arr[n]; 

    printf("Digite %d números:\n", n);
    for (int i = 0; i < n; i++) {
        printf("Número %d: ", i+1);
        scanf("%d", &arr[i]);
    }

    printf("Array original: \n");
    printArray(arr, n);

    bubbleSort(arr, n);

    printf("Array ordenado: \n");
    printArray(arr, n);

    return 0;
}
