#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "incluir_pacote.h"

void Alterar(ListaPacote * *head)
{
  ListaPacote * Pacote = *head;

  int id, novoStatus;
  printf("Digite o id do pacote que deseja alterar: \n");
  scanf("%d", &id);

  for(ListaPacote * Temp = Pacote; Temp != NULL; Temp = Temp -> prox)
  {
    if(id == Temp -> id)
    {
      printf("Digite o status do pacote\n");
      printf("1 - Em processamento \n");
      printf("2 - Em trânsito\n");
      printf("3 - Em espera\n");
      printf("4 - Entregue\n");
      printf("99 - Extraviado\n");

      scanf("%d", &novoStatus);
    
      Temp -> status = novoStatus;

      return;
    }
    else{
      printf("O pacote não foi encontrado!\n");
      return;
    }
    return;
  }
}