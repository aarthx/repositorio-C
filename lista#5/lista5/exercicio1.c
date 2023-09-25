#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct{
  float trocoCheio;
  int nota100, nota50, nota20, nota10, nota5, nota2, nota1, moeda1R, moeda50, moeda25, moeda10, moeda5, moeda1;
} notas;

int main(int argc, char *argv[]) {
  float custo, pago;
  int troco, moedas, cedulas, validaV = 0, validaR = 0;
  notas trocoTotal;

  //Pega os valores dos argumentos de entrada e os valida
  for (int i = 0; i < argc; i++) {
    if (strcmp(argv[i], "-v") == 0) {
      if(argc != i + 1) {
        for (int j = 0; j < strlen(argv[i + 1]); j++) {
          if (argv[i + 1][j] == ',') {
            argv[i + 1][j] = '.';
          }
        }
        custo = atof(argv[i + 1]);
        if(custo != 0) {
          validaV = 1;
        }
      }
    }
    if (strcmp(argv[i], "-r") == 0) {
      if(argc != i + 1) {
        for (int j = 0; j < strlen(argv[i + 1]); j++){
          if (argv[i + 1][j] == ','){
            argv[i + 1][j] = '.';
          }
        }
        pago = atof(argv[i + 1]);
        if(pago != 0) {
          validaR = 1;
        } 
      }
    }
  }
  
  // multiplicar por 100 e mexer com inteiro até que no final
  // Se divida por 100 para voltar
  troco = (pago * 100) - (custo * 100);

  if(!validaV && !validaR) {
    printf("Informe os valores de venda e recebimento (numeros maiores que 0)");
  } else if (!validaV) {
    printf("Informe o valor de venda (numero maior que 0)");
  } else if (!validaR) {
    printf("Informe o valor recebido (numero maior que 0)");
  } else if (custo > pago) {
    printf("O Valor pago foi menor que o custo total!");
  } else {
    trocoTotal.trocoCheio = troco;
    trocoTotal.trocoCheio /= 100;
    printf("Troco total: R$ %.2f\n", trocoTotal.trocoCheio);

    trocoTotal.nota100 = troco / 10000;
    troco -= trocoTotal.nota100 * 10000;
    trocoTotal.nota50 = troco / 5000;
    troco -= trocoTotal.nota50 * 5000;
    trocoTotal.nota20 = troco / 2000;
    troco -= trocoTotal.nota20 * 2000;
    trocoTotal.nota10 = troco / 1000;
    troco -= trocoTotal.nota10 * 1000;
    trocoTotal.nota5 = troco / 500;
    troco -= trocoTotal.nota5 * 500;
    trocoTotal.nota2 = troco / 200;
    troco -= trocoTotal.nota2 * 200;
    trocoTotal.moeda1R = troco / 100;
    troco -= trocoTotal.moeda1R * 100;
    trocoTotal.moeda50 = troco / 50;
    troco -= trocoTotal.moeda50 * 50;
    trocoTotal.moeda25 = troco / 25;
    troco -= trocoTotal.moeda25 * 25;
    trocoTotal.moeda10 = troco / 10;
    troco -= trocoTotal.moeda10 * 10;
    trocoTotal.moeda5 = troco / 5;
    troco -= trocoTotal.moeda5 * 5;
    trocoTotal.moeda1 = troco / 1;
    troco -= trocoTotal.moeda1 * 1;
    cedulas = (trocoTotal.nota100 + trocoTotal.nota50 + trocoTotal.nota20 + trocoTotal.nota10 + trocoTotal.nota5 + trocoTotal.nota2);
    moedas = (trocoTotal.moeda1R + trocoTotal.moeda50 + trocoTotal.moeda25 + trocoTotal.moeda10 + trocoTotal.moeda5 + trocoTotal.moeda1);

    printf("Troco entregue com = %d cedula(s) e %d moeda(s)\n", cedulas, moedas);

    if(trocoTotal.nota100 > 0) {
      printf("(%d) 100 reais\n", trocoTotal.nota100);
    }
    if (trocoTotal.nota50 > 0) {
      printf("(%d) 50 reais\n", trocoTotal.nota50);
    }
    if (trocoTotal.nota20 > 0) {
      printf("(%d) 20 reais\n", trocoTotal.nota20);
    }
    if (trocoTotal.nota10 > 0) {
      printf("(%d) 10 reais\n", trocoTotal.nota10);
    }
    if (trocoTotal.nota5 > 0) {
      printf("(%d) 5 reais\n", trocoTotal.nota5);
    }
    if (trocoTotal.nota2 > 0) {
      printf("(%d) 2 reais\n", trocoTotal.nota2);
    }
    if (trocoTotal.moeda1R > 0) {
      printf("(%d) 1 real\n", trocoTotal.moeda1R);
    }
    if (trocoTotal.moeda50 > 0) {
      printf("(%d) 50 centavos\n", trocoTotal.moeda50);
    }
    if (trocoTotal.moeda25 > 0) {
      printf("(%d) 25 centavos\n", trocoTotal.moeda25);
    }
    if (trocoTotal.moeda10 > 0) {
      printf("(%d) 10 centavos\n", trocoTotal.moeda10);
    }
    if (trocoTotal.moeda5> 0) {
      printf("(%d) 5 centavos\n", trocoTotal.moeda5);
    }
    if (trocoTotal.moeda1> 0) {
      printf("(%d) 1 centavo\n", trocoTotal.moeda1);
    }
  }
}