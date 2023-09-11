#include <stdio.h>
#include <string.h>

typedef struct{
        char nome[50];
        float nota[2];
} aluno;

aluno pegaDados(aluno aluno, char nome[], float nota1, float nota2);
void mostraMedia(aluno aluno);

int main() {
    aluno alunos[5];
    int opcao = 0, contaAlunos = 0;
    char nomeAtual[50];
    float notaAtual[2];

    do {
        printf("---Menu---\n");
        printf("1 - Adicionar Aluno\n");
        printf("2 - Calcular media do aluno\n");
        printf("3 - Sair\n");
        printf("Escolha sua opcao: ");
        scanf("%d", &opcao);

        if(opcao == 1) {
            if(contaAlunos < 5) {
                printf("Digite o nome do aluno: ");
                scanf("%s", nomeAtual);
                printf("Digite a primeira nota: ");
                scanf("%f", &notaAtual[0]);
                printf("Digite a segunda nota: ");
                scanf("%f", &notaAtual[1]);
                alunos[contaAlunos] = pegaDados(alunos[contaAlunos], nomeAtual, notaAtual[0], notaAtual[1]);
                printf("%s adicionado como aluno!\n", nomeAtual);
                contaAlunos++;
            } else {
                printf("Quantidade limite de alunos excedida!\n");
            }
        }
        if(opcao == 2) {
            if(contaAlunos > 0) {
                printf("Digite o nome do aluno: ");
                scanf("%s", nomeAtual);
                for(int i = 0; i <= contaAlunos - 1; i++) {
                    if(strcmp(alunos[i].nome, nomeAtual) == 0) {
                        mostraMedia(alunos[i]);
                    }
                }
            } else {
                printf("Ainda nao ha alunos registrados!\n");
            }  
        }
        if(opcao == 3) {
            printf("PROGRAMA FINALIZADO!\n");
        }

    } while(opcao != 3);
}

aluno pegaDados(aluno aluno, char nome[], float nota1, float nota2) {
    strcpy(aluno.nome, nome);
    aluno.nota[0] = nota1;
    aluno.nota[1] = nota2;
    return aluno;
}

void mostraMedia(aluno aluno) {
    printf("A media do aluno %s foi de: %.2f\n", aluno.nome, (aluno.nota[0] + aluno.nota[1]) / 2);
}
