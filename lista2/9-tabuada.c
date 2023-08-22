#include <stdio.h>

int main(void) {
    int numero;
    printf("Digite um Número: ");
    scanf("%d", &numero);
    for(int i = 1; i <= 10; i++) {
        printf("%d x %d = %d\n", numero, i, numero * i);
    }
}