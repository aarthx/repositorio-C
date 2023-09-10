#include <stdio.h>
#include <ctype.h>
#include <string.h>

int main(int argc, char *argv[]) {
    int opcao, deslocamento, testeMensagem, caracterResultado, validaK = 0, validaV = 0;
    char mensagem[30], mensagemCifrada[30];
    size_t tamanhoMensagem;

    for (int i = 0; i < argc; i++) {
        if (i == 1 && strcmp(argv[i], "-k") == 0){
            validaK = 1;
        }
        if (i == 3 && strcmp(argv[i], "-v") == 0){
            validaV = 1;
        }
    }

    if (validaK && validaV) {
        do{
            printf("--- Menu ---\n");
            printf("1 - Cifrar uma mensagem\n");
            printf("2 - Decifrar uma mensagem\n");
            printf("3 - Sair\n");
            printf("Escolha sua opcao: ");
            scanf("%d", &opcao);

            if(opcao == 1) {
                printf("Defina a mensagem a ser cifrada: ");
                while(getchar() != '\n');
                fgets(mensagem, sizeof(mensagem), stdin);
                tamanhoMensagem = strlen(mensagem);
                mensagem[tamanhoMensagem - 1] = '\0';
                printf("Defina o deslocamento da cifra: ");
                scanf("%d", &deslocamento);
                for(int i = 0; i < tamanhoMensagem - 1; i++){
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
                    } else if(mensagem[i] = ' ') {
                        mensagemCifrada[i] = ' ';
                    }
                }
                mensagemCifrada[tamanhoMensagem - 1] = '\0';
                printf("A mensagem '%s' cifrada fica: '%s'\n", mensagem, mensagemCifrada);
            } else if(opcao == 2) {
                printf("Defina a mensagem a ser decifrada: ");
                while (getchar() != '\n');
                fgets(mensagemCifrada, sizeof(mensagemCifrada), stdin);
                tamanhoMensagem = strlen(mensagemCifrada);
                mensagemCifrada[tamanhoMensagem - 1] = '\0';
                printf("Defina o deslocamento da cifra: ");
                scanf("%d", &deslocamento);
                for(int i = 0; i < tamanhoMensagem; i++){
                    if(isalpha(mensagemCifrada[i]) != 0) {
                        //65 a 90: Maiusculas // 97 a 122: Minusculas
                        caracterResultado = mensagemCifrada[i] - deslocamento;
                        if(mensagemCifrada[i] >= 97 && mensagemCifrada[i] <= 122) {
                            if(caracterResultado < 97) {
                            caracterResultado = 122 - (97 - caracterResultado - 1);
                            }
                        }
                        if(mensagemCifrada[i] >= 65 && mensagemCifrada[i] <= 90) {
                            if(caracterResultado < 65) {
                                caracterResultado = 90 - (65 - caracterResultado - 1);
                            }
                        }
                        mensagem[i] = caracterResultado;
                    } else if (mensagemCifrada[i] = ' ') {
                        mensagem[i] = ' ';
                    }
                }
                mensagem[tamanhoMensagem - 1] = '\0';
                //Não entendi mas minha mensagemCifrada ao final ficava com um espaço em branco então retiro ele aqui apos o for para não alterar a mensagem final decifrada
                mensagemCifrada[tamanhoMensagem - 1] = '\0';
                printf("A mensagem '%s' decifrada fica: '%s'\n",mensagemCifrada, mensagem);
            }
        } while(opcao != 3);
    }
    else {
        printf("ERROR: Parametro -k ou -v nao declarado!\n");
    }
}
