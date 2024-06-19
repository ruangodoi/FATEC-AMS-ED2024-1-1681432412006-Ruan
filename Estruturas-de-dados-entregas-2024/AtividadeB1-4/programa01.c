/*--------------------------------------------------------------------------*/
/*   FATEC-São Caetano do Sul                 Estrutura de Dados            */
/*                         Prof Veríssimo                                   */
/*             Objetivo: Soma Entre dois numeros                            */
/*             Paradigama: - programação Estruturada                        */
/*                                                                          */
/*                                                         Data:26/03/2024  */
/*--------------------------------------------------------------------------*/

#include <stdio.h>
#include <stdio.h>
#include <stdlib.h> 

struct lista {
    int info;
    struct lista* prox;
};
typedef struct lista Lista;

Lista* lst_cria(void) {
    return NULL;
}

// Inserção no início: retorna a lista atualizada
Lista* lst_insere(Lista* l, int i) {
    Lista* novo = (Lista*) malloc(sizeof(Lista));
    novo->info = i;
    novo->prox = l;
    return novo;     
}

// Função imprime: Imprime valores dos elementos
void lst_imprime(Lista* l) {
    Lista* p;

    for (p = l; p != NULL; p = p->prox)
        printf("%d\n", p->info);
}

// Função vazia: retorna 1 se vazia; 0 se não vazia
int lst_vazia(Lista* l) {
    if (l == NULL)
        printf("A lista está VAZIA\n");
    else
        printf("A lista NÃO está VAZIA\n");
}

// Função busca: Busca um elemento na lista
int lst_busca(Lista* l, int v) {
    Lista* p;
    for (p = l; p != NULL; p = p->prox) {
        if (p->info == v) {
            printf("Encontrou: %d\n", v);
            return 1;
        }
    }
    printf("Não encontrou: %d\n", v);
    return 0;
}

// Função deleta: deleta elemento da lista
int lst_deleta(Lista* l, int v) {
    Lista* anterior = NULL; // ponteiro para elemento anterior  
    Lista* p = l;      // ponteiro para percorrer a lista

    // procura elemento na lista, guardando anterior
    while (p != NULL && p->info != v) {
        anterior = p;
        p = p->prox;
    }

    // Verifica se achou elemento
    if (p == NULL) {
        printf("Não existe esse elemento:  %d\n", v);
        return 1; // não achou, retorna lista original
    }

    // Retira elemento
    if (anterior == NULL) {
        // retira elemento do início
        l = p->prox;
    } else {
        // retira elemento do meio da lista
        anterior->prox = p->prox;
    }

    free(p); // Utilizada para limpar o número da memória...
    return 0;
}
  // Função libera: "Destroi" a lista da memória
  void lst_libera(Lista* l) {
      Lista* p = l;
      Lista* t;
  
      while (p != NULL) {
          t = p;
          p = p->prox;
          free(t);
      }
  }



// Função para exibir o menu de opções
int exibir_menu() {
    int opcao;
    printf("Escolha uma das opções para seu elemento:\n");
    printf("0. Sair\n");
    printf("1. Incluir\n");
    printf("2. Consultar\n");
    printf("3. Deletar\n");
    printf("4. Listar todos\n");
    printf("5. Liberar lista\n"); 
    
    printf("Opção escolhida: ");
    scanf("%d", &opcao);
    return opcao;
}

int main(void) {
    Lista* l = lst_cria(); // Declara uma lista não inicializada
    int opcao;

    do {
        opcao = exibir_menu();

        switch (opcao) {
            case 1: {
                int valor;
                printf("Digite o valor para inlcuir: ");
                scanf("%d", &valor);
                l = lst_insere(l, valor);
                break;
            }
            case 2: {
                int valor;
                printf("Digite o valor para consultar: ");
                scanf("%d", &valor);
                lst_busca(l, valor);
                break;
            }
            case 3: {
                int valor;
                printf("Digite o valor para deletar: ");
                scanf("%d", &valor);
                lst_deleta(l, valor);
                printf("O valor foi deletado!\n"); 
                break;
            }
            case 4: {
              lst_imprime(l);
              break;
            }
          case 5: {
              lst_libera(l);
              printf("Lista liberada da memoria.\n");
              l = lst_cria();
              break;
          }
            case 0:
                printf("Programa encerrado!\n");
                break;
            default:
                printf("Opção inválida!\n");
                break;
        }
    } while (opcao != 0);

    return 0;
}