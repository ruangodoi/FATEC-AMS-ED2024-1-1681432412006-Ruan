/*---------------------------------------------------------------*/
/*          FATEC-São Caetano do Sul Estrutura de Dados          */
/*                        Prof Veríssimo                         */
/*               CONTINUAÇÃO Atividade B3-4                      */
/*             Objetivo: Transformar o código em ITERAÇÃO        */
/*              Developers: Bianca Soares & Ruan Defavari        */
/*                        Data:23/09/2024                        */
/*---------------------------------------------------------------*/


#include <stdio.h>
#include <math.h>

int is_prime(int num) {
    if (num < 2) {
        return 0;
    }
    for (int i = 2; i <= sqrt(num); i++) {
        if (num % i == 0) {
            return 0; 
        }
    }
    return 1; 
}

void get_next_session(int sessions[][4], int session_count, int session_size) {

    int example_sessions[3][4] = {
        {23, 15, 11, 49},  
        {97, 4, 17, 50},  
        {5, 29, 16, 77}    
    };

    for (int i = 0; i < session_count; i++) {
        for (int j = 0; j < session_size; j++) {
            sessions[i][j] = example_sessions[i][j];
        }
    }
}

int main() {
    int session_count = 3;  
    int session_size = 4;   
    int sessions[3][4];    

    get_next_session(sessions, session_count, session_size);

    for (int i = 0; i < session_count; i++) {
        printf("Verificando sessão %d:\n", i + 1);
        for (int j = 0; j < session_size; j++) {
            int data_packet = sessions[i][j];
            if (is_prime(data_packet)) {
                printf("%d é primo.\n", data_packet);
            } else {
                printf("%d não é primo.\n", data_packet);
            }
        }
    }

    printf("Todas as sessões foram processadas.\n");
    return 0;
}
