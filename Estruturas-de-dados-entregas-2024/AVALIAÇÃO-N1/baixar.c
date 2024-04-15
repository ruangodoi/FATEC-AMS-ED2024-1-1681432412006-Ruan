#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "cadastro.h"

int baixar(Produto * *lista, int id, int qtd)
{
  Produto *t = *lista;
  Produto *ant; 

    if(t == NULL)
    {
    printf( "vazio\n");
    }
    else{

      if(t->id == id)
      {
        t->qtd = t->qtd - qtd;
        if(t->qtd <= 0)
        {
          *lista = t->prox;
          free(t);
        }
        return 0;
      }
        while(t->id != id)
          {
            ant = t;
            t = t->prox;
            if(t->id == id)
            {
              t->qtd = t->qtd - qtd;
              if(t->qtd <= 0)
              {
                ant->prox = t->prox;
                free(t);
              } 
              return 0;
            }
          }
    }
    return 0;
}