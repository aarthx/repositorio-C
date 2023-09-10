#include <stdio.h>
#include <time.h>
#include <stdlib.h>
#include <string.h>

void menuPrincipal() {
  printf("--Bem Vindo ao jogo da adivinhacao!!!--\n");
  printf("Tente adivinhar a palavra secreta\n");
  printf("Voce podera chutar uma letra ou a palavra completa em cada tentativa\n");
}

int main(void) {
  char palavras[5][10] = {"vidro","alicate","cogumelo","vampiro","caramelo"}, palavraSecreta[10], palavraChutada[10], letraChutada;
  size_t tamanhoDaPalavra;
  int opcao, tentativas = 2, letraPresente = 0;

  srand(time(NULL));
  strcpy(palavraSecreta, palavras[(rand() % 5)]);
  tamanhoDaPalavra = strlen(palavraSecreta);

  menuPrincipal();

  do {
    printf("Voce ainda tem %d tentativas!\n", tentativas);
    printf("DICA: A palavra tem %zu letras\n", tamanhoDaPalavra);
    do{
      printf("Voce deseja:\n1 - Chutar uma letra\n2 - Chutar palavra completa\n");
      scanf("%d", &opcao);
      if (opcao != 1 && opcao != 2) {
        printf("Opcao invalida, digite novamente!\n");
      }
    } while (opcao != 1 && opcao != 2);

    if (opcao == 2){
      printf("Digite a palavra que deseja chutar: ");
      scanf("%s", palavraChutada);
      if (*palavraChutada == *palavraSecreta) {
        printf("Parabens voce venceu o jogo!");
        tentativas = 0;
      } else {
        printf("Palavra errada!\n");
        tentativas--;
      }
    } else {
      printf("Digite a letra que deseja chutar: ");
      scanf(" %c", &letraChutada);
      letraPresente = 0;
      for(int i = 0; i < 10; i++) {
        if(palavraSecreta[i] == letraChutada) {
          printf("A letra '%c' esta na posicao %d!\n", letraChutada, i + 1);
          letraPresente = 1;
        }
      }
      if(letraPresente == 0) {
        printf("A letra '%c' nao esta nessa palavra!\n", letraChutada);
      }
      tentativas--;
    }
    if(tentativas == 0 && *palavraChutada != *palavraSecreta) {
      printf("Suas tentativas acabaram, de seu ultimo chute de palavra: ");
      scanf("%s", palavraChutada);
      if (*palavraChutada == *palavraSecreta) {
        printf("Parabens voce venceu o jogo!");
      }
      else {
        printf("Palavra errada! FIM DE JOGO!\n");
      }
    }
  } while(tentativas != 0);
}