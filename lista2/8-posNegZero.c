#include <stdio.h>

int main(void) {
    double numero;
    printf("Digite um número: ");
    scanf("%lf", &numero);
    if(numero > 0) {
        printf("O número digitiado é positivo!\n");
    } else if(numero < 0) {
        printf("O número digitiado é negativo!\n");
    } else {
        printf("O número digitiado é zero!\n");
    }
}