#include <stdio.h>

int main(void){
    short idade;
    char nome[10];
    printf("Digite seu nome: ");
    scanf("%s", nome);
    printf("\nDigite sua idade: ");
    scanf("%hd", &idade);
    printf("\nSeu nome é: %s", nome);
    printf("\nSua idade é: %hd\n", idade);
}