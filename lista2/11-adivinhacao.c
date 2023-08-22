#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main(void) {
    int numeroSecreto, numeroTentativas, numero = -1;
    printf("Adivinhe o numero secreto!!!\n");
    printf("Quantas tentativas o jogo terá: \n");
    scanf("%d", &numeroTentativas);
    
    srand(time(NULL));
    numeroSecreto = rand() % 101;

    while(numero != numeroSecreto && numeroTentativas > 0) {
        printf("chute um número entre 1 e 100: ");
        scanf("%d", &numero);
        if(numeroSecreto > numero) {
            printf("O número secreto é MAIOR que o número chutado!\n");
        } else {
            printf("O número secreto é MENOR que o número chutado!\n");
        }
        numeroTentativas--;
    }

    if(numero == numeroSecreto) {
        printf("PARABÉNS VOCÊ CONSEGUIU!!!");
    } 

    if(numero != numeroSecreto && numeroTentativas == 0) {
        printf("O numero secreto era: %d\n", numeroSecreto);
        printf("Suas tentativas acabaram, GAME OVER!");
    }
}