#include <stdio.h>

double soma();
double subtracao();
double multiplicacao();
double divisao();
double mediaPonderada();

int main(void){
  int opcao, pesoAtutal, pesoTotal;
  do {
  printf("Qual operacao voce deseja: \n");
  printf("1 - Soma\n");
  printf("2 - Subtracao\n");
  printf("3 - Multiplicacao\n");
  printf("4 - Divisao\n");
  printf("5 - Media Ponderada\nDigite a opcao: ");
  scanf("%d", &opcao);
  if(opcao == 1) {
    printf("O resultado da soma: %lf", soma());
  } else if(opcao == 2) {
    printf("O resultado da subtracao: %lf", subtracao());
  } else if (opcao == 3) {
    printf("O resultado da multiplicacao: %lf", multiplicacao());
  } else if (opcao == 4) {
    printf("O resultado da subtracao: %lf", divisao());
  } else if (opcao == 5) {
    printf("O resultado da media ponderada: %lf", mediaPonderada());
  } else {
    printf("Opcao INVALIDA!!!");
  }
  } while(opcao < 1 || opcao > 5);
}

double soma() {
  int quantidadeNumeros;
  double numAtual, total = 0;
  do {
    printf("Digite quantos numeros irao somar: ");
    scanf("%d", &quantidadeNumeros);
    if (quantidadeNumeros <= 0) {
      printf("Digite um quantidade positiva!!!\n");
    }
  } while(quantidadeNumeros <= 0);
  for(int i = 0; i < quantidadeNumeros; i++) {
    printf("Digite numero a somar: ");
    scanf("%lf", &numAtual);
    total += numAtual;
  }
  return total;
}

double subtracao() {
  int quantidadeNumeros;
  double numAtual, total = 0;
  do {
    printf("Digite quantos numeros irao subtrair: ");
    scanf("%d", &quantidadeNumeros);
    if (quantidadeNumeros <= 0) {
      printf("Digite um quantidade positiva!!!\n");
    }
  } while (quantidadeNumeros <= 0);
  for (int i = 0; i < quantidadeNumeros; i++){
    printf("Digite numero a subtrair: ");
    scanf("%lf", &numAtual);
    total -= numAtual;
  }
  return total;
}

double multiplicacao() {
  int quantidadeNumeros;
  double numAtual, total = 1;
  do {
    printf("Digite quantos numeros irao multiplicar: ");
    scanf("%d", &quantidadeNumeros);
    if (quantidadeNumeros <= 0) {
      printf("Digite um quantidade positiva!!!\n");
    }
  } while (quantidadeNumeros <= 0);
  for (int i = 0; i < quantidadeNumeros; i++) {
    printf("Digite numero a multiplicar: ");
    scanf("%lf", &numAtual);
    total *= numAtual;
  }
  return total;
}

double divisao(){
  int quantidadeNumeros;
  double num1, num2, total;
  do {
    printf("Digite quantos numeros irao dividir: ");
    scanf("%d", &quantidadeNumeros);
    if (quantidadeNumeros <= 1) {
      printf("Digite um quantidade positiva maior que 1!!!\n");
    }
  } while (quantidadeNumeros <= 1);
  printf("Digite o divisor: ");
  scanf("%lf", &num1);
  total = num1;
  for (int i = 0; i < quantidadeNumeros - 1; i++) {
    printf("Digite o numero a dividir: ");
    scanf("%lf", &num2);
    total /= num2;
  }
  return total;
}

double mediaPonderada() {
  int quantidadeNumeros, pesoAtual, pesoTotal = 0;
  double numAtual, numeradorTotal = 0, total;
  do{
    printf("Digite quantos numeros irao entrar nessa media: ");
    scanf("%d", &quantidadeNumeros);
    if (quantidadeNumeros <= 1) {
      printf("Digite um quantidade positiva maior que 1!!!\n");
    }
  } while (quantidadeNumeros <= 1);
  for (int i = 0; i < quantidadeNumeros; i++) {
    printf("Digite o numero: ");
    scanf("%lf", &numAtual);
    printf("Digite o peso deste numero: ");
    scanf("%d", &pesoAtual);
    numeradorTotal += (numAtual * pesoAtual);
    pesoTotal += pesoAtual;
  }
  total = numeradorTotal/pesoTotal;
  return total;
}