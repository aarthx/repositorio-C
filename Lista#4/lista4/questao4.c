#include <stdio.h>
#include <string.h>
#include <ctype.h>

//Problema atuais: 
//Ao escanear o item a ser deletado se o que for digitado não for
//numero a execucao buga

void ExibirMenuPrincipal(){
  printf("--- Menu ---\n");
  printf("1 - Exibir item\n");
  printf("2 - Adicionar item\n");
  printf("3 - Remover item\n");
  printf("0 - Sair\n");
}

int contaItens(char itens[10][25]){
  int contador = 0;
  for(int i = 0; i < 10; i++){
    if(itens[i][0] != '\0') {
      contador++;
    }
  }
  return contador;
}

int main(void) {
  char itens[10][25];
  int opcao = 1, quantidadeItens, itemADeletar;
  for(int i = 0; i < 10; i++) {
    itens[i][0] = '\0';
  }
  do {
    ExibirMenuPrincipal();
    printf("Digite sua opcao: ");
    scanf("%d", &opcao);
    switch(opcao) {
      case 1:
        quantidadeItens = contaItens(itens);
        if(quantidadeItens == 0) {
          printf("Lista de itens vazia!\n");
        } else {
          for(int i = 0; i < quantidadeItens; i++) {
            printf("Item %d: %s\n", i+1, itens[i]);
          }
        }
      break;
      case 2:
        quantidadeItens = contaItens(itens);
        if (quantidadeItens == 10) {
          printf("Lista de itens CHEIA remova um item antes!\n");
          break;
        } else {
          printf("Digite o nome do produto: ");
          //Tentei utilizar o fgets mas deu problemas
          scanf("%s",itens[quantidadeItens]);
          printf("ITEM ADICIONADO!\n");
        }
      break;
      case 3:
        quantidadeItens = contaItens(itens);
        printf("Digite o numero do item a ser removido: ");
        scanf("%d", &itemADeletar);
        if (itemADeletar < 1 || itemADeletar > 10) {
          printf("indice Invalido!\n");
          break;
        }
        else
        {
          if(itens[itemADeletar - 1][0] == '\0') {
            printf("Nao existe item neste numero!\n");
          } else {
            itens[itemADeletar - 1][0] = '\0';
            // Nesta parte, todos os itens do array se deslocam um espaço para baixo, para ocupar a posicao do item removido
            for(int i = itemADeletar - 1; i < 9; i++) {
              if(itens[i + 1][0] != '\0') {
                strcpy(itens[i], itens[i + 1]);
                itens[i + 1][0] = '\0';
              } else {
                i = 9;
              }
            }
            printf("ITEM REMOVIDO\n");
          }
        }
      break;
      case 0:
        printf("PROGRAMA FINALIZADO!");
      break;
      default:
        printf("Opcao invalida digite novamente\n");
    }

  } while(opcao != 0);
}