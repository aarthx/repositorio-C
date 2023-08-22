#include <stdio.h>

int main(void){
    int numero, fatorial = 1;
    printf("Digite um número: ");
    scanf("%d", &numero);
    for(int i = 1; i <= numero; i++) {
        fatorial *= i;
    }
    printf("A fatorial desse número é: %d\n", fatorial);
}