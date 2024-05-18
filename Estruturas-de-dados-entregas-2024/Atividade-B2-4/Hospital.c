/*---------------------------------------------------------------*/
/*          FATEC-São Caetano do Sul Estrutura de Dados          */
/*                        Prof Veríssimo                         */
/*                       Atividade B2-4                          */
/*    Objetivo: Implemementar fila de atendimento - Hospital     */
/*                    Developer: Ruan Defavari Godoi             */
/*                        Data:13/05/2024                        */
/*---------------------------------------------------------------*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>
#include <time.h>

#define MAX_NAME_LENGTH 50

typedef struct { 
    char name[MAX_NAME_LENGTH];
    int  idade;
    char prioridade; 
    char motivo[100];
    int consultorio; 
    time_t hora_chegada;
    time_t hora_atendimento_inicio;
    time_t hora_atendimento_fim;
} Paciente;

typedef struct no {
    Paciente paciente;
    struct no *prox;
} No;

typedef struct {
    No *inicio;
    No *fim;
    int tamanho;
} Fila;

// Função para inicializar a fila
void filaInicio(Fila* fila) {
    fila->inicio = fila->fim = NULL;
    fila->tamanho = 0; 
}

// Função para verificar se a fila está vazia
int filaVazia(Fila* fila) {
    return fila->inicio == NULL;
}

// -------------------- Inserção de um paciente na fila --------------------
void addPaciente(Fila* fila, Paciente paciente) {
    No* no = (No*)malloc(sizeof(No));
    if (no == NULL) {
        printf("Erro: não foi possível alocar memória.\n");
        exit(EXIT_FAILURE);
    }
    no->paciente = paciente;
    no->prox = NULL;

    if (filaVazia(fila)) {
        fila->inicio = fila->fim = no;
    } else {
        fila->fim->prox = no;
        fila->fim = no;
    }
    fila->tamanho++; 
}

// -------------------- Remoção de um paciente na fila --------------------
Paciente removerPaciente(Fila* fila) {
    if (filaVazia(fila)) {
        printf("Erro: a fila está vazia\n");
        exit(EXIT_FAILURE);
    }

    No* temp = fila->inicio;
    Paciente paciente = temp->paciente;

    fila->inicio = fila->inicio->prox;
    free(temp);

    fila->tamanho--; 

    return paciente;
}

// -------------------- Impressão das informações de um paciente --------------------
void imprimirDadosPaciente(Paciente paciente){
    printf("\nNome: %s\n", paciente.name);
    printf("Idade: %d\n", paciente.idade);
    printf("Prioridade: %c\n", paciente.prioridade);
    printf("Motivo: %s\n", paciente.motivo);
    printf("Consultório: %d\n", paciente.consultorio); 

    struct tm* info_chegada = localtime(&paciente.hora_chegada);
    char buffer_chegada[80];
    strftime(buffer_chegada, 80, "%H:%M:%S", info_chegada);
    printf("Hora de chegada: %s\n", buffer_chegada);

    // Se hora_atendimento_inicio for diferente de zero, então o paciente foi atendido
    if (paciente.hora_atendimento_inicio != 0) {
        // Converter o horário de atendimento para uma string legível
        struct tm* info_inicio = localtime(&paciente.hora_atendimento_inicio);
        char buffer_inicio[80];
        strftime(buffer_inicio, 80, "%H:%M:%S", info_inicio);
        printf("Hora de atendimento (inicio): %s\n", buffer_inicio);

        if (paciente.hora_atendimento_fim != 0) {
            struct tm* info_fim = localtime(&paciente.hora_atendimento_fim);
            char buffer_fim[80];
            strftime(buffer_fim, 80, "%H:%M:%S", info_fim);
            printf("Hora de atendimento (fim): %s\n", buffer_fim);
        }
    }
}

// -------------------- Mostrar lista da fila dos pacientes --------------------
void visualizarFila(Fila* fila) {
    if (filaVazia(fila)) {
        printf("A fila está vazia.\n");
        return;
    }
  
    No* atual = fila->inicio;
    int i = 1;
    while (atual != NULL) {
        printf("Paciente %d:\n", i);
        imprimirDadosPaciente(atual->paciente);
        printf("\n");
        atual = atual->prox;
        i++;
    }
}

// -------------------- Leitura dos Dados de um paciente --------------------
Paciente lerDadosPaciente(Fila* filaNormal, Fila* filaPrioritaria, Fila* filaUrgente) {
    Paciente paciente;

    printf("\nDigite o nome do paciente: ");
    scanf("%s", paciente.name);
    printf("Digite a idade do paciente: ");
    scanf("%d", &paciente.idade);
    printf("Digite o motivo da consulta: ");
    scanf(" %[^\n]", paciente.motivo);
    printf("Digite o número do consultório: "); 
    scanf("%d", &paciente.consultorio); 
    time(&paciente.hora_chegada);

    // Inicialização dos campos hora_atendimento_inicio e hora_atendimento_fim
    paciente.hora_atendimento_inicio = 0;
    paciente.hora_atendimento_fim = 0;

    while(getchar() != '\n');

    if (paciente.idade >= 60 || strcmp(paciente.motivo, "Gestante") == 0) {
        addPaciente(filaPrioritaria, paciente);
    } else {
        char urgente;
        printf("O paciente tem uma emergência (s/n)? ");
        scanf(" %c", &urgente);

        if (urgente == 's' || urgente == 'S') {
            addPaciente(filaUrgente, paciente);
        } else {
            addPaciente(filaNormal, paciente);
        }
    }
    return paciente;
}

// -------------------- Atendimento de um paciente --------------------
void atenderPaciente(Fila* filaNormal, Fila* filaPrioritaria, Fila* filaUrgente, Fila* filaHistorico) {
    Paciente pacienteAtendido;


    if (!filaVazia(filaUrgente)) {
        pacienteAtendido = removerPaciente(filaUrgente);
        printf("Chamando paciente %s da fila urgente para o consultório %d.\n", pacienteAtendido.name, pacienteAtendido.consultorio);
    }

    else if (!filaVazia(filaPrioritaria)) {
        pacienteAtendido = removerPaciente(filaPrioritaria);
        printf("Chamando paciente %s da fila prioritária para o consultório %d.\n", pacienteAtendido.name, pacienteAtendido.consultorio);
    }

    else if (!filaVazia(filaNormal)) {
        pacienteAtendido = removerPaciente(filaNormal);
        printf("Chamando paciente %s da fila normal para o consultório %d.\n", pacienteAtendido.name, pacienteAtendido.consultorio);
    } else {
        printf("Não há pacientes para atender.\n");
        return;
    }

    time(&pacienteAtendido.hora_atendimento_inicio);
    time(&pacienteAtendido.hora_atendimento_fim);

    addPaciente(filaHistorico, pacienteAtendido);

    printf("Paciente %s atendido.\n", pacienteAtendido.name);
}

// -------------------- MAIN OPÇÕES --------------------
int main() {
    Fila filaNormal;
    Fila filaPrioritaria;
    Fila filaUrgente;
    Fila filaHistorico;

    filaInicio(&filaNormal);
    filaInicio(&filaPrioritaria);
    filaInicio(&filaUrgente);
    filaInicio(&filaHistorico);

    int opcao;

    do {
        printf("\n\t0 - Sair\n\t1 - Inserir Paciente na Fila\n\t2 - Atender Paciente\n\t3 - Imprimir filas\n\t4 - Imprimir Histórico\n");
        scanf("%d", &opcao);

        switch(opcao) {
            case 1: // Inserir paciente na fila
                lerDadosPaciente(&filaNormal, &filaPrioritaria, &filaUrgente);
                break;

            case 2: // Remover paciente ou atender paciente
                atenderPaciente(&filaNormal, &filaPrioritaria, &filaUrgente, &filaHistorico);
                break;

            case 3: // Imprimir filas
                printf("\n--Fila Normal:\n");
                visualizarFila(&filaNormal);
                printf("\n--Fila Prioritaria:\n");
                visualizarFila(&filaPrioritaria);
                printf("\n--Fila Urgente:\n");
                visualizarFila(&filaUrgente);
                break;

            case 4: // Imprimir histórico
                printf("\nHistórico de atendimentos:\n");
                visualizarFila(&filaHistorico);
                break;

            default:
                if(opcao != 0)
                    printf("\nOpção inválida.\n");
        }
    } while(opcao != 0);

    return 0;
}