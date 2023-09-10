#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>

//Algo que não funciona neste codigo ainda é colocar o argumento de deslocamento negativo para decifrar, para decifrar deve-se utilizar sempre o -u

int main(int argc, char *argv[]) {
    int opcao, deslocamento, testeMensagem, caracterResultado, validaK = 0, validaV = 0, validaOpcional = 0;
    char mensagem[30], mensagemCifrada[30], entrada[30], saida[30];
    size_t tamanhoMensagem;
    entrada[0] = '\0';
    for (int i = 0; i < argc; i++) {
        if (i == 1 && strcmp(argv[i], "-k") == 0){
            validaK = 1;
        }
        if (i == 3 && strcmp(argv[i], "-v") == 0){
            validaV = 1;
        }
    }

    if ((validaK && validaV) && argc >= 5) {
        if(strcmp(argv[argc - 1],"-u") == 0){
            opcao = 2;
            validaOpcional = 1;
        }
        else if (strcmp(argv[argc - 1], "-c") == 0){
            opcao = 1;
            validaOpcional = 1;
        } else {
            opcao = 1;
        }
        if(validaOpcional == 0) {
            for(int i = 4; i < argc; i++) {
                if(i != 4) {
                    strcat(entrada, " ");
                }
                strcat(entrada, argv[i]);
            }
        }
        if (validaOpcional == 1){
            for (int i = 4; i < (argc - 1); i++) {
                if (i != 4) {
                    strcat(entrada, " ");
                }
                strcat(entrada, argv[i]);
            }
        }
        
        printf("A entrada ficou: '%s'\n", entrada);

        if(opcao == 1) {
            tamanhoMensagem = strlen(entrada);
            deslocamento = atoi(argv[2]);
            for(int i = 0; i < tamanhoMensagem; i++){
                if(isalpha(entrada[i]) != 0) {
                    //65 a 90: Maiusculas // 97 a 122: Minusculas
                    caracterResultado = entrada[i] + deslocamento;
                    if(entrada[i] >= 97 && entrada[i] <= 122) {
                        if(caracterResultado > 122) {
                        caracterResultado = 97 + (caracterResultado - 122 - 1);
                        }
                    }
                    if(entrada[i] >= 65 && entrada[i] <= 90) {
                        if(caracterResultado > 90) {
                            caracterResultado = 65 + (caracterResultado - 90 - 1);
                        }
                    }
                    saida[i] = caracterResultado;
                } else if(entrada[i] = ' ') {
                    saida[i] = ' ';
                }
            }
            saida[tamanhoMensagem] = '\0';
            printf("A mensagem '%s' cifrada fica: '%s'\n", entrada, saida);
        } else if(opcao == 2) {
            tamanhoMensagem = strlen(entrada);
            deslocamento = atoi(argv[2]);
            for(int i = 0; i < tamanhoMensagem; i++){
                if(isalpha(entrada[i]) != 0) {
                    //65 a 90: Maiusculas // 97 a 122: Minusculas
                    caracterResultado = entrada[i] - deslocamento;
                    if(entrada[i] >= 97 && entrada[i] <= 122) {
                        if(caracterResultado < 97) {
                        caracterResultado = 122 - (97 - caracterResultado - 1);
                        }
                    }
                    if(entrada[i] >= 65 && entrada[i] <= 90) {
                        if(caracterResultado < 65) {
                            caracterResultado = 90 - (65 - caracterResultado - 1);
                        }
                    }
                    saida[i] = caracterResultado;
                } else if (entrada[i] = ' ') {
                    saida[i] = ' ';
                }
            }
            saida[tamanhoMensagem] = '\0';
            printf("A mensagem '%s' decifrada fica: '%s'\n",entrada, saida);
        }
    } else {
        printf("ERROR: Parametro -k ou -v nao declarado ou numero de parametros menor que 5!\n");
    }
}
