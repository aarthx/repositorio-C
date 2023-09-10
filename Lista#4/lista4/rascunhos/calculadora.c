#include <stdio.h>

double somar(double num1, double num2);
double subtracao(double num1, double num2);
double multiplicacao(double num1, double num2);
double divisao(double num1, double num2);
double mediaPonderada(double num1, double num2, int peso1, int peso2);

int main(void)
{
  double num1, num2;
  int opcao, peso1, peso2;
  printf("Qual operacao voce deseja: \n");
  printf("1 - Soma\n");
  printf("2 - Subtracao\n");
  printf("3 - Multiplicacao\n");
  printf("4 - Divisao\n");
  printf("5 - Media Ponderada\nDigite a opcao: ");
  scanf("%d", &opcao);

  printf("Digite o primeiro numero: ");
  scanf("%lf", &num1);
  if(opcao == 5) {
    printf("Digite o peso do primeiro numero: ");
    scanf("%d", &peso1);
  }
  printf("Digite o segundo numero: ");
  scanf("%lf", &num2);
  if (opcao == 5){
    printf("Digite o peso do segundo numero: ");
    scanf("%d", &peso1);
  }
  /* 
  Essas condicionais ficariam melhor com switch mas
  como ainda não foi explicado não utilizei
  */
  if(opcao == 1) {
    printf("O resultado da soma foi: %lf", somar(num1, num2));
  } else if(opcao == 2) {
    printf("O resultado da subtracao foi: %lf", subtracao(num1, num2));
  } else if(opcao == 3) {
    printf("O resultado da multiplicacao foi: %lf", multiplicacao(num1, num2));
  } else if (opcao == 4){
    printf("O resultado da divisao foi: %lf", divisao(num1, num2));
  } else if (opcao == 5){
    printf("O resultado da media ponderada foi: %lf", mediaPonderada(num1, num2, peso1, peso2));
  }
}

double somar(double num1, double num2){
  return num1 + num2;
}

double subtracao(double num1, double num2){
  return num1 - num2;
}

double multiplicacao(double num1, double num2){
  return num1 * num2;
}

double divisao(double num1, double num2){
  return num1 / num2;
}

double mediaPonderada(double num1, double num2, int peso1, int peso2){
  return ((num1 * peso1) + (num2 * peso2)) / (peso1 + peso2);
}
