#include <stdio.h>

int main(void) {
    int numero, numeroAtual = 0, numeroAnterior = 1, numeroReserva;
    printf("Digite um número: ");
    scanf("%d", &numero);
    //Mostra a seguência de Fibonacci até logo antes do número escolhido
    while(numeroAtual <= numero) {
        printf("%d - ", numeroAtual);
        numeroReserva = numeroAtual;
        numeroAtual += numeroAnterior;
        numeroAnterior = numeroReserva;
    }
    //Mostra o número logo acima do escolhido
    if(numeroAtual > numero) {
        printf("%d\n", numeroAtual);
    }
}

