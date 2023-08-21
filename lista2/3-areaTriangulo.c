#include <stdio.h>

int main(void) {
    double base, altura, area;
    printf("Digite a base do triangulo: ");
    scanf("%lf", &base);
    printf("\nDigite a altura do triangulo: ");
    scanf("%lf", &altura);
    area = (base * altura) / 2;
    printf("\nA área deste triângulo é: %.2lf\n", area);
}