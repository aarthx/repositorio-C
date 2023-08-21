#include <stdio.h>

int main(void) {
    int ano;
    printf("Digite um ano: ");
    scanf("%d", &ano);
    if((ano % 4 == 0 && ano % 100 != 0) || ano % 400 == 0) {
        printf("O ano é bissexto!\n");
    } else {
        printf("O ano NÃO é bissexto!\n");
    }
}