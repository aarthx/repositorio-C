#include <stdio.h>

int main(void) {
    int numero;
    printf("Digite um número: ");
    scanf("%d", &numero);
    printf("O quadrado desse número é %d\n", numero*numero);
    printf("O cubo desse número é %d\n", numero*numero*numero);
}