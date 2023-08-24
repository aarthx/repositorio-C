#include <stdio.h>

int main(void){
    char nome[30], telefone[11];
    int idade;

    printf("Digite o seu nome: ");
    scanf("%s", nome);
    printf("Digite sua idade: ");
    scanf("%d", &idade);
    printf("Digite o seu telefone(11 digitos): ");
    scanf("%s", telefone);

    printf("\nO nome do usuário é: %s", nome);
    printf("\nA idade do usuário é: %d", idade);
    printf("\nO telefone do usuário é: %s\n", telefone);
    
}
