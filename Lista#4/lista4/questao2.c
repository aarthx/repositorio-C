#include <stdio.h>
#include <ctype.h>
#include <string.h>

// A senha deve conter:
// Mínimo 8 caracteres
// pelo menos uma letra maiuscula
// pelo menos uma letra minuscula
// pelo menos um numero
// função deve retornar 1 se a senha for válida e 0 caso contrário

int validaSenha(char senha[25]){
  size_t caracteres = 0, letrasMaiusculas = 0, letrasMinusculas = 0, numeros = 0, resultado;
  for (int i = 0; i < 25; i++) {
    resultado = (isalpha(senha[i]));
    caracteres = strlen(senha);
    if(resultado == 1){
      letrasMaiusculas++;
    }
    else if (resultado == 2) {
      letrasMinusculas++;
    } else {
      resultado = isalnum(senha[i]);
      if (resultado != 0) {
        numeros++;
      }
    }
  }
  if (caracteres >= 8 && letrasMaiusculas >= 1 && letrasMinusculas >= 1 && numeros >= 1) {
    return 1;
  } else {
    return 0;
  }
}

int main(void) {
  char senha[25];

  printf("Digite sua senha (maximo de 25 caracteres): ");
  scanf("%s", senha);

  if(validaSenha(senha)) {
    printf("SENHA VALIDA");
  } else {
    printf("SENHA INVALIDA");
  }
}