#include <stdio.h>

int main(void) {
    double celsius, fahrenheit;
    printf("Digite a temperatura em graus Celsius: ");
    scanf("%lf", &celsius);
    fahrenheit = (celsius * 9 / 5) + 32;
    printf("Esta temperatura em graus Fahrenheit é: %.1lf°F\n", fahrenheit);
}