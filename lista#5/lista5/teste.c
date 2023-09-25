#include <stdio.h>
#include <string.h>

int main(void) {
  
  char frase[30] , fraseTeste[30] = {"Arroz"};
  printf("Digite frase: ");
  fgets(frase, sizeof(frase), stdin); // escrevo Arroz
  printf("%d", strcmp(frase, fraseTeste)); //resulta em 0 Arroz\n == Arroz\n

}