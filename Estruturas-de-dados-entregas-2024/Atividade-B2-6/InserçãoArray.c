/*---------------------------------------------------------------*/
/*          FATEC-São Caetano do Sul Estrutura de Dados          */
/*                        Prof Veríssimo                         */
/*                       Atividade B2-6                          */
/*           Objetivo: Lista ordenada - Inserir dados            */
/*            Developers: Bianca Soares & Ruan Defavari          */
/*                        Data:28/05/2024                        */
/*---------------------------------------------------------------*/

#include <stdio.h>
#include <time.h>

void inserirNoArray(int arr[], int tamanho, int valor, int posicao) {
    for (int i = tamanho; i > posicao; i--) {
        arr[i] = arr[i - 1];
    }
    arr[posicao] = valor;
}

int main() {
    int arr[6] = {10, 25, 40, 80};
    int tamanho = 4;
    int valor = 30;
    int posicao = 2;

    clock_t inicio, fim;
    double tempo_gasto;

    inicio = clock();

    inserirNoArray(arr, tamanho, valor, posicao);
    tamanho++;

    fim = clock();

    tempo_gasto = ((double) (fim - inicio)) / CLOCKS_PER_SEC;

    printf("Array após inserção: ");
    for (int i = 0; i < tamanho; i++) {
        printf("%d ", arr[i]);
    }
    printf("\nTempo de processamento: %f segundos\n", tempo_gasto);

    return 0;
}
