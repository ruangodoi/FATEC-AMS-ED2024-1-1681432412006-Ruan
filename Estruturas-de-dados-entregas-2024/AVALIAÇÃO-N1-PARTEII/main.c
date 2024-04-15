/*---------------------------------------------------------------*/
/*     FATEC-São Caetano do Sul       Estrutura de Dados         */
/*                         Prof Veríssimo                        */
/*             Avaliação N1 - Parte II                            */
/*       Objetivo: Controlar Estoque de produtos                 */
/*                                                               */
/*           Developers: Bianca Soares e Ruan Defavari           */
/*                                      Data:13/04/2024          */
/*---------------------------------------------------------------*/

#include "incluir_pacote.h"
#include "consultar_pacote.h"
#include "alterarsts_pacote.h"
#include "listar_pacote.h"

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(void) 
{

  ListaPacote * Pacote;

  Pacote = listaCria();

  int opcao, saida = 1;

  printf("1. Incluir pacote\n");
  printf("2. Alterar status pacote\n");
  printf("3. Buscar pacote\n");
  printf("4. Listar pacotes\n");
  printf("5. Sair do programa\n");

  while(saida != 0){
    

  printf("\nDigite o número da opção: "); scanf("%d", &opcao);

  switch(opcao)
  {
    case 1:
      Pacote = Incluir(&Pacote);
    break;
    
    case 2:
    {
      Alterar(&Pacote);
    }
    break;

    case 3:
      Consultar(&Pacote);
    break;

    case 4:
      Listar(&Pacote);
    break;

    case 5:
     saida = 0;
    break;
  }    
  }
}