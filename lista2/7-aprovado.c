#include <stdio.h>

int main(void) {
    double nota;
    printf("Digite a sua nota: ");
    scanf("%lf", &nota);
    if(nota >= 6) {
        printf("Você foi aprovado Parabéns!!!\n");
    } else {
        printf("Você foi REPROVADO!!!\n");
    }
}