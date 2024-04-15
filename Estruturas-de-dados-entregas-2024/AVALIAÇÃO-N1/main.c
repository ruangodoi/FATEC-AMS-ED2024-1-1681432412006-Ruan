/*---------------------------------------------------------------*/
/*     FATEC-São Caetano do Sul       Estrutura de Dados         */
/*                         Prof Veríssimo                        */
/*             Avaliação N1 - Parte I                            */
/*       Objetivo: Controlar Estoque de produtos                 */
/*                                                               */
/*           Developers: Bianca Soares e Ruan Defavari           */
/*                                      Data:10/04/2024          */
/*---------------------------------------------------------------*/

#include <stdio.h>
#include <stdlib.h>
#include "cadastro.h"
#include "busca.h"
#include "baixar.h"

int main(void) {
  int opcao;
  Produto *novo = NULL;
  do{
    printf("1-Cadastrar produto\n");
    printf("2-Mostrar produtos\n");
    printf("3-Baixar produto\n");
    printf("4-Buscar produto\n");
    printf("5-Sair\n");
    printf("Escolha uma opção: ");
    scanf("%d", &opcao);


    switch(opcao){
      case 1: 
        printf("ID do produto:");
        int id; 
        scanf("%d", &id);
        
        printf("Nome do produto:");
        char name [45];
        scanf("%s", name);

        printf("Quantidade do produto:");
        int qtd;
        scanf("%d", &qtd);
        
        printf("Preço do produto:");
        float preco;
        scanf("%f", &preco); 
        insere(&novo,id, name, qtd, preco);
        printf("-------------------------- \n");
      break;
      case 2: 
        imprime(&novo);
      
      break;
      case 3: 
        printf("ID do produto:");
         scanf("%d", &id);
        printf("Quantidade que foram vendida:");
        scanf("%d", &qtd);
        baixar(&novo, id, qtd);
        printf("-------------------------- \n");
      break;
      case 4: 
        printf("ID do produto:");
        scanf("%d", &id);
        busca(&novo, id);
      break;
    }
  }while (opcao !=5);

  return 0;
}