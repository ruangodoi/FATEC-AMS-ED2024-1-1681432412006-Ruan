#ifndef INCLUIR_PACOTE_H
#define INCLUIR_PACOTE_H

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct Pacote{
  int id;
  char cidorig[40];
  char ciddest[40];
  int status;
  char conteudo[40];
struct Pacote * prox;
}ListaPacote;


ListaPacote * listaCria(void)
{
  return NULL;
}

ListaPacote * Inserir(ListaPacote * *head, char cidorig[], char ciddest[], int status, char conteudo[])
{
  ListaPacote * novoPacote = (ListaPacote *) malloc(sizeof(ListaPacote));

  if (*head == NULL)
  {
    int id = 2;
    novoPacote -> id = id;
  }
  else
  {
    novoPacote -> id = (*head) -> id + 2;
  }

  strcpy(novoPacote -> cidorig, cidorig);
  strcpy(novoPacote -> ciddest, ciddest);
  novoPacote -> status = status;
  strcpy(novoPacote -> conteudo, conteudo);

  novoPacote -> prox = *head;

  return novoPacote;
}

ListaPacote * Incluir(ListaPacote * *head)
{

  ListaPacote * Pacote = *head;

  char cidorig[40], ciddest[40], conteudo[40];
  int status;

  printf("Digite a cidade origem do pacote: ");
  scanf("%s", cidorig);

  printf("Digite a cidade destino do pacote: ");
  scanf("%s", ciddest);

  printf("Digite o status do pacote \n");
  printf("1 - Em processamento \n");
  printf("2 - Em trânsito \n");
  printf("3 - Em espera \n");
  printf("4 - Entregue \n");
  printf("99 - Extraviado \n");
  scanf("%d", &status);

  printf("Digite o conteúdo do pacote:");
  scanf("%s", conteudo);

  return Inserir(&Pacote, cidorig, ciddest, status, conteudo);
}

#endif