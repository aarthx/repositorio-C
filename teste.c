#include <stdio.h>

int main(){

    int programa = 1, opcao;
    float saque, deposito, saldo; 
    char nome[20];

    while(programa){
        scanf("%d", &opcao);
        if(opcao == 1){
            printf("Digite seu nome: ");
            scanf("%s", nome);
            printf("Digite seu primeiro depósito: ");
            scanf("%f", &saldo);
            
        } 
        if(opcao == 2){
            printf("Digite o valor no qual deseja fazer um depósito: ");
            scanf("%f", &deposito);
            saldo = saldo + deposito;
        }
        if(opcao == 3){
            printf("Digite o valor no qual deseja sacar: ");
            scanf("%f", &saque);
            saldo = saldo - saque;
        }
        if(opcao == 4){
            printf("O valor do seu saldo é de %f", saldo);
        }
        if(opcao == 5){
            !programa;
        }

    }

}
