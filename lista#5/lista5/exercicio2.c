#include <stdio.h>
#include <string.h>
#include <ctype.h>

int main(int argc, char *argv[]) {
    char frase[30], buffer[30];
    int tamanho;
    if(argc > 1) {
        printf("Resultado: ");
        for (int i = 1; i < argc; i++)
        {
            tamanho = strlen(argv[i]);
            for (int j = 0; j < tamanho; j++)
            {
                printf("%c", tolower(argv[i][j]));
            }
            printf(" ");
      }
    } else {
      if (fgets(buffer, sizeof(buffer), stdin) != NULL) {
        for (int i = 0; i < strlen(buffer); i++){
            buffer[i] = tolower(buffer[i]);
        }
        printf("Resultado: %s", buffer);
      } else {
        printf("Digite as palavras para serem transformadas em minusculas: \n");
        fgets(frase, sizeof(frase), stdin);
        for (int i = 0; i < strlen(frase); i++){
            frase[i] = tolower(frase[i]);
        }
        printf("Resultado: %s", frase);
      }
      
    } 
}