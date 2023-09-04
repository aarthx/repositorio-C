#include <stdio.h>
#include <ctype.h>

int main(void) {
    int opcao, deslocamento, testeMensagem, caracterResultado;
    char mensagem[30], mensagemCifrada[30];
    do{
        printf("--- Menu ---\n");
        printf("1 - Cifrar uma mensagem\n");
        printf("2 - Decifrar uma mensagem\n");
        printf("3 - Sair\n");
        printf("Escolha sua opcao: ");
        scanf("%d", &opcao);

        if(opcao == 1) {
            printf("Defina a mensagem a ser cifrada: ");
            scanf("%s", mensagem);
            printf("Defina o deslocamento da cifra: ");
            scanf("%d", &deslocamento);
            for(int i = 0; i < 30; i++){
                if(isalpha(mensagem[i]) != 0) {
                    //65 a 90: Maiusculas // 97 a 122: Minusculas
                    caracterResultado = mensagem[i] + deslocamento;
                    if(mensagem[i] >= 97 && mensagem[i] <= 122) {
                        if(caracterResultado > 122) {
                        caracterResultado = 97 + (caracterResultado - 122 - 1);
                        }
                    }
                    if(mensagem[i] >= 65 && mensagem[i] <= 90) {
                        if(caracterResultado > 90) {
                            caracterResultado = 65 + (caracterResultado - 90 - 1);
                        }
                    }
                    mensagemCifrada[i] = caracterResultado;
                }
            }
            printf("A mensagem '%s' cifrada fica: '%s'\n", mensagem, mensagemCifrada);
        } else if(opcao == 2) {
            printf("Defina a mensagem a ser decifrada: ");
            scanf("%s", mensagemCifrada);
            printf("Defina o deslocamento da cifra: ");
            scanf("%d", &deslocamento);
            for(int i = 0; i < 30; i++){
                if(isalpha(mensagem[i]) != 0) {
                    //65 a 90: Maiusculas // 97 a 122: Minusculas
                    caracterResultado = mensagem[i] - deslocamento;
                    if(mensagem[i] >= 97 && mensagem[i] <= 122) {
                        if(caracterResultado < 97) {
                        caracterResultado = 122 - (97 - caracterResultado - 1);
                        }
                    }
                    if(mensagem[i] >= 65 && mensagem[i] <= 90) {
                        if(caracterResultado < 65) {
                            caracterResultado = 90 - (65 - caracterResultado - 1);
                        }
                    }
                    mensagemCifrada[i] = caracterResultado;
                }
            }
            printf("A mensagem '%s' decifrada fica: '%s'\n", mensagemCifrada, mensagem);
        }

    } while(opcao != 3);
}
