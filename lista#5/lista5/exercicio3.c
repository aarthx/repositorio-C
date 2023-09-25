#include <stdio.h>
#include <string.h>

int main(int argc, char *argv[]) {
  int tamanho;
  if(argc == 1) {
    printf("Insira a string de frutas: fruta1-fruta2-fruta3");
  } else if(argc > 2) {
    printf("Utilize apenas um argumento");
  } else {
    tamanho = strlen(argv[1]);
    for(int i = 0; i < tamanho; i++) {
      if (argv[1][i] == '-') {
        argv[1][i] = ' ';
      }
    }
    printf("%s", argv[1]);
  }
}