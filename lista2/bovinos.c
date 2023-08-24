#include <stdio.h>

int main(void){
    int anos = 0;
    float bovinosTotais = 10, metaBovinos;

    printf("Digite a quantidade final de bovinos: ");
    scanf("%f", &metaBovinos);

    while(bovinosTotais < metaBovinos) {
        bovinosTotais = bovinosTotais + bovinosTotais/3 - bovinosTotais/4;
        anos++;
    }

    printf("Para atingir essa quantidade de bovinos demorará: %d anos!\n", anos);
}
