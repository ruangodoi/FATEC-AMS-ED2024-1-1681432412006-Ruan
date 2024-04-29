#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/*___________________________________________________________________________________*/
/*                                                                                   */
/*   Fatec - São Caetano Do Sul                Estrutura de Dados Profº Veríssimo    */
/*                          Ruan Defavari Godoi                                      */
/*                    Objetivo: Calculadora HP12C                                    */
/*                    Paradigma: Usar Estrutura de pilha e memórias                  */
/*                                                                                   */
/*                                                            22/04/24               */
/*___________________________________________________________________________________*/

#define STACK_SIZE 1500

typedef struct{
  float data[STACK_SIZE];
  char arit[STACK_SIZE];
  int topo;
}Pilha;

Pilha * pilhaCria(){
  Pilha * pilha = (Pilha *) malloc(sizeof(Pilha));
  pilha -> topo = -1;
  return pilha;
}

int vazia(Pilha * pilha){
  return pilha -> topo == -1;
}

int lotada(Pilha * pilha){
  return pilha -> topo == STACK_SIZE -1;
}


int isNum(char *elemento){
    if (*elemento >= '0' && *elemento <= '9') return 1;
    else return 0;
}

void push(Pilha * pilha, float * valor){

  if(lotada(pilha)){ 
    printf("Lista lotada!");
  }
  else{
      pilha->topo++;
      pilha->data[pilha->topo] = *valor;
  }
}

void pushArit(Pilha * pilha, char strCalculo[]){

  if(lotada(pilha)) printf("Lista lotada!");
  else{
    pilha->topo++;
    strcpy(&pilha->arit[pilha->topo], strCalculo);
  }
}

float pop(Pilha * pilha){

  if(vazia(pilha)){
    printf("Lista vazia!");
    return -1;
  }
  else{

    float valor = pilha->data[pilha->topo];
    pilha -> topo--;
    return valor;
  }
}

void calcAritmetica(float * a, float * b, char * ope){

  char strCalculo[50];
  sprintf(strCalculo, "%.2f %c %.2f", *b, *ope, *a);

  printf("\nCada passo da operação aritmética: %s\n", strCalculo);

}

void funcUnica(Pilha * pilha, float * a, float * b, char * ope, char strCalculo[]){

  static int chama = 0;

  if(chama == 0){
  sprintf(strCalculo, "%.2f %c %.2f", *b, *ope, *a);
  pushArit(pilha,strCalculo);
  chama = 1;
  return;
  }
  else return;

}

void opAritmetica(Pilha * pilha, float * a, float * b, char * ope, int * count){

  char strCalculo[STACK_SIZE];
  char opNaLista[STACK_SIZE];
  char novoCalc[STACK_SIZE];

  funcUnica(pilha, a, b, ope, strCalculo);

  if(*count > 0){
      strcpy(opNaLista, &pilha->arit[pilha->topo]);
      sprintf(novoCalc, "%c %.2f", *ope, *a);

      sprintf(strCalculo, "(%s) %s", opNaLista, novoCalc);
      pushArit(pilha,strCalculo);
  }
}

float calcular(float * ope1, float * ope2, char * ope) {

  calcAritmetica(ope1,ope2,ope);

    switch (*ope) {
        case '+':
            return *ope1 + *ope2;
        case '-':
            return -*ope1 + *ope2;
        case '*':
            return *ope1 * *ope2;
        case '/':
            return *ope1 / *ope2;

        default:
            printf("Operador está inválido\n");
          return 0;
    }

}

void separar(Pilha * pilha, char RPN[]) {

  float ope1;
  float ope2;
  char operador;

  int count = 0;

  char * simbolo = strtok(RPN, " ");

  while (simbolo != NULL){
    if(isNum(&simbolo[0])){
      float ope = atof(simbolo);
      push(pilha, &ope);
    }
    else{
      ope1 = pop(pilha);
      ope2 = pop(pilha);
      operador = simbolo[0];

      float resultado = calcular(&ope1, &ope2, &simbolo[0]);
      opAritmetica(pilha, &ope1,&ope2,&operador, &count);
      push(pilha, &resultado);

      count++;
    }
    simbolo = strtok(NULL, " ");
  }
  float resulFinal = pop(pilha);

  printf("\nOperação aritmética: %s\n", &pilha->arit[pilha->topo]);

  printf("\nResultado: %.2f\n",resulFinal);

}

int main(void){

  Pilha * pilha;

  pilha = pilhaCria();

  char RPN[STACK_SIZE];


  printf("\nDigite em RPN: "); scanf("%[^\n]s",RPN);

  separar(pilha,RPN);

}