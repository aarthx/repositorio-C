#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

int main(void){
  char vogais[] = {'a','e','i','o','u'};
  int quantidadeVogais = 0;
  char frase[50];
  size_t caracteres;
  printf("Digite uma frase: ");
  fgets(frase, 50, stdin);
  caracteres = strlen(frase) - 1;
  for(int i = 0; i < caracteres; i++) {
    for(int j = 0; j < 5; j++) {
      if(tolower(frase[i]) == vogais[j]) {
        quantidadeVogais++;
      }
    }
  }
  printf("Sua frase tem %d vogais!!", quantidadeVogais);
}