#include <stdio.h>
#include <locale.h>

float mediaPonder(float div[], int peso[], int quantos);

int main()
{
  int opcao = 0;
  setlocale(LC_ALL, "Portuguese_Brazil");
  while (opcao == 0)
  {
    printf("Selecione a operacao desejada:\n");
    printf(" 1- Soma;\n 2- Subtracao;\n 3- Multiplicacao;\n 4- Divisao;\n 5- Media Ponderada;\n 6- Sair;\n");
    scanf("%d", &opcao);
    if (opcao == 5)
    {
      int quantos;
      printf("Quantos valores serao utilizados?: ");
      scanf("%d", &quantos);
      float div[100];
      int peso[100];
      if (quantos > 100)
      {
        printf("Quantidade de valores excede o limite.\n");
        continue;
      }
      for (int i = 0; i < quantos; i++)
      {
        printf("Digite o %d numero: ", i + 1);
        scanf("%f", &div[i]);
        printf("Digite o peso do %d numero: ", i + 1);
        scanf("%d", &peso[i]);
      }
      float mediaPond = mediaPonder(div, peso, quantos);
      printf("A media das notas dadas e: %.2f\n", mediaPond);
      opcao = 0;
    }
  }
  return 0;
}
float mediaPonder(float div[], int peso[], int quantos)
{
  int pesoTot = 0;
  float divPeso = 0;
  for (int i = 0; i < quantos; i++)
  {
    divPeso += div[i] * peso[i];
    pesoTot += peso[i];
  }
  if (pesoTot == 0)
  {
    return 0;
  }
  return divPeso / pesoTot;
}